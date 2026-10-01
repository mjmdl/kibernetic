#ifndef OPENGL_H
#define OPENGL_H

#include <GL/gl.h>

#define FOREACH_OPENGL_PROC_CORE_1_0(X) \
    X(void, glViewport, (GLint x, GLint y, GLsizei width, GLsizei height)) \
    X(void, glDepthRange, (GLdouble nearVal, GLdouble farVal)) \
    X(GLboolean, glIsEnabled, (GLenum cap)) \
    X(void, glGetTexLevelParameteriv, (GLenum target, GLint level, GLenum pname, GLint *params)) \
    X(void, glGetTexLevelParameterfv, (GLenum target, GLint level, GLenum pname, GLfloat *params)) \
    X(void, glGetTexParameteriv, (GLenum target, GLenum pname, GLint *params)) \
    X(void, glGetTexParameterfv, (GLenum target, GLenum pname, GLfloat *params)) \
    X(void, glGetTexImage, (GLenum target, GLint level, GLenum format, GLenum type, void *pixels)) \
    X(const GLubyte *, glGetString, (GLenum name)) \
    X(void, glGetIntegerv, (GLenum pname, GLint *data)) \
    X(void, glGetFloatv, (GLenum pname, GLfloat *data)) \
    X(GLenum, glGetError, (void)) \
    X(void, glGetDoublev, (GLenum pname, GLdouble *data)) \
    X(void, glGetBooleanv, (GLenum pname, GLboolean *data)) \
    X(void, glReadPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels)) \
    X(void, glReadBuffer, (GLenum src)) \
    X(void, glPixelStorei, (GLenum pname, GLint param)) \
    X(void, glPixelStoref, (GLenum pname, GLfloat param)) \
    X(void, glDepthFunc, (GLenum func)) \
    X(void, glStencilOp, (GLenum fail, GLenum zfail, GLenum zpass)) \
    X(void, glStencilFunc, (GLenum func, GLint ref, GLuint mask)) \
    X(void, glLogicOp, (GLenum opcode)) \
    X(void, glBlendFunc, (GLenum sfactor, GLenum dfactor)) \
    X(void, glFlush, (void)) \
    X(void, glFinish, (void)) \
    X(void, glEnable, (GLenum cap)) \
    X(void, glDisable, (GLenum cap)) \
    X(void, glDepthMask, (GLboolean flag)) \
    X(void, glColorMask, (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)) \
    X(void, glStencilMask, (GLuint mask)) \
    X(void, glClearDepth, (GLdouble depth)) \
    X(void, glClearStencil, (GLint s)) \
    X(void, glClearColor, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)) \
    X(void, glClear, (GLbitfield mask)) \
    X(void, glDrawBuffer, (GLenum buf)) \
    X(void, glTexImage2D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels)) \
    X(void, glTexImage1D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels)) \
    X(void, glTexParameteriv, (GLenum target, GLenum pname, const GLint *params)) \
    X(void, glTexParameteri, (GLenum target, GLenum pname, GLint param)) \
    X(void, glTexParameterfv, (GLenum target, GLenum pname, const GLfloat *params)) \
    X(void, glTexParameterf, (GLenum target, GLenum pname, GLfloat param)) \
    X(void, glScissor, (GLint x, GLint y, GLsizei width, GLsizei height)) \
    X(void, glPolygonMode, (GLenum face, GLenum mode)) \
    X(void, glPointSize, (GLfloat size)) \
    X(void, glLineWidth, (GLfloat width)) \
    X(void, glHint, (GLenum target, GLenum mode)) \
    X(void, glFrontFace, (GLenum mode)) \
    X(void, glCullFace, (GLenum mode))

#define FOREACH_OPENGL_PROC_CORE_1_1(X) \
    X(GLboolean, glIsTexture, (GLuint texture)) \
    X(void, glGenTextures, (GLsizei n, GLuint *textures)) \
    X(void, glDeleteTextures,(GLsizei n, const GLuint *textures)) \
    X(void, glBindTexture, (GLenum target, GLuint texture)) \
    X(void, glTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)) \
    X(void, glTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels)) \
    X(void, glCopyTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    X(void, glCopyTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)) \
    X(void, glCopyTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)) \
    X(void, glCopyTexImage1D, (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)) \
    X(void, glPolygonOffset, (GLfloat factor, GLfloat units)) \
    X(void, glDrawElements, (GLenum mode, GLsizei count, GLenum type, const void *indices)) \
    X(void, glDrawArrays, (GLenum mode, GLint first, GLsizei count))

#define FOREACH_OPENGL_PROC_CORE_1_2(X) \
    X(void, glBlendColor, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)) \
    X(void, glBlendEquation, (GLenum mode)) \
    X(void, glCopyTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    X(void, glTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)) \
    X(void, glTexImage3D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels)) \
    X(void, glDrawRangeElements, (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices))

#define FOREACH_OPENGL_PROC_CORE_1_3(X) \
    X(void, glGetCompressedTexImage, (GLenum target, GLint level, void *img)) \
    X(void, glCompressedTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data)) \
    X(void, glCompressedTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)) \
    X(void, glCompressedTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)) \
    X(void, glCompressedTexImage1D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data)) \
    X(void, glCompressedTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)) \
    X(void, glCompressedTexImage3D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)) \
    X(void, glSampleCoverage, (GLfloat value, GLboolean invert)) \
    X(void, glActiveTexture, (GLenum texture))

#define FOREACH_OPENGL_PROC_CORE_1_4(X) \
    X(void, glPointParameteriv, (GLenum pname, const GLint *params)) \
    X(void, glPointParameteri, (GLenum pname, GLint param)) \
    X(void, glPointParameterfv, (GLenum pname, const GLfloat *params)) \
    X(void, glPointParameterf, (GLenum pname, GLfloat param)) \
    X(void, glMultiDrawElements, (GLenum mode, const GLsizei *count, GLenum type, const void *const *indices, GLsizei drawcount)) \
    X(void, glMultiDrawArrays, (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount)) \
    X(void, glBlendFuncSeparate, (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha))

