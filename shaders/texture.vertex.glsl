#version 460 core

layout (location = 1) in vec2 v_position;
layout (location = 2) in vec2 v_texcoord;

out vec2 f_texcoord;

void main() {
    gl_Position = vec4(v_position.xy, 0.0, 1.0);
    f_texcoord = v_texcoord;
}
