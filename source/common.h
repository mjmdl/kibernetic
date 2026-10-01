#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

#define ARRAY_LENGTH(ARRAY) \
    (sizeof(ARRAY) / sizeof((ARRAY)[0]))

#define GREATEST(A, B) \
    ((A) > (B) ? (A) : (B))

#define LEAST(A, B) \
    ((A) > (B) ? (B) : (A))

#define CLAMP(X, MIN, MAX) \
    GREATEST((MIN), LEAST((MAX), (X)))

#define LOG_MESSAGE(STREAM, LEVEL, ...) \
    do { \
        fprintf(STREAM, LEVEL ": " __VA_ARGS__); \
        fputc('\n', STREAM); \
    } while (0)

#define LOG_DEBUG(...) \
    LOG_MESSAGE(stdout, "DEBUG", __VA_ARGS__)

#define LOG_INFO(...) \
    LOG_MESSAGE(stdout, "INFO", __VA_ARGS__)

#define LOG_WARN(...) \
    LOG_MESSAGE(stderr, "WARN", __VA_ARGS__)

#define LOG_ERROR(...) \
    LOG_MESSAGE(stderr, "ERROR", __VA_ARGS__)

#endif // COMMON_H