#define FOREACH_OPENGL_PROC_CORE_1_5(X) \
    X(void, glGetBufferPointerv, (GLenum target, GLenum pname, void * *params)) \
    X(void, glGetBufferParameteriv, (GLenum target, GLenum pname, GLint *params)) \
    X(GLboolean, glUnmapBuffer, (GLenum target)) \
    X(void *, glMapBuffer, (GLenum target, GLenum access)) \
    X(void, glGetBufferSubData, (GLenum target, GLintptr offset, GLsizeiptr size, void *data)) \
    X(void, glBufferSubData, (GLenum target, GLintptr offset, GLsizeiptr size, const void *data)) \
    X(void, glBufferData, (GLenum target, GLsizeiptr size, const void *data, GLenum usage)) \
    X(GLboolean, glIsBuffer, (GLuint buffer)) \
    X(void, glGenBuffers, (GLsizei n, GLuint *buffers)) \
    X(void, glDeleteBuffers, (GLsizei n, const GLuint *buffers)) \
    X(void, glBindBuffer, (GLenum target, GLuint buffer)) \
    X(void, glGetQueryObjectuiv, (GLuint id, GLenum pname, GLuint *params)) \
    X(void, glGetQueryObjectiv, (GLuint id, GLenum pname, GLint *params)) \
    X(void, glGetQueryiv, (GLenum target, GLenum pname, GLint *params)) \
    X(void, glEndQuery, (GLenum target)) \
    X(void, glBeginQuery, (GLenum target, GLuint id)) \
    X(GLboolean, glIsQuery, (GLuint id)) \
    X(void, glDeleteQueries, (GLsizei n, const GLuint *ids)) \
    X(void, glGenQueries, (GLsizei n, GLuint *ids))

