#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "concatenate.h"

#define MAX_RESULT_SIZE 201

char* concatenate_data(const char* str1, const char* str2, size_t n_bytes) {
    static char result[MAX_RESULT_SIZE];

    /* Check for NULL pointers */
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    /* Validate n_bytes */
    if (n_bytes == 0 || n_bytes > 100) {
        return NULL;
    }

    size_t len1 = strnlen(str1, n_bytes);
    size_t len2 = strnlen(str2, n_bytes);

    /* Check for overflow */
    if (len1 + len2 >= MAX_RESULT_SIZE) {
        return NULL;
    }

    /* Copy first string */
    (void)strncpy(result, str1, len1);
    result[len1] = '\0';

    /* Concatenate second string */
    (void)strncat(result, str2, len2);

    return result;
}
