#include <stddef.h>
#include <stdlib.h>

#include <X11/extensions/Xinerama.h>

#include "common.h"
#include "string.h"
#include "window_linux.h"

enum {
    WINDOW_TITLE_MAX_LENGTH = 64,
};

static Platform_Window g_window;
static char g_window_title[WINDOW_TITLE_MAX_LENGTH];

static int handle_xlib_error_event(Display *display, XErrorEvent *event) {
    char log[256];
    XGetErrorText(display, event->error_code, log, sizeof(log));

    LOG_ERROR("X11: %.*s (error #%d, request #%d, minor #%d).", (int)sizeof(log), log, event->error_code, event->request_code, event->minor_code);

    return 0;
}

static bool check_glx_version(Display *display) {
    int major = 0;
    int minor = 0;
    if (!glXQueryVersion(display, &major, &minor)) {
        LOG_ERROR("Failed to query the GLX version.");
        return false;
    }

    LOG_DEBUG("Current GLX version: %d.%d.", major, minor);

    const int minimum_major = 1;
    const int minimum_minor = 3;
    if (major < minimum_major || (major == minimum_major && minor < minimum_minor)) {
        LOG_ERROR("GLX version %d.%d or greater is required.", minimum_major, minimum_minor);
        return false;
    }

    return true;
}

#define FOREACH_GLX_EXTENSION(X) \
    /* X(NAME, REQUIRED) */ \
    X(GLX_ARB_get_proc_address, true) \
    X(GLX_ARB_create_context_profile, true) \
    X(GLX_EXT_swap_buffers, false)

#define DECLARE_VARIABLE(NAME, REQUIRED) \
    static bool support_##NAME;
FOREACH_GLX_EXTENSION(DECLARE_VARIABLE)
#undef DECLARE_VARIABLE

