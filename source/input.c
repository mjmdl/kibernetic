#include "input.h"

bool input_key_down(Platform_Input const *input, Keyboard_Key key)
{
    if (key < 0 || key >= KEY_COUNT) {
        return false;
    }

    return input->keys[key] & INPUT_TRANSITION_DOWN;
}

bool input_key_pressed(Platform_Input const *input, Keyboard_Key key)
{
    if (key < 0 || key >= KEY_COUNT) {
        return false;
    }

    return input->keys[key] & INPUT_TRANSITION_PRESSED;
}

bool input_key_released(Platform_Input const *input, Keyboard_Key key)
{
    if (key < 0 || key >= KEY_COUNT) {
        return false;
    }

    return input->keys[key] & INPUT_TRANSITION_RELEASED;
}

bool input_button_down(Platform_Input const *input, Mouse_Button button)
{
    if (button < 0 || button >= BUTTON_COUNT) {
        return false;
    }

    return input->buttons[button] & INPUT_TRANSITION_DOWN;
}

bool input_button_pressed(Platform_Input const *input, Mouse_Button button)
{
    if (button < 0 || button >= BUTTON_COUNT) {
        return false;
    }

    return input->buttons[button] & INPUT_TRANSITION_PRESSED;
}

bool input_button_released(Platform_Input const *input, Mouse_Button button)
{
    if (button < 0 || button >= BUTTON_COUNT) {
        return false;
    }

    return input->buttons[button] & INPUT_TRANSITION_RELEASED;
}

float input_mouse_x(Platform_Input const *input)
{
    return input->mouse_x;
}

float input_mouse_y(Platform_Input const *input)
{
    return input->mouse_y;
}

float input_mouse_x_delta(Platform_Input const *input)
{
    return input->mouse_x_delta;
}

float input_mouse_y_delta(Platform_Input const *input)
{
    return input->mouse_y_delta;
}

float input_scroll(Platform_Input const *input)
{
    return input->scroll;
}
