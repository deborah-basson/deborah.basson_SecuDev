#include <string.h>
#include <stdio.h>
#include "concatenate.h"

char* concatenate_data(const char* str1, const char* str2, size_t n_bytes) {
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    static char result[201];
    size_t len1 = strnlen(str1, n_bytes);
    size_t len2 = strnlen(str2, n_bytes);

    if (len1 + len2 >= sizeof(result)) {
        return NULL;
    }

    strncpy(result, str1, n_bytes);
    result[len1] = '\0';
    strncat(result, str2, n_bytes);

    return result;
}
