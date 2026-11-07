#ifndef COMMON_H
#define COMMON_H

#if defined(__linux__)
#   define PLATFORM_LINUX 1
#elif defined(_WIN32)
#   define PLATFORM_WINDOWS 1
#endif
#if !defined(PLATFORM_LINUX)
#   define PLATFORM_LINUX 0
#endif
#if !defined(PLATFORM_WINDOWS)
#   define PLATFORM_WINDOWS 0
#endif

#if defined(__clang__)
#   define COMPILER_CLANG 1
#elif defined(__GNUC__)
#   define COMPILER_GCC 1
#elif defined(_MSC_VER)
#   define COMPILER_MSC 1
#endif
#if !defined(COMPILER_CLANG)
#   define COMPILER_CLANG 0
#endif
#if !defined(COMPILER_GCC)
#   define COMPILER_GCC 0
#endif
#if !defined(COMPILER_MSC)
#   define COMPILER_MSC 0
#endif

#define STRINGIFY_INNER(EXPR) \
    #EXPR
#define STRINGIFY(EXPR) \
    STRINGIFY_INNER(EXPR)

#define ARRAY_LENGTH(ARRAY) \
    (sizeof(ARRAY) / sizeof((ARRAY)[0]))

#define GREATEST(A, B) \
    ((A) > (B) ? (A) : (B))

#define LEAST(A, B) \
    ((A) > (B) ? (B) : (A))

#define CLAMP(X, MIN, MAX) \
    GREATEST((MIN), LEAST((MAX), (X)))

#if COMPILER_GCC || COMPILER_CLANG
#   define PACKED_STRUCT() \
        __attribute__((packed))
#endif
#if !defined(PACKED_STRUCT)
#   define PACKED_STRUCT()
#endif

#endif // COMMON_H
