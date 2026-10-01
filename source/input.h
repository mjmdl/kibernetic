#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <stdint.h>

typedef enum Keyboard_Key {
    KEY_NONE = 0,
    KEY_ESCAPE,
    KEY_ENTER,
    KEY_BACKSPACE,
    KEY_TAB,
    KEY_CAPS_LOCK,
    KEY_SPACE,
    KEY_LEFT_SHIFT,
    KEY_RIGHT_SHIFT,
    KEY_LEFT_CTRL,
    KEY_RIGHT_CTRL,
    KEY_LEFT_ALT,
    KEY_RIGHT_ALT,
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_PAD_0,
    KEY_PAD_1,
    KEY_PAD_2,
    KEY_PAD_3,
    KEY_PAD_4,
    KEY_PAD_5,
    KEY_PAD_6,
    KEY_PAD_7,
    KEY_PAD_8,
    KEY_PAD_9,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_COUNT,
} Keyboard_Key;

typedef enum Mouse_Button {
    BUTTON_NONE = 0,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_MIDDLE,
    BUTTON_FORWARD,
    BUTTON_BACKWARD,
    BUTTON_COUNT,
} Mouse_Button;

typedef enum Input_Transition {
    INPUT_TRANSITION_DOWN     = 0x1,
    INPUT_TRANSITION_PRESSED  = 0x2,
    INPUT_TRANSITION_RELEASED = 0x4,
} Input_Transition;

typedef uint8_t Input_Transitions;

typedef struct Platform_Input {
    Input_Transitions keys[KEY_COUNT];
    Input_Transitions buttons[BUTTON_COUNT];
    float mouse_x;
    float mouse_y;
    float mouse_x_delta;
    float mouse_y_delta;
    float scroll;
} Platform_Input;

bool input_key_down(const Platform_Input *input, Keyboard_Key key);

bool input_key_pressed(const Platform_Input *input, Keyboard_Key key);

bool input_key_released(const Platform_Input *input, Keyboard_Key key);

bool input_mouse_down(const Platform_Input *input, Mouse_Button button);

bool input_mouse_pressed(const Platform_Input *input, Mouse_Button button);

bool input_mouse_released(const Platform_Input *input, Mouse_Button button);

float input_mouse_x(const Platform_Input *input);

float input_mouse_y(const Platform_Input *input);

float input_mouse_x_delta(const Platform_Input *input);

float input_mouse_y_delta(const Platform_Input *input);

float input_scroll(const Platform_Input *input);

#endif // INPUT_H
