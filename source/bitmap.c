#include <inttypes.h>
#include <stdlib.h>

#include "bitmap.h"
#include "common.h"
#include "file.h"
#include "log.h"

#define BITMAP_SIGNATURE 0x4D42

#define BGRA_BLUE 0x000000FFU
#define BGRA_GREEN 0x0000FF00U
#define BGRA_RED 0x00FF0000U
#define BGRA_ALPHA 0xFF000000U

#define BITMAP_INFO_FIELDS \
    uint32_t size; \
    int32_t width; \
    int32_t height; \
    int16_t planes; \
    int16_t bits_per_pixel; \
    uint32_t compression; \
    uint32_t image_size; \
    uint32_t x_pixels_per_meter; \
    uint32_t y_pixels_per_meter; \
    uint32_t colors_used; \
    uint32_t colors_important

#define BITMAP_V2_FIELDS \
    BITMAP_INFO_FIELDS; \
    uint32_t red_mask; \
    uint32_t green_mask; \
    uint32_t blue_mask

#define BITMAP_V3_FIELDS \
    BITMAP_V2_FIELDS; \
    uint32_t alpha_mask

#define BITMAP_V4_FIELDS \
    BITMAP_V3_FIELDS; \
    uint32_t color_space; \
    int32_t end_points[9]; \
    uint32_t gamma_red; \
    uint32_t gamma_green; \
    uint32_t gamma_blue

#define BITMAP_V5_FIELDS \
    BITMAP_V4_FIELDS; \
    uint32_t intent; \
    uint32_t profile_data; \
    uint32_t profile_size; \
    uint32_t reserved_2

#if COMPILER_MSC
#   pragma pack(push, 1)
#endif

typedef struct PACKED_STRUCT() Bitmap_File_Header {
    int16_t signature;
    uint32_t file_size;
    int16_t reserved_0;
    int16_t reserved_1;
    uint32_t data_offset;
} Bitmap_File_Header;

typedef struct PACKED_STRUCT() Bitmap_Core_Header {
    uint32_t size;
    int16_t width;
    int16_t height;
    int16_t planes;
    int16_t bits_per_pixel;
} Bitmap_Core_Header;

typedef struct PACKED_STRUCT() Bitmap_V2_Header {
    BITMAP_V2_FIELDS;
} Bitmap_V2_Header;

typedef struct PACKED_STRUCT() Bitmap_Info_Header {
    BITMAP_INFO_FIELDS;
} Bitmap_Info_Header;

typedef struct PACKED_STRUCT() Bitmap_V3_Header {
    BITMAP_V3_FIELDS;
} Bitmap_V3_Header;

typedef struct PACKED_STRUCT() Bitmap_V4_Header {
    BITMAP_V4_FIELDS;
} Bitmap_V4_Header;

typedef struct PACKED_STRUCT() Bitmap_V5_Header {
    BITMAP_V5_FIELDS;
} Bitmap_V5_Header;

#if COMPILER_MSC
#   pragma pack(pop)
#endif

_Static_assert(sizeof(Bitmap_File_Header) == 14, "");
_Static_assert(sizeof(Bitmap_Core_Header) == 12, "");
_Static_assert(sizeof(Bitmap_Info_Header) == 40, "");
_Static_assert(sizeof(Bitmap_V2_Header) == 52, "");
_Static_assert(sizeof(Bitmap_V3_Header) == 56, "");
_Static_assert(sizeof(Bitmap_V4_Header) == 108, "");
_Static_assert(sizeof(Bitmap_V5_Header) == 124, "");

bool bitmap_load(const void *data, int size, Bitmap *out_bitmap) {
    int min_header_size = sizeof (Bitmap_File_Header) + sizeof (uint32_t);
    if (size < min_header_size) {
        LOG_ERROR("Provided data size is %d but a bitmap file must be at least %d bytes long.", size, min_header_size);
        return false;
    }

    const Bitmap_File_Header *file_header = (const Bitmap_File_Header *)data;
    if (file_header->signature != BITMAP_SIGNATURE) {
        LOG_ERROR("Incorrect bitmap signature: Expected " STRINGIFY(BITMAP_SIGNATURE) ", actual %" PRIx16 ".", file_header->signature);
        return false;
    }

    if ((int)file_header->file_size > size) {
        LOG_ERROR("Bitmap header specifies a file of %u bytes, but provided data is only %d bytes long.", file_header->file_size, size);
        return false;
    }

    uint32_t header_size = *(uint32_t *)&file_header[1];
    switch (header_size) {
    case 12:
        LOG_ERROR("Bitmap version core is not implemented.");
        return false;
    case 40:
        break;
    case 52:
        LOG_WARN("Bitmap version 2 is not fully implemented.");
        break;
    case 56:
        LOG_WARN("Bitmap version 3 is not fully implemented.");
        break;
    case 108:
        LOG_WARN("Bitmap version 4 is not fully implemented.");
        break;
    case 124:
        LOG_WARN("Bitmap version 5 is not fully implemented.");
        break;
    default:
        LOG_ERROR("Unrecognized bitmap header size: %u", header_size);
        return false;
    }

    const Bitmap_Info_Header *info_header = (Bitmap_Info_Header *)&file_header[1];

    uint8_t bytes_per_pixel = info_header->bits_per_pixel / 8;
    if (bytes_per_pixel != sizeof (uint32_t)) {
        LOG_ERROR("Bitmap info with 24 bits per pixel is not implemented.");
        return false;
    }

    uint32_t width = info_header->width;
    uint32_t height = (uint32_t)(info_header->height < 0 ? -info_header->height : info_header->height);

    int pixels_count = width * height;
    int pixels_bytes = pixels_count * bytes_per_pixel;

    uint8_t *destin = malloc(pixels_bytes);
    if (destin == NULL) {
        LOG_ERROR("Failed to allocate %d bytes to load the bitmap pixels.", pixels_bytes);
        return false;
    }

    const uint8_t *source = (uint8_t *)data + file_header->data_offset;
    int bytes_per_row = width * bytes_per_pixel;

    for (uint32_t row = 0; row < height; ++row) {
        uint32_t row_offset = info_header->height < 0 ? row : (height - 1 - row);

        const uint32_t *from = (uint32_t const *)(source + (row_offset * bytes_per_row));
        uint32_t *into = (uint32_t *)(destin + (row * bytes_per_row));

        for (uint32_t column = 0; column < width; ++column) {
            uint32_t bgra = *from++;
            uint32_t r = (bgra & BGRA_RED) >> 16;
            uint32_t g = bgra & BGRA_GREEN;
            uint32_t b = (bgra & BGRA_BLUE) << 16;
            uint32_t a = bgra & BGRA_ALPHA;
            *into++ = r | g | b | a;
        }
    }

    *out_bitmap = (Bitmap){
        .pixels = destin,
        .width = width,
        .height = height,
        .bytes_per_pixel = bytes_per_pixel,
    };
    return true;
}

bool bitmap_load_from_path(const char *path, Bitmap *out_bitmap) {
    File file = {0};
    if (!file_read(path, &file)) {
        return false;
    }

    bool loaded = bitmap_load((uint8_t *)file.data, file.size, out_bitmap);
    file_free(&file);
    return loaded;
}

void bitmap_unload(Bitmap *bitmap) {
    free(bitmap->pixels);
}