#define FOREACH_OPENGL_PROC_CORE_2_0(X) \
    X(void, glVertexAttribPointer, (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)) \
    X(void, glVertexAttrib4usv, (GLuint index, const GLushort *v)) \
    X(void, glVertexAttrib4uiv, (GLuint index, const GLuint *v)) \
    X(void, glVertexAttrib4ubv, (GLuint index, const GLubyte *v)) \
    X(void, glVertexAttrib4sv, (GLuint index, const GLshort *v)) \
    X(void, glVertexAttrib4s, (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)) \
    X(void, glVertexAttrib4iv, (GLuint index, const GLint *v)) \
    X(void, glVertexAttrib4fv, (GLuint index, const GLfloat *v)) \
    X(void, glVertexAttrib4f, (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)) \
    X(void, glVertexAttrib4dv, (GLuint index, const GLdouble *v)) \
    X(void, glVertexAttrib4d, (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)) \
    X(void, glVertexAttrib4bv, (GLuint index, const GLbyte *v)) \
    X(void, glVertexAttrib4Nusv, (GLuint index, const GLushort *v)) \
    X(void, glVertexAttrib4Nuiv, (GLuint index, const GLuint *v)) \
    X(void, glVertexAttrib4Nubv, (GLuint index, const GLubyte *v)) \
    X(void, glVertexAttrib4Nub, (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)) \
    X(void, glVertexAttrib4Nsv, (GLuint index, const GLshort *v)) \
    X(void, glVertexAttrib4Niv, (GLuint index, const GLint *v)) \
    X(void, glVertexAttrib4Nbv, (GLuint index, const GLbyte *v)) \
    X(void, glVertexAttrib3sv, (GLuint index, const GLshort *v)) \
    X(void, glVertexAttrib3s, (GLuint index, GLshort x, GLshort y, GLshort z)) \
    X(void, glVertexAttrib3fv, (GLuint index, const GLfloat *v)) \
    X(void, glVertexAttrib3f, (GLuint index, GLfloat x, GLfloat y, GLfloat z)) \
    X(void, glVertexAttrib3dv, (GLuint index, const GLdouble *v)) \
    X(void, glVertexAttrib3d, (GLuint index, GLdouble x, GLdouble y, GLdouble z)) \
    X(void, glVertexAttrib2sv, (GLuint index, const GLshort *v)) \
    X(void, glVertexAttrib2s, (GLuint index, GLshort x, GLshort y)) \
    X(void, glVertexAttrib2fv, (GLuint index, const GLfloat *v)) \
    X(void, glVertexAttrib2f, (GLuint index, GLfloat x, GLfloat y)) \
    X(void, glVertexAttrib2dv, (GLuint index, const GLdouble *v)) \
    X(void, glVertexAttrib2d, (GLuint index, GLdouble x, GLdouble y)) \
    X(void, glVertexAttrib1sv, (GLuint index, const GLshort *v)) \
    X(void, glVertexAttrib1s, (GLuint index, GLshort x)) \
    X(void, glVertexAttrib1fv, (GLuint index, const GLfloat *v)) \
    X(void, glVertexAttrib1f, (GLuint index, GLfloat x)) \
    X(void, glVertexAttrib1dv, (GLuint index, const GLdouble *v)) \
    X(void, glVertexAttrib1d, (GLuint index, GLdouble x)) \
    X(void, glValidateProgram, (GLuint program)) \
    X(void, glUniformMatrix4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glUniformMatrix3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glUniformMatrix2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glUniform4iv, (GLint location, GLsizei count, const GLint *value)) \
    X(void, glUniform3iv, (GLint location, GLsizei count, const GLint *value)) \
    X(void, glUniform2iv, (GLint location, GLsizei count, const GLint *value)) \
    X(void, glUniform1iv, (GLint location, GLsizei count, const GLint *value)) \
    X(void, glUniform4fv, (GLint location, GLsizei count, const GLfloat *value)) \
    X(void, glUniform3fv, (GLint location, GLsizei count, const GLfloat *value)) \
    X(void, glUniform2fv, (GLint location, GLsizei count, const GLfloat *value)) \
    X(void, glUniform1fv, (GLint location, GLsizei count, const GLfloat *value)) \
    X(void, glUniform4i, (GLint location, GLint v0, GLint v1, GLint v2, GLint v3)) \
    X(void, glUniform3i, (GLint location, GLint v0, GLint v1, GLint v2)) \
    X(void, glUniform2i, (GLint location, GLint v0, GLint v1)) \
    X(void, glUniform1i, (GLint location, GLint v0)) \
    X(void, glUniform4f, (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)) \
    X(void, glUniform3f, (GLint location, GLfloat v0, GLfloat v1, GLfloat v2)) \
    X(void, glUniform2f, (GLint location, GLfloat v0, GLfloat v1)) \
    X(void, glUniform1f, (GLint location, GLfloat v0)) \
    X(void, glUseProgram, (GLuint program)) \
    X(void, glShaderSource, (GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length)) \
    X(void, glLinkProgram, (GLuint program)) \
    X(GLboolean, glIsShader, (GLuint shader)) \
    X(GLboolean, glIsProgram, (GLuint program)) \
    X(void, glGetVertexAttribPointerv, (GLuint index, GLenum pname, void * *pointer)) \
    X(void, glGetVertexAttribiv, (GLuint index, GLenum pname, GLint *params)) \
    X(void, glGetVertexAttribfv, (GLuint index, GLenum pname, GLfloat *params)) \
    X(void, glGetVertexAttribdv, (GLuint index, GLenum pname, GLdouble *params)) \
    X(void, glGetUniformiv, (GLuint program, GLint location, GLint *params)) \
    X(void, glGetUniformfv, (GLuint program, GLint location, GLfloat *params)) \
    X(GLint, glGetUniformLocation, (GLuint program, const GLchar *name)) \
    X(void, glGetShaderSource, (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)) \
    X(void, glGetShaderInfoLog, (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \
    X(void, glGetShaderiv, (GLuint shader, GLenum pname, GLint *params)) \
    X(void, glGetProgramInfoLog, (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \
    X(void, glGetProgramiv, (GLuint program, GLenum pname, GLint *params)) \
    X(GLint, glGetAttribLocation, (GLuint program, const GLchar *name)) \
    X(void, glGetAttachedShaders, (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)) \
    X(void, glGetActiveUniform, (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)) \
    X(void, glGetActiveAttrib, (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)) \
    X(void, glEnableVertexAttribArray, (GLuint index)) \
    X(void, glDisableVertexAttribArray, (GLuint index)) \
    X(void, glDetachShader, (GLuint program, GLuint shader)) \
    X(void, glDeleteShader, (GLuint shader)) \
    X(void, glDeleteProgram, (GLuint program)) \
    X(GLuint, glCreateShader, (GLenum type)) \
    X(GLuint, glCreateProgram, (void)) \
    X(void, glCompileShader, (GLuint shader)) \
    X(void, glBindAttribLocation, (GLuint program, GLuint index, const GLchar *name)) \
    X(void, glAttachShader, (GLuint program, GLuint shader)) \
    X(void, glStencilMaskSeparate, (GLenum face, GLuint mask)) \
    X(void, glStencilFuncSeparate, (GLenum face, GLenum func, GLint ref, GLuint mask)) \
    X(void, glStencilOpSeparate, (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)) \
    X(void, glDrawBuffers, (GLsizei n, const GLenum *bufs)) \
    X(void, glBlendEquationSeparate, (GLenum modeRGB, GLenum modeAlpha))

#define FOREACH_OPENGL_PROC_CORE_2_1(X) \
    X(void, glUniformMatrix4x3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glUniformMatrix3x4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glUniformMatrix4x2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glUniformMatrix2x4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glUniformMatrix3x2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glUniformMatrix2x3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))

#define FOREACH_OPENGL_PROC_CORE_3_0(X) \
    X(GLboolean, glIsVertexArray, (GLuint array)) \
    X(void, glGenVertexArrays, (GLsizei n, GLuint *arrays)) \
    X(void, glDeleteVertexArrays, (GLsizei n, const GLuint *arrays)) \
    X(void, glBindVertexArray, (GLuint array)) \
    X(void, glFlushMappedBufferRange, (GLenum target, GLintptr offset, GLsizeiptr length)) \
    X(void *, glMapBufferRange, (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)) \
    X(void, glFramebufferTextureLayer, (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)) \
    X(void, glRenderbufferStorageMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    X(void, glBlitFramebuffer, (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)) \
    X(void, glGenerateMipmap, (GLenum target)) \
    X(void, glGetFramebufferAttachmentParameteriv, (GLenum target, GLenum attachment, GLenum pname, GLint *params)) \
    X(void, glFramebufferRenderbuffer, (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)) \
    X(void, glFramebufferTexture3D, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)) \
    X(void, glFramebufferTexture2D, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)) \
    X(void, glFramebufferTexture1D, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)) \
    X(GLenum, glCheckFramebufferStatus, (GLenum target)) \
    X(void, glGenFramebuffers, (GLsizei n, GLuint *framebuffers)) \
    X(void, glDeleteFramebuffers, (GLsizei n, const GLuint *framebuffers)) \
    X(void, glBindFramebuffer, (GLenum target, GLuint framebuffer)) \
    X(GLboolean, glIsFramebuffer, (GLuint framebuffer)) \
    X(void, glGetRenderbufferParameteriv, (GLenum target, GLenum pname, GLint *params)) \
    X(void, glRenderbufferStorage, (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)) \
    X(void, glGenRenderbuffers, (GLsizei n, GLuint *renderbuffers)) \
    X(void, glDeleteRenderbuffers, (GLsizei n, const GLuint *renderbuffers)) \
    X(void, glBindRenderbuffer, (GLenum target, GLuint renderbuffer)) \
    X(GLboolean, glIsRenderbuffer, (GLuint renderbuffer)) \
    X(const GLubyte *, glGetStringi, (GLenum name, GLuint index)) \
    X(void, glClearBufferfi, (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)) \
    X(void, glClearBufferfv, (GLenum buffer, GLint drawbuffer, const GLfloat *value)) \
    X(void, glClearBufferuiv, (GLenum buffer, GLint drawbuffer, const GLuint *value)) \
    X(void, glClearBufferiv, (GLenum buffer, GLint drawbuffer, const GLint *value)) \
    X(void, glGetTexParameterIuiv, (GLenum target, GLenum pname, GLuint *params)) \
    X(void, glGetTexParameterIiv, (GLenum target, GLenum pname, GLint *params)) \
    X(void, glTexParameterIuiv, (GLenum target, GLenum pname, const GLuint *params)) \
    X(void, glTexParameterIiv, (GLenum target, GLenum pname, const GLint *params)) \
    X(void, glUniform4uiv, (GLint location, GLsizei count, const GLuint *value)) \
    X(void, glUniform3uiv, (GLint location, GLsizei count, const GLuint *value)) \
    X(void, glUniform2uiv, (GLint location, GLsizei count, const GLuint *value)) \
    X(void, glUniform1uiv, (GLint location, GLsizei count, const GLuint *value)) \
    X(void, glUniform4ui, (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)) \
    X(void, glUniform3ui, (GLint location, GLuint v0, GLuint v1, GLuint v2)) \
    X(void, glUniform2ui, (GLint location, GLuint v0, GLuint v1)) \
    X(void, glUniform1ui, (GLint location, GLuint v0)) \
    X(GLint, glGetFragDataLocation, (GLuint program, const GLchar *name)) \
    X(void, glBindFragDataLocation, (GLuint program, GLuint color, const GLchar *name)) \
    X(void, glGetUniformuiv, (GLuint program, GLint location, GLuint *params)) \
    X(void, glVertexAttribI4usv, (GLuint index, const GLushort *v)) \
    X(void, glVertexAttribI4ubv, (GLuint index, const GLubyte *v)) \
    X(void, glVertexAttribI4sv, (GLuint index, const GLshort *v)) \
    X(void, glVertexAttribI4bv, (GLuint index, const GLbyte *v)) \
    X(void, glVertexAttribI4uiv, (GLuint index, const GLuint *v)) \
    X(void, glVertexAttribI3uiv, (GLuint index, const GLuint *v)) \
    X(void, glVertexAttribI2uiv, (GLuint index, const GLuint *v)) \
    X(void, glVertexAttribI1uiv, (GLuint index, const GLuint *v)) \
    X(void, glVertexAttribI4iv, (GLuint index, const GLint *v)) \
    X(void, glVertexAttribI3iv, (GLuint index, const GLint *v)) \
    X(void, glVertexAttribI2iv, (GLuint index, const GLint *v)) \
    X(void, glVertexAttribI1iv, (GLuint index, const GLint *v)) \
    X(void, glVertexAttribI4ui, (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)) \
    X(void, glVertexAttribI3ui, (GLuint index, GLuint x, GLuint y, GLuint z)) \
    X(void, glVertexAttribI2ui, (GLuint index, GLuint x, GLuint y)) \
    X(void, glVertexAttribI1ui, (GLuint index, GLuint x)) \
    X(void, glVertexAttribI4i, (GLuint index, GLint x, GLint y, GLint z, GLint w)) \
    X(void, glVertexAttribI3i, (GLuint index, GLint x, GLint y, GLint z)) \
    X(void, glVertexAttribI2i, (GLuint index, GLint x, GLint y)) \
    X(void, glVertexAttribI1i, (GLuint index, GLint x)) \
    X(void, glGetVertexAttribIuiv, (GLuint index, GLenum pname, GLuint *params)) \
    X(void, glGetVertexAttribIiv, (GLuint index, GLenum pname, GLint *params)) \
    X(void, glVertexAttribIPointer, (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)) \
    X(void, glEndConditionalRender, (void)) \
    X(void, glBeginConditionalRender, (GLuint id, GLenum mode)) \
    X(void, glClampColor,(GLenum target, GLenum clamp)) \
    X(void, glGetTransformFeedbackVarying, (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)) \
    X(void, glTransformFeedbackVaryings, (GLuint program, GLsizei count, const GLchar* const *varyings, GLenum bufferMode)) \
    X(void, glBindBufferBase, (GLenum target, GLuint index, GLuint buffer)) \
    X(void, glBindBufferRange, (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)) \
    X(void, glEndTransformFeedback, (void)) \
    X(void, glBeginTransformFeedback, (GLenum primitiveMode)) \
    X(GLboolean, glIsEnabledi, (GLenum target, GLuint index)) \
    X(void, glDisablei, (GLenum target, GLuint index)) \
    X(void, glEnablei, (GLenum target, GLuint index)) \
    X(void, glGetIntegeri_v, (GLenum target, GLuint index, GLint *data)) \
    X(void, glGetBooleani_v, (GLenum target, GLuint index, GLboolean *data)) \
    X(void, glColorMaski, (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a))

#define FOREACH_OPENGL_PROC_CORE_3_1(X) \
    X(void, glUniformBlockBinding, (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)) \
    X(void, glGetActiveUniformBlockName, (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)) \
    X(void, glGetActiveUniformBlockiv, (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)) \
    X(GLuint, glGetUniformBlockIndex, (GLuint program, const GLchar *uniformBlockName)) \
    X(void, glGetActiveUniformName, (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName)) \
    X(void, glGetActiveUniformsiv, (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)) \
    X(void, glGetUniformIndices, (GLuint program, GLsizei uniformCount, const GLchar *const *uniformNames, GLuint *uniformIndices)) \
    X(void, glCopyBufferSubData, (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)) \
    X(void, glPrimitiveRestartIndex, (GLuint index)) \
    X(void, glTexBuffer, (GLenum target, GLenum internalformat, GLuint buffer)) \
    X(void, glDrawElementsInstanced, (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount)) \
    X(void, glDrawArraysInstanced, (GLenum mode, GLint first, GLsizei count, GLsizei instancecount))

#define FOREACH_OPENGL_PROC_CORE_3_2(X) \
    X(void, glSampleMaski, (GLuint maskNumber, GLbitfield mask)) \
    X(void, glGetMultisamplefv, (GLenum pname, GLuint index, GLfloat *val)) \
    X(void, glTexImage3DMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)) \
    X(void, glTexImage2DMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)) \
    X(void, glFramebufferTexture, (GLenum target, GLenum attachment, GLuint texture, GLint level)) \
    X(void, glGetBufferParameteri64v, (GLenum target, GLenum pname, GLint64 *params)) \
    X(void, glGetInteger64i_v, (GLenum target, GLuint index, GLint64 *data)) \
    X(void, glGetSynciv, (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)) \
    X(void, glGetInteger64v, (GLenum pname, GLint64 *data)) \
    X(void, glWaitSync, (GLsync sync, GLbitfield flags, GLuint64 timeout)) \
    X(GLenum, glClientWaitSync, (GLsync sync, GLbitfield flags, GLuint64 timeout)) \
    X(void, glDeleteSync, (GLsync sync)) \
    X(GLboolean, glIsSync, (GLsync sync)) \
    X(GLsync, glFenceSync, (GLenum condition, GLbitfield flags)) \
    X(void, glProvokingVertex, (GLenum mode)) \
    X(void, glMultiDrawElementsBaseVertex, (GLenum mode, const GLsizei *count, GLenum type, const void *const *indices, GLsizei drawcount, const GLint *basevertex)) \
    X(void, glDrawElementsInstancedBaseVertex, (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex)) \
    X(void, glDrawRangeElementsBaseVertex, (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)) \
    X(void, glDrawElementsBaseVertex, (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex))