static bool check_glx_extensions(Display *display, int screen_number) {
    const char *extensions = glXQueryExtensionsString(display, screen_number);
    if (extensions == NULL || *extensions == '\0') {
        LOG_ERROR("Failed to query the GLX extensions string.");
        return false;
    }

    LOG_DEBUG("Supported GLX extensions: %s.", extensions);

    const char *position = extensions;
    const char *current_extension = extensions;

    while (true) {
        bool separator = *position == ' ';
        bool terminator = *position == '\0';

        if (separator || terminator) {
            int length = position - current_extension;

            #define COMPARE_EXTENSION(NAME, REQUIRED) \
                else if (!support_##NAME && cstring_equal_no_case(#NAME, current_extension, length)) { \
                    support_##NAME = true; \
                }
            if (false) {
            }
            FOREACH_GLX_EXTENSION(COMPARE_EXTENSION)
            #undef COMPARE_EXTENSION

            current_extension = position + 1;
        }

        if (terminator) {
            break;
        }

        ++position;
    }

    bool supported = true;

    #define CHECK_SUPPORT(NAME, REQUIRED) \
        if (!support_##NAME) { \
            LOG_ERROR("%s GLX extension " #NAME " is not supported.", REQUIRED ? "Required" : "Optional"); \
            if (REQUIRED) { \
                supported = false; \
            } \
        }
    FOREACH_GLX_EXTENSION(CHECK_SUPPORT)
    #undef CHECK_SUPPORT

    return supported;
}

#undef FOREACH_GLX_EXTENSION

static bool check_glx(Display *display, int screen_number) {
    bool version_supported = check_glx_version(display);
    bool extensions_supported = check_glx_extensions(display, screen_number);
    return version_supported && extensions_supported;
}

static bool query_xinerama_screen_dimensions(Display *display, int screen_number, int *out_width, int *out_height) {
    if (!XineramaIsActive(display)) {
        return false;
    }

    int screens_count = 0;
    XineramaScreenInfo *screens = XineramaQueryScreens(display, &screens_count);
    if (screens == NULL || screens_count <= 0) {
        return false;
    }

    for (int i = 0; i < screens_count; ++i) {
        XineramaScreenInfo *screen = &screens[i];
        if (screen->screen_number == screen_number) {
            *out_width = screen->width;
            *out_height = screen->height;
            XFree(screens);
            return true;
        }
    }

    XFree(screens);
    return false;
}

static void query_xlib_screen_dimensions(Display *display, int screen_number, int *out_width, int *out_height) {
    Screen *screen = ScreenOfDisplay(display, screen_number);
    *out_width = WidthOfScreen(screen);
    *out_height = HeightOfScreen(screen);
}

static void query_screen_dimensions(Display *display, int screen_number, int *out_width, int *out_height) {
    if (query_xinerama_screen_dimensions(display, screen_number, out_width, out_height)) {
        return;
    }

    query_xlib_screen_dimensions(display, screen_number, out_width, out_height);
}

static bool choose_glx_fb_config(Display *display, int screen_number, GLXFBConfig *out_fb_config, XVisualInfo *out_visual_info) {
    #define ATTRIB(KEY, VALUE) \
        (KEY), (VALUE)
    const int attribs[] = {
        ATTRIB(GLX_FBCONFIG_ID, GLX_DONT_CARE),
        ATTRIB(GLX_BUFFER_SIZE, 0),
        ATTRIB(GLX_LEVEL, 0),
        ATTRIB(GLX_DOUBLEBUFFER, True),
        ATTRIB(GLX_STEREO, False),
        ATTRIB(GLX_AUX_BUFFERS, 0),
        ATTRIB(GLX_RED_SIZE, 8),
        ATTRIB(GLX_GREEN_SIZE, 8),
        ATTRIB(GLX_BLUE_SIZE, 8),
        ATTRIB(GLX_ALPHA_SIZE, 8),
        ATTRIB(GLX_DEPTH_SIZE, 16),
        ATTRIB(GLX_STENCIL_SIZE, 8),
        ATTRIB(GLX_ACCUM_RED_SIZE, 0),
        ATTRIB(GLX_ACCUM_GREEN_SIZE, 0),
        ATTRIB(GLX_ACCUM_BLUE_SIZE, 0),
        ATTRIB(GLX_ACCUM_ALPHA_SIZE, 0),
        ATTRIB(GLX_RENDER_TYPE, GLX_RGBA_BIT),
        ATTRIB(GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT),
        ATTRIB(GLX_X_RENDERABLE, True),
        ATTRIB(GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR),
        ATTRIB(GLX_CONFIG_CAVEAT, GLX_NONE),
        ATTRIB(GLX_TRANSPARENT_TYPE, GLX_DONT_CARE),
        ATTRIB(GLX_TRANSPARENT_INDEX_VALUE, GLX_DONT_CARE),
        ATTRIB(GLX_TRANSPARENT_RED_VALUE, GLX_DONT_CARE),
        ATTRIB(GLX_TRANSPARENT_GREEN_VALUE, GLX_DONT_CARE),
        ATTRIB(GLX_TRANSPARENT_BLUE_VALUE, GLX_DONT_CARE),
        ATTRIB(GLX_TRANSPARENT_ALPHA_VALUE, GLX_DONT_CARE),
        None,
    };
    #undef ATTRIB

    int fb_configs_count = 0;
    GLXFBConfig *fb_configs = glXChooseFBConfig(display, screen_number, attribs, &fb_configs_count);
    if (fb_configs == NULL || fb_configs_count <= 0) {
        LOG_ERROR("Failed to query any GLX framebuffer configurations.");
        return false;
    }

    LOG_DEBUG("Number of available GLX framebuffer configurations: %d.", fb_configs_count);

    int best_samples = 0;
    int best_sample_buffers = 0;
    GLXFBConfig best_fb_config = NULL;
    XVisualInfo *best_visual_info = NULL;

    for (int i = 0; i < fb_configs_count; ++i) {
        GLXFBConfig fb_config = fb_configs[i];

        XVisualInfo *visual_info = glXGetVisualFromFBConfig(display, fb_config);
        if (visual_info == NULL) {
            continue;
        }

        int samples = 0;
        int sample_buffers = 0;
        if (
            glXGetFBConfigAttrib(display, fb_config, GLX_SAMPLES, &samples) != 0 ||
            glXGetFBConfigAttrib(display, fb_config, GLX_SAMPLE_BUFFERS, &sample_buffers) != 0 ||
            (samples <= best_samples || sample_buffers <= 0)
        ) {
            XFree(visual_info);
            continue;
        }

        best_samples = samples;
        best_sample_buffers = sample_buffers;
        best_fb_config = fb_config;

        if (best_visual_info != NULL) {
            XFree(best_visual_info);
        }
        best_visual_info = visual_info;
    }

    XFree(fb_configs);

    if (best_fb_config == NULL) {
        LOG_ERROR("Could not find a good enough GLX framebuffer configuration.");
        return false;
    }

    LOG_DEBUG("GLX framebuffer configuration has %d samples and %d sample buffers.", best_samples, best_sample_buffers);

    *out_fb_config = best_fb_config;
    *out_visual_info = *best_visual_info;
    XFree(best_visual_info);
    return true;
}

static bool create_glx_context(Display *display, GLXFBConfig fb_config, Window window, GLXContext *out_context) {
    typedef GLXContext(*Glx_Create_Context_Attribs_Arb_Proc)(Display *display, GLXFBConfig fb_config, GLXContext context, Bool direct, const int *attribs);

    #define ATTRIB(KEY, VALUE) \
        (KEY), (VALUE)
    const int attribs[] = {
        ATTRIB(GLX_CONTEXT_MAJOR_VERSION_ARB, 4),
        ATTRIB(GLX_CONTEXT_MINOR_VERSION_ARB, 6),
        ATTRIB(GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_DEBUG_BIT_ARB | GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB),
        ATTRIB(GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB),
        None,
    };
    #undef ATTRIB

    Glx_Create_Context_Attribs_Arb_Proc glXCreateContextAttribsARB = (Glx_Create_Context_Attribs_Arb_Proc)glXGetProcAddressARB((const GLubyte *)"glXCreateContextAttribsARB");
    if (glXCreateContextAttribsARB == NULL) {
        LOG_ERROR("Failed to retrieve the GLX context function.");
        return false;
    }

    GLXContext context = glXCreateContextAttribsARB(display, fb_config, NULL, True, attribs);
    if (context == NULL) {
        LOG_ERROR("Failed to create the GLX context.");
        return false;
    }

    if (!glXMakeCurrent(display, window, context)) {
        LOG_ERROR("Failed to make the GLX context current.");
        glXDestroyContext(display, context);
        return false;
    }

    *out_context = context;
    return true;
}

static void setup_xlib_window_manager_protocols(Display *display, Window window, Atom *out_close_message) {
    Atom messages[1] = {0};
    messages[0] = XInternAtom(display, "WM_DELETE_WINDOW", False);

    if (!XSetWMProtocols(display, window, messages, ARRAY_LENGTH(messages))) {
        LOG_ERROR("Failed to set the X11 window manager protocols.");
        return;
    }

    *out_close_message = messages[0];
}

static Cursor create_xlib_hidden_cursor(Display *display, Window window) {
    Pixmap pixmap = XCreateBitmapFromData(display, window, "\0", 1, 1);
    XColor color = {0};
    return XCreatePixmapCursor(display, pixmap, pixmap, &color, &color, 0, 0);
}

static void check_windowing_system(void) {
    const char *protocol_name = getenv("XDG_SESSION_TYPE");
    if (protocol_name != NULL && cstring_equal_no_case(protocol_name, "wayland", sizeof("wayland")) == 0) {
        LOG_WARN("Wayland detected. Some windowing features might not work.");
    }
}

Platform_Window *window_create(void) {
    check_windowing_system();

    XSetErrorHandler(handle_xlib_error_event);

    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        LOG_ERROR("Failed to open the X11 display.");
        return NULL;
    }

    int screen_number = DefaultScreen(display);
    Window root_window = RootWindow(display, screen_number);

    if (!check_glx(display, screen_number)) {
        XCloseDisplay(display);
        return NULL;
    }

    GLXFBConfig fb_config = NULL;
    XVisualInfo visual_info = {0};
    if (!choose_glx_fb_config(display, screen_number, &fb_config, &visual_info)) {
        XCloseDisplay(display);
        return NULL;
    }

    XSetWindowAttributes attribs = {0};
    attribs.border_pixel = BlackPixel(display, screen_number);
    attribs.colormap = XCreateColormap(display, root_window, visual_info.visual, AllocNone);
    attribs.event_mask = StructureNotifyMask;
    long attribs_mask = CWBorderPixel | CWColormap | CWEventMask;

    if (attribs.colormap == 0) {
        LOG_ERROR("Failed to create the X11 colormap.");
        XCloseDisplay(display);
        return NULL;
    }

    int x = 100;
    int y = 100;
    int width = 800;
    int height = 600;
    int border_width = 0;
    int class = InputOutput;

    Window window = XCreateWindow(display, root_window, x, y, width, height, border_width, visual_info.depth, class, visual_info.visual, attribs_mask, &attribs);
    if (window == 0) {
        LOG_ERROR("Failed to create the X11 window.");
        XCloseDisplay(display);
        return NULL;
    }

    GLXContext context = NULL;
    if (!create_glx_context(display, fb_config, window, &context)) {
        XCloseDisplay(display);
        return NULL;
    }

    Atom close_message;
    setup_xlib_window_manager_protocols(display, window, &close_message);

    int screen_width = 0;
    int screen_height = 0;
    query_screen_dimensions(display, screen_number, &screen_width, &screen_height);
    
    width = (int)(screen_width * 2.0f / 3.0f);
    height = (int)(screen_height * 2.0f / 3.0f);
    XResizeWindow(display, window, width, height);

    x = (int)((screen_width - width) / 2.0f);
    y = (int)((screen_height - height) / 2.0f);
    XMoveWindow(display, window, x, y);

    const char *default_title = "A Window";
    cstring_copy(default_title, g_window_title, LEAST(cstring_length(default_title) + 1, WINDOW_TITLE_MAX_LENGTH - 1));
    XStoreName(display, window, g_window_title);

    XMapWindow(display, window);

    Cursor cursor_hidden = create_xlib_hidden_cursor(display, window);

    if (g_window.initialized) {
        window_destroy(&g_window);
    }

    g_window = (Platform_Window){
        .initialized = true,
        .should_close = false,
        .cursor_locked = false,
        .ignore_next_motion_event = false,
        .width = width,
        .height = height,

        .display = display,
        .context = context,
        .screen_number = screen_number,
        .root_window = root_window,
        .window = window,
        .close_message = close_message,
        .cursor_hidden = cursor_hidden,
    };
    return &g_window;
}

