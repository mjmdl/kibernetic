#version 460 core

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

layout (location = 1) in vec3 v_position;
layout (location = 2) in vec2 v_texcoords;

out vec2 f_texcoords;

void main(void) {
    gl_Position = projection * view * model * vec4(v_position, 1.0);
    f_texcoords = v_texcoords;
}