#define FOREACH_OPENGL_PROC_CORE_3_3(X) \
    X(void, glVertexAttribP4uiv, (GLuint index, GLenum type, GLboolean normalized, const GLuint *value)) \
    X(void, glVertexAttribP4ui, (GLuint index, GLenum type, GLboolean normalized, GLuint value)) \
    X(void, glVertexAttribP3uiv, (GLuint index, GLenum type, GLboolean normalized, const GLuint *value)) \
    X(void, glVertexAttribP3ui, (GLuint index, GLenum type, GLboolean normalized, GLuint value)) \
    X(void, glVertexAttribP2uiv, (GLuint index, GLenum type, GLboolean normalized, const GLuint *value)) \
    X(void, glVertexAttribP2ui, (GLuint index, GLenum type, GLboolean normalized, GLuint value)) \
    X(void, glVertexAttribP1uiv, (GLuint index, GLenum type, GLboolean normalized, const GLuint *value)) \
    X(void, glVertexAttribP1ui, (GLuint index, GLenum type, GLboolean normalized, GLuint value)) \
    X(void, glVertexAttribDivisor, (GLuint index, GLuint divisor)) \
    X(void, glGetQueryObjectui64v, (GLuint id, GLenum pname, GLuint64 *params)) \
    X(void, glGetQueryObjecti64v, (GLuint id, GLenum pname, GLint64 *params)) \
    X(void, glQueryCounter, (GLuint id, GLenum target)) \
    X(void, glGetSamplerParameterIuiv, (GLuint sampler, GLenum pname, GLuint *params)) \
    X(void, glGetSamplerParameterfv, (GLuint sampler, GLenum pname, GLfloat *params)) \
    X(void, glGetSamplerParameterIiv, (GLuint sampler, GLenum pname, GLint *params)) \
    X(void, glGetSamplerParameteriv, (GLuint sampler, GLenum pname, GLint *params)) \
    X(void, glSamplerParameterIuiv, (GLuint sampler, GLenum pname, const GLuint *param)) \
    X(void, glSamplerParameterIiv, (GLuint sampler, GLenum pname, const GLint *param)) \
    X(void, glSamplerParameterfv, (GLuint sampler, GLenum pname, const GLfloat *param)) \
    X(void, glSamplerParameterf, (GLuint sampler, GLenum pname, GLfloat param)) \
    X(void, glSamplerParameteriv, (GLuint sampler, GLenum pname, const GLint *param)) \
    X(void, glSamplerParameteri, (GLuint sampler, GLenum pname, GLint param)) \
    X(void, glBindSampler, (GLuint unit, GLuint sampler)) \
    X(GLboolean, glIsSampler, (GLuint sampler)) \
    X(void, glDeleteSamplers, (GLsizei count, const GLuint *samplers)) \
    X(void, glGenSamplers, (GLsizei count, GLuint *samplers)) \
    X(GLint, glGetFragDataIndex, (GLuint program, const GLchar *name)) \
    X(void, glBindFragDataLocationIndexed, (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name))

