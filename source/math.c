#include "math.h"

float radians(float degrees) {
    return degrees * (M_PI / 180.0f);
}

Vector3 vector3_add(Vector3 left, Vector3 right) {
    return (Vector3){left.x + right.x, left.y + right.y, left.z + right.z};
}

Vector3 vector3_subtract(Vector3 left, Vector3 right) {
    return (Vector3){left.x - right.x, left.y - right.y, left.z - right.z};
}

Vector3 vector3_multiply_scalar(Vector3 vector, float scalar) {
    return (Vector3){
        .x = vector.x * scalar,
        .y = vector.y * scalar,
        .z = vector.z * scalar,
    };
}

float vector3_dot(Vector3 left, Vector3 right) {
    return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
}

Vector3 vector3_cross(Vector3 left, Vector3 right) {
    return (Vector3){
        (left.y * right.z) - (left.z * right.y),
        (left.z * right.x) - (left.x * right.z),
        (left.x * right.y) - (left.y * right.x),
    };
}

float vector3_length(Vector3 vector) {
    return sqrtf(vector3_dot(vector, vector));
}

Vector3 vector3_scale(Vector3 vector, float scalar) {
    return (Vector3){vector.x * scalar, vector.y * scalar, vector.z * scalar};
}

Vector3 vector3_normalize(Vector3 vector) {
    float length = vector3_length(vector);
    if (length <= FLT_EPSILON) {
        return (Vector3){0};
    }
    return vector3_scale(vector, 1.0f / length);
}

