#ifndef LOG_H
#define LOG_H

#include <stdio.h>

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

#endif // LOG_H
