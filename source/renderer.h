#ifndef RENDERER_H
#define RENDERER_H

#include <stdbool.h>

typedef enum Shader_Kind {
    SHADER_KIND_COMPUTE = 0x1,
    SHADER_KIND_FRAGMENT = 0x2,
    SHADER_KIND_GEOMETRY = 0x4,
    SHADER_KIND_TESSELATION_CONTROL = 0x8,
    SHADER_KIND_TESSELATION_EVALUATION = 0x10,
    SHADER_KIND_VERTEX = 0x20,
} Shader_Kind;

typedef struct Shader {
    int id;
    int kinds;
} Shader;

typedef struct Shader_Source {
    const char *data;
    Shader_Kind kind;
} Shader_Source;

typedef struct Texture {
    uint32_t id;
} Texture;

enum {
    SHADER_SOURCE_MAX_COUNT = 5,
};

bool shader_create_from_sources(const Shader_Source *sources, int souces_count, Shader *out_shader);

bool shader_create_from_file_paths(const Shader_Source *paths, int paths_count, Shader *out_shader);

void shader_destroy(Shader *shader);

bool texture_load_from_path(const char *file_path, Texture *out_texture);

void texture_destroy(Texture *texture);

#endif // RENDERER_H
