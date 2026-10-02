#ifndef PLAYER_H
#define PLAYER_H

#include "math.h"

typedef struct Camera {
    Vector3 position;
    Vector3 rotation;
    float sensitivity;
    float axis_z_clamp;
} Camera;

Camera camera_default(void);

void camera_update(Camera *camera, Vector2 mouse_movement);

Vector3 camera_forward(const Camera *camera);

Matrix4 camera_view_matrix(const Camera *camera, Vector3 up);

typedef struct Player {
    Vector3 position;
    Vector3 up;
    float movement_speed;
} Player;

Player player_default(void);

void player_update(Player *player, float rotation_y, Vector3 movement, float frame_seconds);

#endif // PLAYER_H
