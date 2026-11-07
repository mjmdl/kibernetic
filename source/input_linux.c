#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "input_linux.h"

Keyboard_Key xlib_to_keyboard_key(KeySym keysym)
{
    switch (keysym) {
    case XK_Escape:
        return KEY_ESCAPE;
    case XK_Return:
        return KEY_ENTER;
    case XK_BackSpace:
        return KEY_BACKSPACE;
    case XK_Tab:
        return KEY_TAB;
    case XK_Caps_Lock:
        return KEY_CAPS_LOCK;
    case XK_space:
        return KEY_SPACE;
    case XK_Shift_L:
        return KEY_LEFT_SHIFT;
    case XK_Shift_R:
        return KEY_RIGHT_SHIFT;
    case XK_Control_L:
        return KEY_LEFT_CTRL;
    case XK_Control_R:
        return KEY_RIGHT_CTRL;
    case XK_Alt_L:
        return KEY_LEFT_ALT;
    case XK_Alt_R:
        return KEY_RIGHT_ALT;
    case XK_0:
        return KEY_0;
    case XK_1:
        return KEY_1;
    case XK_2:
        return KEY_2;
    case XK_3:
        return KEY_3;
    case XK_4:
        return KEY_4;
    case XK_5:
        return KEY_5;
    case XK_6:
        return KEY_6;
    case XK_7:
        return KEY_7;
    case XK_8:
        return KEY_8;
    case XK_9:
        return KEY_9;
    case XK_KP_0:
        return KEY_PAD_0;
    case XK_KP_1:
        return KEY_PAD_1;
    case XK_KP_2:
        return KEY_PAD_2;
    case XK_KP_3:
        return KEY_PAD_3;
    case XK_KP_4:
        return KEY_PAD_4;
    case XK_KP_5:
        return KEY_PAD_5;
    case XK_KP_6:
        return KEY_PAD_6;
    case XK_KP_7:
        return KEY_PAD_7;
    case XK_KP_8:
        return KEY_PAD_8;
    case XK_KP_9:
        return KEY_PAD_9;
    case XK_a:
        return KEY_A;
    case XK_b:
        return KEY_B;
    case XK_c:
        return KEY_C;
    case XK_d:
        return KEY_D;
    case XK_e:
        return KEY_E;
    case XK_f:
        return KEY_F;
    case XK_g:
        return KEY_G;
    case XK_h:
        return KEY_H;
    case XK_i:
        return KEY_I;
    case XK_j:
        return KEY_J;
    case XK_k:
        return KEY_K;
    case XK_l:
        return KEY_L;
    case XK_m:
        return KEY_M;
    case XK_n:
        return KEY_N;
    case XK_o:
        return KEY_O;
    case XK_p:
        return KEY_P;
    case XK_q:
        return KEY_Q;
    case XK_r:
        return KEY_R;
    case XK_s:
        return KEY_S;
    case XK_t:
        return KEY_T;
    case XK_u:
        return KEY_U;
    case XK_v:
        return KEY_V;
    case XK_w:
        return KEY_W;
    case XK_x:
        return KEY_X;
    case XK_y:
        return KEY_Y;
    case XK_z:
        return KEY_Z;
    default:
        return KEY_NONE;
    }
}

Mouse_Button xlib_to_mouse_button(unsigned int button)
{
    switch (button) {
    case Button1:
        return BUTTON_LEFT;
    case Button2:
        return BUTTON_MIDDLE;
    case Button3:
        return BUTTON_RIGHT;
    case 6:
        return BUTTON_FORWARD;
    case 7:
        return BUTTON_BACKWARD;
    default:
        return BUTTON_NONE;
    }
}
