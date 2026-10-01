#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#include "common.h"
#include "file.h"
#include "opengl.h"
#include "renderer.h"

static GLenum shader_kind_to_opengl_enum(Shader_Kind kind) {
    switch (kind) {
    case SHADER_KIND_FRAGMENT:
        return GL_FRAGMENT_SHADER;
    case SHADER_KIND_GEOMETRY:
        return GL_GEOMETRY_SHADER;
    case SHADER_KIND_TESSELATION_CONTROL:
        return GL_TESS_CONTROL_SHADER;
    case SHADER_KIND_TESSELATION_EVALUATION:
        return GL_TESS_EVALUATION_SHADER;
    case SHADER_KIND_VERTEX:
        return GL_VERTEX_SHADER;
    default:
        assert(false);
    }
}

static const char *opengl_enum_to_string(GLenum name) {
    switch (name) {
    case GL_COMPUTE_SHADER:
        return "compute";
    case GL_FRAGMENT_SHADER:
        return "fragment";
    case GL_GEOMETRY_SHADER:
        return "geometry";
    case GL_TESS_CONTROL_SHADER:
        return "tesselation control";
    case GL_TESS_EVALUATION_SHADER:
        return "tesselation evaluation";
    case GL_VERTEX_SHADER:
        return "vertex";
    default:
        return "*GLenum*";
    }
}

bool shader_create_from_sources(const Shader_Source *sources, int souces_count, Shader *out_shader) {
    if (1 > souces_count || souces_count > SHADER_SOURCE_MAX_COUNT) {
        LOG_ERROR("shader_create_from_sources expects between 1 and %d shader sources.", SHADER_SOURCE_MAX_COUNT);
        return false;
    }

    GLuint shaders[SHADER_SOURCE_MAX_COUNT] = {0};
    char info_log[256] = {0};
    bool failure = false;
    uint8_t kinds = 0;

    GLuint program = glCreateProgram();

    for (int i = 0; i < souces_count; ++i) {
        const Shader_Source *source = sources + i;

        GLenum type = shader_kind_to_opengl_enum(source->kind);
        if (kinds & source->kind) {
            LOG_WARN("More than one %s shader was provided for the shader program.", opengl_enum_to_string(type));
        }
        kinds |= source->kind;

        GLuint shader = glCreateShader(type);
        shaders[i] = shader;

        glShaderSource(shader, 1, &source->data, NULL);
        glCompileShader(shader);
        glAttachShader(program, shaders[i]);

        GLint compiled = GL_FALSE;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (compiled == GL_FALSE) {
            glGetShaderInfoLog(shader, sizeof(info_log), NULL, info_log);
            LOG_ERROR("Failed to compile %s shader because: %.*s", opengl_enum_to_string(type), (int)sizeof(info_log), info_log);

            failure = true;
        }
    }

    glLinkProgram(program);

    GLint linked = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (linked == GL_FALSE) {
        glGetProgramInfoLog(program, sizeof(info_log), NULL, info_log);
        LOG_ERROR("Failed to link program shader because: %.*s", (int)sizeof(info_log), info_log);

        failure = true;
    }

    for (int i = 0; i < souces_count; ++i) {
        glDetachShader(program, shaders[i]);
        glDeleteShader(shaders[i]);
    }

    if (failure) {
        glDeleteProgram(program);
        return false;
    }

    *out_shader = (Shader){.id = program, .kinds = kinds};
    return true;
}

bool shader_create_from_file_paths(const Shader_Source *paths, int paths_count, Shader *out_shader) {
    if (1 > paths_count || paths_count > SHADER_SOURCE_MAX_COUNT) {
        LOG_ERROR("shader_create_from_file_paths expects between 1 and %d shader sources.", SHADER_SOURCE_MAX_COUNT);
        return false;
    }

    Shader_Source sources[SHADER_SOURCE_MAX_COUNT] = {0};
    File files[SHADER_SOURCE_MAX_COUNT] = {0};
    bool failure = false;

    int sources_count = 0;
    for (int i = 0; i < paths_count; ++i) {
        const Shader_Source *path = paths + i;
        File *file = files + i;
        if (file_read(path->data, file)) {
            sources[sources_count] = (Shader_Source){
                .data = file->data,
                .kind = path->kind,
            };
            ++sources_count;
        } else {
            failure = true;
        }
    }

    Shader shader = {0};
    if (sources_count >= 1 && !shader_create_from_sources(sources, sources_count, &shader)) {
        failure = true;
    }

    for (int i = 0; i < sources_count; ++i) {
        file_free(&files[i]);
    }

    if (failure) {
        if (shader.id != 0) {
            glDeleteShader(shader.id);
        }

        return false;
    }

    *out_shader = shader;
    return true;
}

void shader_destroy(Shader *shader) {
    glDeleteProgram(shader->id);
}
