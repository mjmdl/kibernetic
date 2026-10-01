#ifndef STRING_H
#define STRING_H

#include <stdbool.h>

char character_to_lower_case(char character);

int cstring_length(const char *string);

bool cstring_equal_no_case(const char *left, const char *right, int length);

void cstring_copy(const char *from, char *into, int length);

#endif // STRING_H
