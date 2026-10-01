#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include <errno.h>
#include <string.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "common.h"
#include "file.h"

bool file_read(char const *path, File *out_file) {
    int file = open(path, O_RDONLY);
    if (file < 0) {
        LOG_ERROR("Failed to open file %s: %s", path, strerror(errno));
        return false;
    }

    struct stat info = {0};
    if (fstat(file, &info) < 0) {
        LOG_ERROR("Failed to retrieve info about the file %s: %s", path, strerror(errno));
        close(file);
        return false;
    }

    char *data = mmap(NULL, info.st_size, PROT_READ, MAP_PRIVATE, file, 0);
    close(file);
    if (data == MAP_FAILED) {
        LOG_ERROR("Failed to read %zu bytes from file %s: %s", info.st_size, path, strerror(errno));
        return false;
    }

    *out_file = (File){
        .data = data,
        .size = info.st_size,
    };
    return true;
}

void file_free(File *file) {
    munmap(file->data, file->size);
}
