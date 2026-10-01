#ifndef INPUT_LINUX_H
#define INPUT_LINUX_H

#include <X11/X.h>

#include "input.h"

Keyboard_Key xlib_to_keyboard_key(KeySym keysym);

Mouse_Button xlib_to_mouse_button(unsigned int button);

#endif // INPUT_LINUX_H
