#version 460 core

uniform sampler2D u_texture;

in vec2 f_texcoords;

out vec4 r_color;

void main(void) {
    r_color = texture(u_texture, f_texcoords);
}
