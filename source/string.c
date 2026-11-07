#include "string.h"

char character_to_lower_case(char character)
{
    if (character >= 'A' && character <= 'Z') {
        return character + ('a' - 'A');
    }

    return character;
}

int cstring_length(const char *string)
{
    int i = 0;
    while (string[i] != '\0') {
        ++i;
    }
    return i;
}

bool cstring_equal_no_case(const char *left, const char *right, int length)
{
    for (int i = 0; i < length; ++i) {
        if (character_to_lower_case(left[i]) != character_to_lower_case(right[i])) {
            return false;
        }

        if (left[i] == '\0') {
            return true;
        }
    }

    return true;
}

void cstring_copy(const char *from, char *into, int length)
{
    for (int i = 0; i < length; ++i) {
        into[i] = from[i];
    }

    into[length] = '\0';
}
