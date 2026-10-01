#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include <stddef.h>

#include "input.h"

typedef struct Platform_Window Platform_Window;

Platform_Window *window_create(void);

void window_destroy(Platform_Window *window);

void window_poll_events(Platform_Window *window);

void window_swap_buffers(Platform_Window *window);

bool window_should_close(const Platform_Window *window);

void window_set_should_close(Platform_Window *window, bool should_close);

void window_position(const Platform_Window *window, int *out_x, int *out_y);

void window_set_position(Platform_Window *window, int x, int y);

void window_move_to_center(Platform_Window *window);

void window_dimensions(const Platform_Window *window, int *out_width, int *out_height);

void window_set_dimensions(Platform_Window *window, int width, int height);

void window_screen_dimensions(const Platform_Window *window, int *out_width, int *out_height);

const char *window_title(const Platform_Window *window);

void window_set_title(Platform_Window *window, const char *title);

bool window_cursor_locked(const Platform_Window *window);

void window_set_cursor_locked(Platform_Window *window, bool cursor_locked);

const Platform_Input *window_input(const Platform_Window *window);

#endif // WINDOW_H
