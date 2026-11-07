#ifndef FILE_H
#define FILE_H

#include <stdbool.h>

typedef struct File {
    char *data;
    int size;
} File;

bool file_read(const char *path, File *out_file);

void file_free(File *file);

#endif // FILE_H
