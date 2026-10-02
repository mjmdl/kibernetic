#include <stdlib.h>

#include <GL/gl.h>

#include "common.h"
#include "log.h"
#include "math.h"
#include "opengl.h"
#include "player.h"
#include "renderer.h"
#include "time.h"
#include "window.h"

static const float plane_vertices[] = {
    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,
     0.5f, -0.5f, 0.0f,  0.0f, 1.0f,
     0.5f,  0.5f, 0.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f,  1.0f, 0.0f,
};
static const unsigned int plane_indices[] = {
    0, 1, 2,
    0, 2, 3,
};
static const float cube_vertices[] = {
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
};
static const Vector3 cube_positions[] = {
    { 0.0f,  0.0f,  0.0f },
    { 2.0f,  5.0f, -15.0f},
    {-1.5f, -2.2f, -2.5f },
    {-3.8f, -2.0f, -12.3f},
    { 2.4f, -0.4f, -3.5f },
    {-1.7f,  3.0f, -7.5f },
    { 1.3f, -2.0f, -2.5f },
    { 1.5f,  2.0f, -2.5f },
    { 1.5f,  0.2f, -1.5f },
    {-1.3f,  1.0f, -1.5f },
};

static GLuint create_plane_mesh(GLint position_location, GLint texcoords_location) {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(plane_vertices), plane_vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(position_location);
    glVertexAttribPointer(position_location, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(plane_vertices[0]), (const void *)0);

    glEnableVertexAttribArray(texcoords_location);
    glVertexAttribPointer(texcoords_location, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(plane_vertices[0]), (const void *)(3 * sizeof(float)));

    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(plane_indices), plane_indices, GL_STATIC_DRAW);

    return vao;
}

static GLuint create_cube_mesh(GLint position_location, GLint texcoords_location) {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(position_location);
    glVertexAttribPointer(position_location, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(plane_vertices[0]), (const void *)0);

    glEnableVertexAttribArray(texcoords_location);
    glVertexAttribPointer(texcoords_location, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(plane_vertices[0]), (const void *)(3 * sizeof(float)));

    return vao;
}

static Vector3 process_movement_input(const Platform_Input *input) {
    Vector3 movement = {0};
    if (input_key_down(input, KEY_W)) {
        movement.x += 1.0f;
    }
    if (input_key_down(input, KEY_A)) {
        movement.z -= 1.0f;
    }
    if (input_key_down(input, KEY_S)) {
        movement.x -= 1.0f;
    }
    if (input_key_down(input, KEY_D)) {
        movement.z += 1.0f;
    }
    if (input_key_down(input, KEY_SPACE)) {
        movement.y += 1.0f;
    }
    if (input_key_down(input, KEY_LEFT_SHIFT)) {
        movement.y -= 1.0f;
    }
    return vector3_normalize(movement);
}

int main(void) {
    Platform_Window *window = window_create();
    if (window == NULL) {
        return EXIT_FAILURE;
    }

    const Platform_Input *input = window_input(window);

    Texture texture_crate = {0};
    texture_load_from_path("textures/crate.bmp", &texture_crate);

    Texture texture_casey = {0};
    texture_load_from_path("textures/casey.bmp", &texture_casey);

    const Shader_Source shader_paths[] = {
        {.data = "shaders/texture3d.vertex.glsl", .kind = SHADER_KIND_VERTEX},
        {.data = "shaders/texture3d.fragment.glsl", .kind = SHADER_KIND_FRAGMENT},
    };
    Shader shader = {0};
    shader_create_from_file_paths(shader_paths, 2, &shader);

    GLint position_location = glGetAttribLocation(shader.id, "v_position");
    GLint texcoords_location = glGetAttribLocation(shader.id, "v_texcoords");
    GLint model_location = glGetUniformLocation(shader.id, "model");
    GLint view_location = glGetUniformLocation(shader.id, "view");
    GLint projection_location = glGetUniformLocation(shader.id, "projection");

    GLuint plane_vao = create_plane_mesh(position_location, texcoords_location);
    GLuint cube_vao = create_cube_mesh(position_location, texcoords_location);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

    Player player = player_default();
    Camera camera = camera_default();

    Loop_Timer timer = {0};
    loop_timer_reset(&timer);

    window_set_vsync(window, false);

    while (!window_should_close(window)) {
        loop_timer_begin(&timer);
        window_poll_events(window);

        while (loop_timer_drain(&timer)) {
        }

        if (input_key_pressed(input, KEY_V)) {
            bool vsync = !window_vsync(window);
            window_set_vsync(window, vsync);

            LOG_DEBUG("V-sync %s", vsync ? "ON" : "OFF");
        }

        if (window_cursor_locked(window)) {
            if (input_key_pressed(input, KEY_ESCAPE)) {
                LOG_DEBUG("Cursor unlocked");
                window_set_cursor_locked(window, false);
            }
        } else {
            if (input_button_pressed(input, BUTTON_LEFT)) {
                LOG_DEBUG("Cursor locked");
                window_set_cursor_locked(window, true);
            }
        }

        Vector3 movement = process_movement_input(input);
        player_update(&player, camera.rotation.y, movement, timer.frame_seconds);

        camera.position = player.position;

        if (window_cursor_locked(window)) {
            camera_update(&camera, (Vector2){
                .x = input_mouse_x_delta(input),
                .y = input_mouse_y_delta(input),
            });
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Matrix4 plane_model = matrix4_identity();
        plane_model = matrix4_rotate_x(plane_model, radians(-90.0f));
        plane_model = matrix4_scale_xyz(plane_model, 100.0f, 1.0f, 100.0f);
        plane_model = matrix4_translate_xyz(plane_model, 0.0f, -20.0f, 0.0f);
        Matrix4 view = camera_view_matrix(&camera, player.up);

        int width = 0;
        int height = 0;
        window_dimensions(window, &width, &height);
        Matrix4 projection = matrix4_perspective(radians(120.0f), height != 0 ? ((float)width / (float)height) : 0, 0.1f, 1000.0f);

        glUseProgram(shader.id);
        glUniformMatrix4fv(view_location, 1, GL_FALSE, (float *)&view);
        glUniformMatrix4fv(projection_location, 1, GL_FALSE, (float *)&projection);

        glUniformMatrix4fv(model_location, 1, GL_FALSE, (float *)&plane_model);
        glBindVertexArray(plane_vao);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_casey.id);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

        glBindVertexArray(cube_vao);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_crate.id);
        float now = (float)wallclock_seconds();
        for (size_t i = 0; i < ARRAY_LENGTH(cube_positions); ++i) {
            Matrix4 model = matrix4_identity();
            model = matrix4_rotate_xyz(model, radians(now * ((i * i * i) + 1)), 1.0f, 0.3f, 0.5f);
            model = matrix4_translate(model, cube_positions[i]);
            model = matrix4_rotate_xyz(model, radians(now * ((i * i) + 1)), 1.0f, 0.3f, 0.5f);
            glUniformMatrix4fv(model_location, 1, GL_FALSE, (float *)&model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        window_swap_buffers(window);
        loop_timer_end(&timer);
    }

    window_destroy(window);
    return EXIT_SUCCESS;
}
