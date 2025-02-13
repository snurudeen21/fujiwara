#include "shell.h"

int valid_double(char *str)
{
    if (str == NULL || *str == '\0') {
        return 0;  // ❌ Empty or NULL input is invalid
    }

    char *endptr;
    double value1 = strtod(str, &endptr);

    // ❌ Check if conversion failed (strtod() couldn't parse a number)
    if (str == endptr) {
        return 0;  
    }

    // ❌ Flag exact zero ("0" or "0.0")
    if (value1 == 0.0) {
        return -1;  // Special flag for zero
    }

    // ❌ Check if any extra invalid characters exist
    while (*endptr != '\0' && *endptr != '\n') {
        if (!isspace((unsigned char)*endptr)) {
            return 0;  // ❌ Invalid: Extra non-numeric characters
        }
        endptr++;
    }

    return 1;  // ✅ Valid floating-point number
}