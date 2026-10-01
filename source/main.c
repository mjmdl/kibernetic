#include <stdlib.h>

#include <GL/gl.h>

#include "common.h"
#include "window.h"

int main(void) {
    Platform_Window *window = window_create();
    if (window == NULL) {
        return EXIT_FAILURE;
    }

    const Platform_Input *input = window_input(window);

    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

    while (!window_should_close(window)) {
        window_poll_events(window);

        if (input_key_down(input, KEY_X)) {
            window_set_should_close(window, true);
        }

        if (input_key_pressed(input, KEY_SPACE)) {
            LOG_DEBUG("Space is pressed.");
        } else if (input_key_released(input, KEY_SPACE)) {
            LOG_DEBUG("Space is released.");
        }

        if (input_mouse_x_delta(input) != 0 || input_mouse_y_delta(input) != 0) {
            LOG_DEBUG("Mouse pos: %.2fx%.2f", input_mouse_x(input), input_mouse_y(input));
        }

        if (input_key_pressed(input, KEY_ESCAPE)) {
            window_set_cursor_locked(window, false);
        } else if (input_mouse_pressed(input, BUTTON_LEFT)) {
            window_set_cursor_locked(window, true);
        }

        glClear(GL_COLOR_BUFFER_BIT);

        window_swap_buffers(window);
    }

    window_destroy(window);
    return EXIT_SUCCESS;
}
