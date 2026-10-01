#include <stdlib.h>

#include <GL/gl.h>

#include "common.h"
#include "log.h"
#include "opengl.h"
#include "renderer.h"
#include "time.h"
#include "window.h"

int main(void) {
    Platform_Window *window = window_create();
    if (window == NULL) {
        return EXIT_FAILURE;
    }

    const Platform_Input *input = window_input(window);

    const float triangle_vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 0.0f,
    };

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);

    const Shader_Source shader_paths[] = {
        {.data = "shaders/texture.vertex.glsl", .kind = SHADER_KIND_VERTEX},
        {.data = "shaders/texture.fragment.glsl", .kind = SHADER_KIND_FRAGMENT},
    };
    Shader shader = {0};
    shader_create_from_file_paths(shader_paths, ARRAY_LENGTH(shader_paths), &shader);

    GLint position_location = glGetAttribLocation(shader.id, "v_position");
    glEnableVertexAttribArray(position_location);
    glVertexAttribPointer(position_location, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (const void *)0);
    GLint texcoord_location = glGetAttribLocation(shader.id, "v_texcoord");
    glEnableVertexAttribArray(texcoord_location);
    glVertexAttribPointer(texcoord_location, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (const void *)(2 * sizeof (float)));

    Texture texture = {0};
    texture_load_from_path("textures/casey.bmp", &texture);

    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

    Loop_Timer timer = {0};
    loop_timer_reset(&timer);
    window_set_vsync(window, false);

    while (!window_should_close(window)) {
        loop_timer_begin(&timer);
        window_poll_events(window);

        while (loop_timer_drain(&timer)) {
        }

        if (input_key_down(input, KEY_X)) {
            window_set_should_close(window, true);
        }

        if (input_key_pressed(input, KEY_SPACE)) {
            LOG_DEBUG("Space is pressed.");
        } else if (input_key_released(input, KEY_SPACE)) {
            LOG_DEBUG("Space is released.");
        } else if (input_key_down(input, KEY_SPACE)) {
            LOG_DEBUG("Mouse pos: %.2fx%.2f", input_mouse_x(input), input_mouse_y(input));
        }

        if (input_key_pressed(input, KEY_ESCAPE)) {
            window_set_cursor_locked(window, false);
        } else if (input_mouse_pressed(input, BUTTON_LEFT)) {
            window_set_cursor_locked(window, true);
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao);
        glUseProgram(shader.id);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture.id);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        window_swap_buffers(window);
        loop_timer_end(&timer);
    }

    window_destroy(window);
    return EXIT_SUCCESS;
}