void window_destroy(Platform_Window *window) {
    glXDestroyContext(window->display, window->context);
    XCloseDisplay(window->display);

    window->initialized = false;
}

static void dispatch_client_message_event(Platform_Window *window, const XClientMessageEvent *event) {
    Atom client_message = (Atom)event->data.l[0];

    if (client_message == window->close_message) {
        window->should_close = true;
    }
}

static void dispatch_configure_event(Platform_Window *window, const XConfigureEvent *event) {
    window->width = event->width;
    window->height = event->height;

    glViewport(0, 0, event->width, event->height);
}

static void dispatch_motion_event(Platform_Window *window, const XMotionEvent *event) {
    (void)event;

    if (window->ignore_next_motion_event) {
        window->ignore_next_motion_event = false;
        return;
    }

    float center_x = window->width / 2.0f;
    float center_y = window->height / 2.0f;

    if (window->cursor_locked) {
        XWarpPointer(window->display, None, window->window, 0, 0, 0, 0, center_x, center_y);
        window->ignore_next_motion_event = true;
    }
}

static Bool check_if_xlib_window_event(Display *display, XEvent *event, XPointer argument) {
    (void)display;

    Platform_Window *window = (Platform_Window *)argument;

    return window->display == event->xany.display && window->window == event->xany.window;
}