Matrix4 matrix4_identity(void) {
    return (Matrix4){
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}

Matrix4 matrix4_multiply(Matrix4 left, Matrix4 right) {
    return (Matrix4){
        .m00 = (left.m00 * right.m00) + (left.m10 * right.m01) + (left.m20 * right.m02) + (left.m30 * right.m03),
        .m10 = (left.m00 * right.m10) + (left.m10 * right.m11) + (left.m20 * right.m12) + (left.m30 * right.m13),
        .m20 = (left.m00 * right.m20) + (left.m10 * right.m21) + (left.m20 * right.m22) + (left.m30 * right.m23),
        .m30 = (left.m00 * right.m30) + (left.m10 * right.m31) + (left.m20 * right.m32) + (left.m30 * right.m33),
        .m01 = (left.m01 * right.m00) + (left.m11 * right.m01) + (left.m21 * right.m02) + (left.m31 * right.m03),
        .m11 = (left.m01 * right.m10) + (left.m11 * right.m11) + (left.m21 * right.m12) + (left.m31 * right.m13),
        .m21 = (left.m01 * right.m20) + (left.m11 * right.m21) + (left.m21 * right.m22) + (left.m31 * right.m23),
        .m31 = (left.m01 * right.m30) + (left.m11 * right.m31) + (left.m21 * right.m32) + (left.m31 * right.m33),
        .m02 = (left.m02 * right.m00) + (left.m12 * right.m01) + (left.m22 * right.m02) + (left.m32 * right.m03),
        .m12 = (left.m02 * right.m10) + (left.m12 * right.m11) + (left.m22 * right.m12) + (left.m32 * right.m13),
        .m22 = (left.m02 * right.m20) + (left.m12 * right.m21) + (left.m22 * right.m22) + (left.m32 * right.m23),
        .m32 = (left.m02 * right.m30) + (left.m12 * right.m31) + (left.m22 * right.m32) + (left.m32 * right.m33),
        .m03 = (left.m03 * right.m00) + (left.m13 * right.m01) + (left.m23 * right.m02) + (left.m33 * right.m03),
        .m13 = (left.m03 * right.m10) + (left.m13 * right.m11) + (left.m23 * right.m12) + (left.m33 * right.m13),
        .m23 = (left.m03 * right.m20) + (left.m13 * right.m21) + (left.m23 * right.m22) + (left.m33 * right.m23),
        .m33 = (left.m03 * right.m30) + (left.m13 * right.m31) + (left.m23 * right.m32) + (left.m33 * right.m33),
    };
}

Vector4 matrix4_multiply_vector4(Matrix4 matrix, Vector4 vector) {
    return (Vector4){
        (matrix.m00 * vector.x) + (matrix.m10 * vector.y) + (matrix.m20 * vector.z) + (matrix.m30 * vector.w),
        (matrix.m01 * vector.x) + (matrix.m11 * vector.y) + (matrix.m21 * vector.z) + (matrix.m31 * vector.w),
        (matrix.m02 * vector.x) + (matrix.m12 * vector.y) + (matrix.m22 * vector.z) + (matrix.m32 * vector.w),
        (matrix.m03 * vector.x) + (matrix.m13 * vector.y) + (matrix.m23 * vector.z) + (matrix.m33 * vector.w),
    };
}

Matrix4 matrix4_translation(Vector3 vector) {
    Matrix4 result = matrix4_identity();
    result.m03 = vector.x;
    result.m13 = vector.y;
    result.m23 = vector.z;
    return result;
}

Matrix4 matrix4_scaling(Vector3 vector) {
    return (Matrix4){
        .m00 = vector.x,
        .m11 = vector.y,
        .m22 = vector.z,
        .m33 = 1.0f,
    };
}

Matrix4 matrix4_rotation(float angle, Vector3 axis) {
    float c = cosf(angle);
    float s = sinf(angle);
    float t = 1.0f - c;
    axis = vector3_normalize(axis);
    return (Matrix4){
        .m00 = (t * axis.x * axis.x) + c,
        .m10 = (t * axis.x * axis.y) - (s * axis.z),
        .m20 = (t * axis.x * axis.z) + (s * axis.y),
        .m30 = 0.0f,
        .m01 = (t * axis.x * axis.y) + (s * axis.z),
        .m11 = (t * axis.y * axis.y) + c,
        .m21 = (t * axis.y * axis.z) - (s * axis.x),
        .m31 = 0.0f,
        .m02 = (t * axis.x * axis.z) - (s * axis.y),
        .m12 = (t * axis.y * axis.z) + (s * axis.x),
        .m22 = (t * axis.z * axis.z) + c,
        .m32 = 0.0f,
        .m03 = 0.0f,
        .m13 = 0.0f,
        .m23 = 0.0f,
        .m33 = 1.0f,
    };
}

Matrix4 matrix4_rotation_x(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    return (Matrix4){
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, c,     s,   0.0f,
        0.0f, -s,    c,   0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}

Matrix4 matrix4_rotation_y(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    return (Matrix4){
         c,   0.0f, s,    0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -s,   0.0f, c,    0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}

Matrix4 matrix4_rotation_z(float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    return (Matrix4){
        c,    -s,   0.0f, 0.0f,
        s,     c,   0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}

Matrix4 matrix4_perspective(float fov, float aspect, float near_plane, float far_plane) {
    float f = 1.0f / tanf(fov * 0.5f);
    return (Matrix4){
        .m00 = f / aspect,
        .m11 = f,
        .m22 = (far_plane + near_plane) / (near_plane - far_plane),
        .m23 = (2.0f * far_plane * near_plane) / (near_plane - far_plane),
        .m32 = -1.0f,
    };
}

Matrix4 matrix4_look_at(Vector3 from, Vector3 to, Vector3 up) {
    Vector3 f = vector3_normalize(vector3_subtract(to, from));
    Vector3 s = vector3_normalize(vector3_cross(f, up));
    Vector3 u = vector3_cross(s, f);
    return (Matrix4){
         s.x, u.x, -f.x, 0.0f,
         s.y, u.y, -f.y, 0.0f,
         s.z, u.z, -f.z, 0.0f,
        -vector3_dot(s, from), -vector3_dot(u, from), vector3_dot(f, from), 1.0f,
    };
}

Matrix4 matrix4_translate(Matrix4 matrix, Vector3 vector) {
    Matrix4 t = matrix4_identity();
    t.m03 = vector.x;
    t.m13 = vector.y;
    t.m23 = vector.z;
    return matrix4_multiply(matrix, t);
}

Matrix4 matrix4_scale(Matrix4 matrix, Vector3 vector) {
    Matrix4 s = (Matrix4){
        .m00 = vector.x,
        .m11 = vector.y,
        .m22 = vector.z,
        .m33 = 1.0f,
    };
    return matrix4_multiply(matrix, s);
}

Matrix4 matrix4_rotate(Matrix4 matrix, float angle, Vector3 axis) {
    float c = cosf(angle);
    float s = sinf(angle);
    float t = 1.0f - c;
    axis = vector3_normalize(axis);
    Matrix4 r = (Matrix4){
        .m00 = (t * axis.x * axis.x) + c,
        .m10 = (t * axis.x * axis.y) - (s * axis.z),
        .m20 = (t * axis.x * axis.z) + (s * axis.y),
        .m30 = 0.0f,
        .m01 = (t * axis.x * axis.y) + (s * axis.z),
        .m11 = (t * axis.y * axis.y) + c,
        .m21 = (t * axis.y * axis.z) - (s * axis.x),
        .m31 = 0.0f,
        .m02 = (t * axis.x * axis.z) - (s * axis.y),
        .m12 = (t * axis.y * axis.z) + (s * axis.x),
        .m22 = (t * axis.z * axis.z) + c,
        .m32 = 0.0f,
        .m03 = 0.0f,
        .m13 = 0.0f,
        .m23 = 0.0f,
        .m33 = 1.0f,
    };
    return matrix4_multiply(matrix, r);
}

Matrix4 matrix4_rotate_x(Matrix4 matrix, float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    Matrix4 r = (Matrix4){
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f,  c,    s,   0.0f,
        0.0f, -s,    c,   0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
    return matrix4_multiply(matrix, r);
}

Matrix4 matrix4_rotate_y(Matrix4 matrix, float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    Matrix4 r = (Matrix4){
         c,   0.0f, s,    0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -s,   0.0f, c,    0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
    return matrix4_multiply(matrix, r);
}

Matrix4 matrix4_rotate_z(Matrix4 matrix, float angle) {
    float c = cosf(angle);
    float s = sinf(angle);
    Matrix4 r = (Matrix4){
        c,    -s,   0.0f, 0.0f,
        s,     c,   0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
    return matrix4_multiply(matrix, r);
}