#define FOREACH_OPENGL_PROC_CORE_4_0(X) \
    X(void, glGetQueryIndexediv, (GLenum target, GLuint index, GLenum pname, GLint *params)) \
    X(void, glEndQueryIndexed, (GLenum target, GLuint index)) \
    X(void, glBeginQueryIndexed, (GLenum target, GLuint index, GLuint id)) \
    X(void, glDrawTransformFeedbackStream, (GLenum mode, GLuint id, GLuint stream)) \
    X(void, glDrawTransformFeedback, (GLenum mode, GLuint id)) \
    X(void, glResumeTransformFeedback, (void)) \
    X(void, glPauseTransformFeedback, (void)) \
    X(GLboolean, glIsTransformFeedback, (GLuint id)) \
    X(void, glGenTransformFeedbacks, (GLsizei n, GLuint *ids)) \
    X(void, glDeleteTransformFeedbacks, (GLsizei n, const GLuint *ids)) \
    X(void, glBindTransformFeedback, (GLenum target, GLuint id)) \
    X(void, glPatchParameterfv, (GLenum pname, const GLfloat *values)) \
    X(void, glPatchParameteri, (GLenum pname, GLint value)) \
    X(void, glGetProgramStageiv, (GLuint program, GLenum shadertype, GLenum pname, GLint *values)) \
    X(void, glGetUniformSubroutineuiv, (GLenum shadertype, GLint location, GLuint *params)) \
    X(void, glUniformSubroutinesuiv, (GLenum shadertype, GLsizei count, const GLuint *indices)) \
    X(void, glGetActiveSubroutineName, (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)) \
    X(void, glGetActiveSubroutineUniformName, (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)) \
    X(void, glGetActiveSubroutineUniformiv, (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values)) \
    X(GLuint, glGetSubroutineIndex, (GLuint program, GLenum shadertype, const GLchar *name)) \
    X(GLint, glGetSubroutineUniformLocation, (GLuint program, GLenum shadertype, const GLchar *name)) \
    X(void, glGetUniformdv, (GLuint program, GLint location, GLdouble *params)) \
    X(void, glUniformMatrix4x3dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glUniformMatrix4x2dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glUniformMatrix3x4dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glUniformMatrix3x2dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glUniformMatrix2x4dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glUniformMatrix2x3dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glUniformMatrix4dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glUniformMatrix3dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glUniformMatrix2dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glUniform4dv, (GLint location, GLsizei count, const GLdouble *value)) \
    X(void, glUniform3dv, (GLint location, GLsizei count, const GLdouble *value)) \
    X(void, glUniform2dv, (GLint location, GLsizei count, const GLdouble *value)) \
    X(void, glUniform1dv, (GLint location, GLsizei count, const GLdouble *value)) \
    X(void, glUniform4d, (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)) \
    X(void, glUniform3d, (GLint location, GLdouble x, GLdouble y, GLdouble z)) \
    X(void, glUniform2d, (GLint location, GLdouble x, GLdouble y)) \
    X(void, glUniform1d, (GLint location, GLdouble x)) \
    X(void, glDrawElementsIndirect, (GLenum mode, GLenum type, const void *indirect)) \
    X(void, glDrawArraysIndirect, (GLenum mode, const void *indirect)) \
    X(void, glBlendFuncSeparatei, (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)) \
    X(void, glBlendFunci, (GLuint buf, GLenum src, GLenum dst)) \
    X(void, glBlendEquationSeparatei, (GLuint buf, GLenum modeRGB, GLenum modeAlpha)) \
    X(void, glBlendEquationi, (GLuint buf, GLenum mode)) \
    X(void, glMinSampleShading, (GLfloat value))