void window_poll_events(Platform_Window *window) {
    XEvent event = {0};
    while (XCheckIfEvent(window->display, &event, check_if_xlib_window_event, (XPointer)window)) {
        switch (event.type) {
        case ClientMessage:
            dispatch_client_message_event(window, &event.xclient);
            break;

        case ConfigureNotify:
            dispatch_configure_event(window, &event.xconfigure);
            break;

        case MotionNotify:
            dispatch_motion_event(window, &event.xmotion);
            break;
        }
    }
}

void window_swap_buffers(Platform_Window *window) {
    glXSwapBuffers(window->display, window->window);
}

bool window_should_close(const Platform_Window *window) {
    return window->should_close;
}

void window_position(const Platform_Window *window, int *out_x, int *out_y) {
    XTranslateCoordinates(window->display, window->window, window->root_window, 0, 0, out_x, out_y, None);
}

void window_set_position(Platform_Window *window, int x, int y) {
    XMoveWindow(window->display, window->window, x, y);
}

void window_move_to_center(Platform_Window *window) {
    int screen_width = 0;
    int screen_height = 0;
    query_screen_dimensions(window->display, window->screen_number, &screen_width, &screen_height);

    int x = (int)((screen_width - window->width) / 2.0f);
    int y = (int)((screen_height - window->height) / 2.0f);
    XMoveWindow(window->display, window->window, x, y);
}

void window_dimensions(const Platform_Window *window, int *out_width, int *out_height) {
    *out_width = window->width;
    *out_height = window->height;
}

void window_set_dimensions(Platform_Window *window, int width, int height) {
    XResizeWindow(window->display, window->window, width, height);

    window->width = width;
    window->height = height;
}

void window_screen_dimensions(const Platform_Window *window, int *out_width, int *out_height) {
    query_screen_dimensions(window->display, window->screen_number, out_width, out_height);
}

const char *window_title(const Platform_Window *window) {
    (void)window;

    return g_window_title;
}

void window_set_title(Platform_Window *window, const char *title) {
    if (title == NULL) {
        title = "";
    }

    cstring_copy(title, g_window_title, cstring_length(title));

    XStoreName(window->display, window->window, g_window_title);
}

bool window_cursor_locked(const Platform_Window *window) {
    return window->cursor_locked;
}

void window_set_cursor_locked(Platform_Window *window, bool cursor_locked) {
    if (cursor_locked) {
        XDefineCursor(window->display, window->window, window->cursor_hidden);

        long grab_mask = ButtonPressMask | ButtonReleaseMask | PointerMotionMask;
        XGrabPointer(window->display, window->window, True, grab_mask, GrabModeAsync, GrabModeAsync, window->window, window->cursor_hidden, CurrentTime);
    } else {
        XUngrabPointer(window->display, CurrentTime);

        XUndefineCursor(window->display, window->window);
    }

    window->cursor_locked = cursor_locked;
}
