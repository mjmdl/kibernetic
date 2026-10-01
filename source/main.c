#include <stdlib.h>

#include <GL/gl.h>

#include "common.h"
#include "opengl.h"
#include "renderer.h"
#include "window.h"

int main(void) {
    Platform_Window *window = window_create();
    if (window == NULL) {
        return EXIT_FAILURE;
    }

    const Platform_Input *input = window_input(window);

    const float triangle_vertices[] = {
        -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 1.0f,
    };
    const char *vertex_glsl =
        "#version 460 core\n"
        "layout (location = 1) in vec2 v_position;"
        "layout (location = 2) in vec3 v_color;"
        "out vec3 f_color;"
        "void main() {"
        "    gl_Position = vec4(v_position.xy, 0.0, 1.0);"
        "    f_color = v_color;"
        "}";
    const char *fragment_glsl =
        "#version 460 core\n"
        "in vec3 f_color;"
        "out vec4 fragment;"
        "void main() {"
        "    fragment = vec4(f_color.xyz, 1.0);"
        "}";

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);

    const Shader_Source shader_sources[] = {
        {.data = vertex_glsl, .kind = SHADER_KIND_VERTEX},
        {.data = fragment_glsl, .kind = SHADER_KIND_FRAGMENT},
    };
    Shader shader = {0};
    shader_create_from_sources(shader_sources, ARRAY_LENGTH(shader_sources), &shader);

    GLint position_location = glGetAttribLocation(shader.id, "v_position");
    glEnableVertexAttribArray(position_location);
    glVertexAttribPointer(position_location, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void *)0);
    GLint color_location = glGetAttribLocation(shader.id, "v_color");
    glEnableVertexAttribArray(color_location);
    glVertexAttribPointer(color_location, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void *)(2 * sizeof (float)));

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

        glBindVertexArray(vao);
        glUseProgram(shader.id);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window_swap_buffers(window);
    }

    window_destroy(window);
    return EXIT_SUCCESS;
}
