#version 460 core

layout (location = 1) in vec2 v_position;
layout (location = 2) in vec3 v_color;

out vec3 f_color;

void main() {
    gl_Position = vec4(v_position.xy, 0.0, 1.0);
    f_color = v_color;
}
