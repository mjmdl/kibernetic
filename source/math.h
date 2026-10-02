#ifndef MATH_H
#define MATH_H

#define _GNU_SOURCE

#include <float.h>
#include <math.h>

typedef struct Vector2 {
    float x, y;
} Vector2;

typedef struct Vector3 {
    float x, y, z;
} Vector3;

typedef struct Vector4 {
    float x, y, z, w;
} Vector4;

typedef struct Matrix4 {
    float m00, m10, m20, m30;
    float m01, m11, m21, m31;
    float m02, m12, m22, m32;
    float m03, m13, m23, m33;
} Matrix4;

float radians(float degrees);

Vector3 vector3_add(Vector3 left, Vector3 right);

Vector3 vector3_subtract(Vector3 left, Vector3 right);

Vector3 vector3_multiply_scalar(Vector3 vector, float scalar);

float vector3_dot(Vector3 left, Vector3 right);

Vector3 vector3_cross(Vector3 left, Vector3 right);

float vector3_length(Vector3 vector);

Vector3 vector3_scale(Vector3 vector, float scalar);

Vector3 vector3_normalize(Vector3 vector);

Matrix4 matrix4_identity(void);

Matrix4 matrix4_multiply(Matrix4 left, Matrix4 right);

Vector4 matrix4_multiply_vector4(Matrix4 matrix, Vector4 vector);

Matrix4 matrix4_translation(Vector3 vector);

Matrix4 matrix4_scaling(Vector3 vector);

Matrix4 matrix4_rotation(float angle, Vector3 axis);

Matrix4 matrix4_rotation_x(float angle);

Matrix4 matrix4_rotation_y(float angle);

Matrix4 matrix4_rotation_z(float angle);

Matrix4 matrix4_perspective(float fov, float aspect, float near_plane, float far_plane);

Matrix4 matrix4_look_at(Vector3 from, Vector3 to, Vector3 up);

Matrix4 matrix4_translate(Matrix4 matrix, Vector3 vector);

Matrix4 matrix4_scale(Matrix4 matrix, Vector3 vector);

Matrix4 matrix4_rotate(Matrix4 matrix, float angle, Vector3 axis);

Matrix4 matrix4_rotate_x(Matrix4 matrix, float angle);

Matrix4 matrix4_rotate_y(Matrix4 matrix, float angle);

Matrix4 matrix4_rotate_z(Matrix4 matrix, float angle);

#define matrix4_translate_xyz(matrix, x, y, z) \
    matrix4_translate(matrix, (Vector3){x, y, z})

#define matrix4_scale_xyz(matrix, x, y, z) \
    matrix4_scale(matrix, (Vector3){x, y, z})

#define matrix4_rotate_xyz(matrix, angle, x, y, z) \
    matrix4_rotate(matrix, angle, (Vector3){x, y, z})

#endif // MATH_H
