#ifndef BITMAP_H
#define BITMAP_H

#include <stdbool.h>
#include <stdint.h>

typedef struct Bitmap {
    uint8_t *pixels;
    uint32_t width;
    uint32_t height;
    uint8_t bytes_per_pixel;
} Bitmap;

bool bitmap_load(const void *data, int size, Bitmap *out_bitmap);

bool bitmap_load_from_path(const char *path, Bitmap *out_bitmap);

void bitmap_unload(Bitmap *bitmap);

#endif // BITMAP_H