#define FOREACH_OPENGL_PROC_CORE_4_1(X) \
    X(void, glGetDoublei_v, (GLenum target, GLuint index, GLdouble *data)) \
    X(void, glGetFloati_v, (GLenum target, GLuint index, GLfloat *data)) \
    X(void, glDepthRangeIndexed, (GLuint index, GLdouble n, GLdouble f)) \
    X(void, glDepthRangeArrayv, (GLuint first, GLsizei count, const GLdouble *v)) \
    X(void, glScissorIndexedv, (GLuint index, const GLint *v)) \
    X(void, glScissorIndexed, (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)) \
    X(void, glScissorArrayv, (GLuint first, GLsizei count, const GLint *v)) \
    X(void, glViewportIndexedfv, (GLuint index, const GLfloat *v)) \
    X(void, glViewportIndexedf, (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)) \
    X(void, glViewportArrayv, (GLuint first, GLsizei count, const GLfloat *v)) \
    X(void, glGetVertexAttribLdv, (GLuint index, GLenum pname, GLdouble *params)) \
    X(void, glVertexAttribLPointer, (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)) \
    X(void, glVertexAttribL4dv, (GLuint index, const GLdouble *v)) \
    X(void, glVertexAttribL3dv, (GLuint index, const GLdouble *v)) \
    X(void, glVertexAttribL2dv, (GLuint index, const GLdouble *v)) \
    X(void, glVertexAttribL1dv, (GLuint index, const GLdouble *v)) \
    X(void, glVertexAttribL4d, (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)) \
    X(void, glVertexAttribL3d, (GLuint index, GLdouble x, GLdouble y, GLdouble z)) \
    X(void, glVertexAttribL2d, (GLuint index, GLdouble x, GLdouble y)) \
    X(void, glVertexAttribL1d, (GLuint index, GLdouble x)) \
    X(void, glGetProgramPipelineInfoLog, (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)) \
    X(void, glValidateProgramPipeline, (GLuint pipeline)) \
    X(void, glProgramUniformMatrix4x3dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glProgramUniformMatrix3x4dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glProgramUniformMatrix4x2dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glProgramUniformMatrix2x4dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glProgramUniformMatrix3x2dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glProgramUniformMatrix2x3dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glProgramUniformMatrix4x3fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glProgramUniformMatrix3x4fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glProgramUniformMatrix4x2fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glProgramUniformMatrix2x4fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glProgramUniformMatrix3x2fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glProgramUniformMatrix2x3fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glProgramUniformMatrix4dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glProgramUniformMatrix3dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glProgramUniformMatrix2dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)) \
    X(void, glProgramUniformMatrix4fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glProgramUniformMatrix3fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glProgramUniformMatrix2fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)) \
    X(void, glProgramUniform4uiv, (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    X(void, glProgramUniform4ui, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)) \
    X(void, glProgramUniform4dv, (GLuint program, GLint location, GLsizei count, const GLdouble *value)) \
    X(void, glProgramUniform4d, (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3)) \
    X(void, glProgramUniform4fv, (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    X(void, glProgramUniform4f, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)) \
    X(void, glProgramUniform4iv, (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    X(void, glProgramUniform4i, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)) \
    X(void, glProgramUniform3uiv, (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    X(void, glProgramUniform3ui, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)) \
    X(void, glProgramUniform3dv, (GLuint program, GLint location, GLsizei count, const GLdouble *value)) \
    X(void, glProgramUniform3d, (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2)) \
    X(void, glProgramUniform3fv, (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    X(void, glProgramUniform3f, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)) \
    X(void, glProgramUniform3iv, (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    X(void, glProgramUniform3i, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2)) \
    X(void, glProgramUniform2uiv, (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    X(void, glProgramUniform2ui, (GLuint program, GLint location, GLuint v0, GLuint v1)) \
    X(void, glProgramUniform2dv, (GLuint program, GLint location, GLsizei count, const GLdouble *value)) \
    X(void, glProgramUniform2d, (GLuint program, GLint location, GLdouble v0, GLdouble v1)) \
    X(void, glProgramUniform2fv, (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    X(void, glProgramUniform2f, (GLuint program, GLint location, GLfloat v0, GLfloat v1)) \
    X(void, glProgramUniform2iv, (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    X(void, glProgramUniform2i, (GLuint program, GLint location, GLint v0, GLint v1)) \
    X(void, glProgramUniform1uiv, (GLuint program, GLint location, GLsizei count, const GLuint *value)) \
    X(void, glProgramUniform1ui, (GLuint program, GLint location, GLuint v0)) \
    X(void, glProgramUniform1dv, (GLuint program, GLint location, GLsizei count, const GLdouble *value)) \
    X(void, glProgramUniform1d, (GLuint program, GLint location, GLdouble v0)) \
    X(void, glProgramUniform1fv, (GLuint program, GLint location, GLsizei count, const GLfloat *value)) \
    X(void, glProgramUniform1f, (GLuint program, GLint location, GLfloat v0)) \
    X(void, glProgramUniform1iv, (GLuint program, GLint location, GLsizei count, const GLint *value)) \
    X(void, glProgramUniform1i, (GLuint program, GLint location, GLint v0)) \
    X(void, glGetProgramPipelineiv, (GLuint pipeline, GLenum pname, GLint *params)) \
    X(GLboolean, glIsProgramPipeline, (GLuint pipeline)) \
    X(void, glGenProgramPipelines, (GLsizei n, GLuint *pipelines)) \
    X(void, glDeleteProgramPipelines, (GLsizei n, const GLuint *pipelines)) \
    X(void, glBindProgramPipeline, (GLuint pipeline)) \
    X(GLuint, glCreateShaderProgramv, (GLenum type, GLsizei count, const GLchar* const *strings)) \
    X(void, glActiveShaderProgram, (GLuint pipeline, GLuint program)) \
    X(void, glUseProgramStages, (GLuint pipeline, GLbitfield stages, GLuint program)) \
    X(void, glProgramParameteri, (GLuint program, GLenum pname, GLint value)) \
    X(void, glProgramBinary, (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length)) \
    X(void, glGetProgramBinary, (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)) \
    X(void, glClearDepthf, (GLfloat dd)) \
    X(void, glDepthRangef, (GLfloat n, GLfloat f)) \
    X(void, glGetShaderPrecisionFormat, (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)) \
    X(void, glShaderBinary, (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length)) \
    X(void, glReleaseShaderCompiler, (void))

#define FOREACH_OPENGL_PROC_CORE_4_2(X) \
    X(void, glDrawTransformFeedbackStreamInstanced, (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount)) \
    X(void, glDrawTransformFeedbackInstanced, (GLenum mode, GLuint id, GLsizei instancecount)) \
    X(void, glTexStorage3D, (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)) \
    X(void, glTexStorage2D, (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)) \
    X(void, glTexStorage1D, (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)) \
    X(void, glMemoryBarrier, (GLbitfield barriers)) \
    X(void, glBindImageTexture, (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)) \
    X(void, glGetActiveAtomicCounterBufferiv, (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params)) \
    X(void, glGetInternalformativ, (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)) \
    X(void, glDrawElementsInstancedBaseVertexBaseInstance, (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)) \
    X(void, glDrawElementsInstancedBaseInstance, (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance)) \
    X(void, glDrawArraysInstancedBaseInstance, (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance))

#define FOREACH_OPENGL_PROC_CORE_4_3(X) \
    X(void, glGetObjectPtrLabel, (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label)) \
    X(void, glObjectPtrLabel, (const void *ptr, GLsizei length, const GLchar *label)) \
    X(void, glGetObjectLabel, (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label)) \
    X(void, glObjectLabel, (GLenum identifier, GLuint name, GLsizei length, const GLchar *label)) \
    X(void, glPopDebugGroup, (void)) \
    X(void, glPushDebugGroup, (GLenum source, GLuint id, GLsizei length, const GLchar *message)) \
    X(GLuint, glGetDebugMessageLog, (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)) \
    X(void, glDebugMessageCallback, (GLDEBUGPROC callback, const void *userParam)) \
    X(void, glDebugMessageInsert, (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf)) \
    X(void, glDebugMessageControl, (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)) \
    X(void, glVertexBindingDivisor, (GLuint bindingindex, GLuint divisor)) \
    X(void, glVertexAttribBinding, (GLuint attribindex, GLuint bindingindex)) \
    X(void, glVertexAttribLFormat, (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)) \
    X(void, glVertexAttribIFormat, (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)) \
    X(void, glVertexAttribFormat, (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)) \
    X(void, glBindVertexBuffer, (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)) \
    X(void, glTextureView, (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)) \
    X(void, glTexStorage3DMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)) \
    X(void, glTexStorage2DMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)) \
    X(void, glTexBufferRange, (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)) \
    X(void, glShaderStorageBlockBinding, (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)) \
    X(GLint, glGetProgramResourceLocationIndex, (GLuint program, GLenum programInterface, const GLchar *name)) \
    X(GLint, glGetProgramResourceLocation, (GLuint program, GLenum programInterface, const GLchar *name)) \
    X(void, glGetProgramResourceiv, (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params)) \
    X(void, glGetProgramResourceName, (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name)) \
    X(GLuint, glGetProgramResourceIndex, (GLuint program, GLenum programInterface, const GLchar *name)) \
    X(void, glGetProgramInterfaceiv, (GLuint program, GLenum programInterface, GLenum pname, GLint *params)) \
    X(void, glMultiDrawElementsIndirect, (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride)) \
    X(void, glMultiDrawArraysIndirect, (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride)) \
    X(void, glInvalidateSubFramebuffer, (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height)) \
    X(void, glInvalidateFramebuffer, (GLenum target, GLsizei numAttachments, const GLenum *attachments)) \
    X(void, glInvalidateBufferData, (GLuint buffer)) \
    X(void, glInvalidateBufferSubData, (GLuint buffer, GLintptr offset, GLsizeiptr length)) \
    X(void, glInvalidateTexImage, (GLuint texture, GLint level)) \
    X(void, glInvalidateTexSubImage, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)) \
    X(void, glGetInternalformati64v, (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params)) \
    X(void, glGetFramebufferParameteriv, (GLenum target, GLenum pname, GLint *params)) \
    X(void, glFramebufferParameteri, (GLenum target, GLenum pname, GLint param)) \
    X(void, glCopyImageSubData, (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)) \
    X(void, glDispatchComputeIndirect, (GLintptr indirect)) \
    X(void, glDispatchCompute, (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)) \
    X(void, glClearBufferSubData, (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)) \
    X(void, glClearBufferData, (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data))

#define FOREACH_OPENGL_PROC_CORE_4_4(X) \
    X(void, glBindVertexBuffers, (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides)) \
    X(void, glBindImageTextures, (GLuint first, GLsizei count, const GLuint *textures)) \
    X(void, glBindSamplers, (GLuint first, GLsizei count, const GLuint *samplers)) \
    X(void, glBindTextures, (GLuint first, GLsizei count, const GLuint *textures)) \
    X(void, glBindBuffersRange, (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes)) \
    X(void, glBindBuffersBase, (GLenum target, GLuint first, GLsizei count, const GLuint *buffers)) \
    X(void, glClearTexSubImage, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data)) \
    X(void, glClearTexImage, (GLuint texture, GLint level, GLenum format, GLenum type, const void *data)) \
    X(void, glBufferStorage, (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags))

#define FOREACH_OPENGL_PROC_CORE_4_5(X) \
    X(void, glTextureBarrier, (void)) \
    X(void, glReadnPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data)) \
    X(void, glGetnUniformuiv, (GLuint program, GLint location, GLsizei bufSize, GLuint *params)) \
    X(void, glGetnUniformiv, (GLuint program, GLint location, GLsizei bufSize, GLint *params)) \
    X(void, glGetnUniformfv, (GLuint program, GLint location, GLsizei bufSize, GLfloat *params)) \
    X(void, glGetnUniformdv, (GLuint program, GLint location, GLsizei bufSize, GLdouble *params)) \
    X(void, glGetnTexImage, (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels)) \
    X(void, glGetnCompressedTexImage, (GLenum target, GLint lod, GLsizei bufSize, void *pixels)) \
    X(GLenum, glGetGraphicsResetStatus, (void)) \
    X(void, glGetCompressedTextureSubImage, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels)) \
    X(void, glGetTextureSubImage, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels)) \
    X(void, glMemoryBarrierByRegion, (GLbitfield barriers)) \
    X(void, glCreateQueries, (GLenum target, GLsizei n, GLuint *ids)) \
    X(void, glCreateProgramPipelines, (GLsizei n, GLuint *pipelines)) \
    X(void, glCreateSamplers, (GLsizei n, GLuint *samplers)) \
    X(void, glGetVertexArrayIndexed64iv, (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param)) \
    X(void, glGetVertexArrayIndexediv, (GLuint vaobj, GLuint index, GLenum pname, GLint *param)) \
    X(void, glGetVertexArrayiv, (GLuint vaobj, GLenum pname, GLint *param)) \
    X(void, glVertexArrayBindingDivisor, (GLuint vaobj, GLuint bindingindex, GLuint divisor)) \
    X(void, glVertexArrayAttribLFormat, (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)) \
    X(void, glVertexArrayAttribIFormat, (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)) \
    X(void, glVertexArrayAttribFormat, (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)) \
    X(void, glVertexArrayAttribBinding, (GLuint vaobj, GLuint attribindex, GLuint bindingindex)) \
    X(void, glVertexArrayVertexBuffers, (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides)) \
    X(void, glVertexArrayVertexBuffer, (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)) \
    X(void, glVertexArrayElementBuffer, (GLuint vaobj, GLuint buffer)) \
    X(void, glEnableVertexArrayAttrib, (GLuint vaobj, GLuint index)) \
    X(void, glDisableVertexArrayAttrib, (GLuint vaobj, GLuint index)) \
    X(void, glCreateVertexArrays, (GLsizei n, GLuint *arrays)) \
    X(void, glGetTextureParameteriv, (GLuint texture, GLenum pname, GLint *params)) \
    X(void, glGetTextureParameterIuiv, (GLuint texture, GLenum pname, GLuint *params)) \
    X(void, glGetTextureParameterIiv, (GLuint texture, GLenum pname, GLint *params)) \
    X(void, glGetTextureParameterfv, (GLuint texture, GLenum pname, GLfloat *params)) \
    X(void, glGetTextureLevelParameteriv, (GLuint texture, GLint level, GLenum pname, GLint *params)) \
    X(void, glGetTextureLevelParameterfv, (GLuint texture, GLint level, GLenum pname, GLfloat *params)) \
    X(void, glGetCompressedTextureImage, (GLuint texture, GLint level, GLsizei bufSize, void *pixels)) \
    X(void, glGetTextureImage, (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels)) \
    X(void, glBindTextureUnit, (GLuint unit, GLuint texture)) \
    X(void, glGenerateTextureMipmap, (GLuint texture)) \
    X(void, glTextureParameteriv, (GLuint texture, GLenum pname, const GLint *param)) \
    X(void, glTextureParameterIuiv, (GLuint texture, GLenum pname, const GLuint *params)) \
    X(void, glTextureParameterIiv, (GLuint texture, GLenum pname, const GLint *params)) \
    X(void, glTextureParameteri, (GLuint texture, GLenum pname, GLint param)) \
    X(void, glTextureParameterfv, (GLuint texture, GLenum pname, const GLfloat *param)) \
    X(void, glTextureParameterf, (GLuint texture, GLenum pname, GLfloat param)) \
    X(void, glCopyTextureSubImage3D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    X(void, glCopyTextureSubImage2D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    X(void, glCopyTextureSubImage1D, (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)) \
    X(void, glCompressedTextureSubImage3D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)) \
    X(void, glCompressedTextureSubImage2D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)) \
    X(void, glCompressedTextureSubImage1D, (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data)) \
    X(void, glTextureSubImage3D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)) \
    X(void, glTextureSubImage2D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)) \
    X(void, glTextureSubImage1D, (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels)) \
    X(void, glTextureStorage3DMultisample, (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)) \
    X(void, glTextureStorage2DMultisample, (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)) \
    X(void, glTextureStorage3D, (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)) \
    X(void, glTextureStorage2D, (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)) \
    X(void, glTextureStorage1D, (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width)) \
    X(void, glTextureBufferRange, (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizei size)) \
    X(void, glTextureBuffer, (GLuint texture, GLenum internalformat, GLuint buffer)) \
    X(void, glCreateTextures, (GLenum target, GLsizei n, GLuint *textures)) \
    X(void, glGetNamedRenderbufferParameteriv, (GLuint renderbuffer, GLenum pname, GLint *params)) \
    X(void, glNamedRenderbufferStorageMultisample, (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)) \
    X(void, glNamedRenderbufferStorage, (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height)) \
    X(void, glCreateRenderbuffers, (GLsizei n, GLuint *renderbuffers)) \
    X(void, glGetNamedFramebufferAttachmentParameteriv, (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params)) \
    X(void, glGetNamedFramebufferParameteriv, (GLuint framebuffer, GLenum pname, GLint *param)) \
    X(GLenum, glCheckNamedFramebufferStatus, (GLuint framebuffer, GLenum target)) \
    X(void, glBlitNamedFramebuffer, (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)) \
    X(void, glClearNamedFramebufferfi, (GLuint framebuffer, GLenum buffer, GLfloat depth, GLint stencil)) \
    X(void, glClearNamedFramebufferfv, (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value)) \
    X(void, glClearNamedFramebufferuiv, (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value)) \
    X(void, glClearNamedFramebufferiv, (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value)) \
    X(void, glInvalidateNamedFramebufferSubData, (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height)) \
    X(void, glInvalidateNamedFramebufferData, (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments)) \
    X(void, glNamedFramebufferReadBuffer, (GLuint framebuffer, GLenum src)) \
    X(void, glNamedFramebufferDrawBuffers, (GLuint framebuffer, GLsizei n, const GLenum *bufs)) \
    X(void, glNamedFramebufferDrawBuffer, (GLuint framebuffer, GLenum buf)) \
    X(void, glNamedFramebufferTextureLayer, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer)) \
    X(void, glNamedFramebufferTexture, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)) \
    X(void, glNamedFramebufferParameteri, (GLuint framebuffer, GLenum pname, GLint param)) \
    X(void, glNamedFramebufferRenderbuffer, (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)) \
    X(void, glCreateFramebuffers, (GLsizei n, GLuint *framebuffers)) \
    X(void, glGetNamedBufferSubData, (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data)) \
    X(void, glGetNamedBufferPointerv, (GLuint buffer, GLenum pname, void * *params)) \
    X(void, glGetNamedBufferParameteri64v, (GLuint buffer, GLenum pname, GLint64 *params)) \
    X(void, glGetNamedBufferParameteriv, (GLuint buffer, GLenum pname, GLint *params)) \
    X(void, glFlushMappedNamedBufferRange, (GLuint buffer, GLintptr offset, GLsizeiptr length)) \
    X(GLboolean, glUnmapNamedBuffer, (GLuint buffer)) \
    X(void *, glMapNamedBufferRange, (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)) \
    X(void *, glMapNamedBuffer, (GLuint buffer, GLenum access)) \
    X(void, glClearNamedBufferSubData, (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)) \
    X(void, glClearNamedBufferData, (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data)) \
    X(void, glCopyNamedBufferSubData, (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)) \
    X(void, glNamedBufferSubData, (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data)) \
    X(void, glNamedBufferData, (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage)) \
    X(void, glNamedBufferStorage, (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags)) \
    X(void, glCreateBuffers, (GLsizei n, GLuint *buffers)) \
    X(void, glGetTransformFeedbacki64_v, (GLuint xfb, GLenum pname, GLuint index, GLint64 *param)) \
    X(void, glGetTransformFeedbacki_v, (GLuint xfb, GLenum pname, GLuint index, GLint *param)) \
    X(void, glGetTransformFeedbackiv, (GLuint xfb, GLenum pname, GLint *param)) \
    X(void, glTransformFeedbackBufferRange, (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)) \
    X(void, glTransformFeedbackBufferBase, (GLuint xfb, GLuint index, GLuint buffer)) \
    X(void, glCreateTransformFeedbacks, (GLsizei n, GLuint *ids)) \
    X(void, glClipControl, (GLenum origin, GLenum depth))

#define FOREACH_OPENGL_PROC_FROM_CORE_1_2_TO_4_5(X) \
    FOREACH_OPENGL_PROC_CORE_1_4(X) \
    FOREACH_OPENGL_PROC_CORE_1_5(X) \
    FOREACH_OPENGL_PROC_CORE_2_0(X) \
    FOREACH_OPENGL_PROC_CORE_2_1(X) \
    FOREACH_OPENGL_PROC_CORE_3_0(X) \
    FOREACH_OPENGL_PROC_CORE_3_1(X) \
    FOREACH_OPENGL_PROC_CORE_3_2(X) \
    FOREACH_OPENGL_PROC_CORE_3_3(X) \
    FOREACH_OPENGL_PROC_CORE_4_0(X) \
    FOREACH_OPENGL_PROC_CORE_4_1(X) \
    FOREACH_OPENGL_PROC_CORE_4_2(X) \
    FOREACH_OPENGL_PROC_CORE_4_3(X) \
    FOREACH_OPENGL_PROC_CORE_4_4(X) \
    FOREACH_OPENGL_PROC_CORE_4_5(X)

#define FOREACH_OPENGL_PROC_FROM_CORE_UP_TO_4_5(X) \
    FOREACH_OPENGL_PROC_CORE_1_0(X) \
    FOREACH_OPENGL_PROC_CORE_1_1(X) \
    FOREACH_OPENGL_PROC_CORE_1_2(X) \
    FOREACH_OPENGL_PROC_CORE_1_3(X) \
    FOREACH_OPENGL_PROC_FROM_CORE_1_2_TO_4_5(X)

#define OPENGL_PROC_TYPE(NAME) \
    NAME##_Proc

#define DECLARE_TYPE(RETURN, PROC, ARGUMENTS) \
    typedef RETURN(*OPENGL_PROC_TYPE(PROC))ARGUMENTS;
FOREACH_OPENGL_PROC_FROM_CORE_1_2_TO_4_5(DECLARE_TYPE)
#undef DECLARE_TYPE

#define DECLARE_POINTER(RETURN, PROC, ARGUMENTS) \
    extern OPENGL_PROC_TYPE(PROC) PROC;
FOREACH_OPENGL_PROC_FROM_CORE_1_2_TO_4_5(DECLARE_POINTER)
#undef DECLARE_POINTER

#endif // OPENGL_H
