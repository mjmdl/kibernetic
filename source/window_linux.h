#ifndef WINDOW_LINUX_H
#define WINDOW_LINUX_H

#include <GL/glx.h>
#include <X11/Xlib.h>

#include "window.h"

struct Platform_Window {
    bool initialized;
    bool should_close;
    bool cursor_locked;
    bool ignore_next_motion_event;
    int width;
    int height;

    Display *display;
    GLXContext context;
    int screen_number;
    Window root_window;
    Window window;
    Atom close_message;
    Cursor cursor_hidden;
};

#endif // WINDOW_LINUX_H
