#include "player.h"

Camera camera_default(void)
{
    return (Camera){
        .position = {0},
        .rotation = {.y = radians(90.0f)},
        .sensitivity = 0.001f,
        .axis_z_clamp = radians(89.99f)};
}

void camera_update(Camera *camera, Vector2 mouse_movement)
{
    camera->rotation.y += mouse_movement.x * camera->sensitivity;
    camera->rotation.z += mouse_movement.y * camera->sensitivity;

    if (camera->rotation.z > camera->axis_z_clamp) {
        camera->rotation.z = camera->axis_z_clamp;
    } else if (camera->rotation.z < -camera->axis_z_clamp) {
        camera->rotation.z = -camera->axis_z_clamp;
    }
}

Vector3 camera_forward(const Camera *camera)
{
    return (Vector3){
        .x = cosf(camera->rotation.y) * cosf(camera->rotation.z),
        .y = sinf(camera->rotation.z),
        .z = sinf(camera->rotation.y) * cosf(camera->rotation.z)};
}

Matrix4 camera_view_matrix(const Camera *camera, Vector3 up)
{
    Vector3 forward = {
        .x = cosf(camera->rotation.y) * cosf(camera->rotation.z),
        .y = sinf(camera->rotation.z),
        .z = sinf(camera->rotation.y) * cosf(camera->rotation.z)};
    Vector3 target = vector3_add(camera->position, forward);

    return matrix4_look_at(camera->position, target, up);
}

Player player_default(void)
{
    return (Player){
        .position = {0},
        .up = {.y = 1.0f},
        .movement_speed = 2.0f};
}

void player_update(Player *player, float rotation_y, Vector3 movement, float frame_seconds)
{
    Vector3 forward = {.x = cosf(rotation_y), .y = 0.0f, .z = sinf(rotation_y)};
    Vector3 right = {.x = -forward.z, .y = 0.0f, .z = forward.x};

    float speed = frame_seconds * player->movement_speed;
    Vector3 velocity = vector3_add(
        vector3_multiply_scalar(player->up, movement.y * speed),
        vector3_add(
            vector3_multiply_scalar(right, movement.z * speed),
            vector3_multiply_scalar(forward, movement.x * speed)));

    player->position = vector3_add(player->position, velocity);
}
