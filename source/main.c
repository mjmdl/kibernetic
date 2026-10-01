#include <stdlib.h>

#include <GL/gl.h>

#include "window.h"

int main(void) {
    Platform_Window *window = window_create();
    if (window == NULL) {
        return EXIT_FAILURE;
    }

    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

    while (!window_should_close(window)) {
        window_poll_events(window);

        glClear(GL_COLOR_BUFFER_BIT);

        window_swap_buffers(window);
    }

    window_destroy(window);
    return EXIT_SUCCESS;
}
