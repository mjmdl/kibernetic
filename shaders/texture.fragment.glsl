#version 460 core

uniform sampler2D u_texture;

in vec2 f_texcoord;

out vec4 fragment;

void main(void) {
    fragment = texture(u_texture, f_texcoord);
}
