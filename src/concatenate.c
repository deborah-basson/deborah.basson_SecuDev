#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "concatenate.h"

/* Manual implementation of strnlen for splint compatibility */
static size_t safe_strnlen(const char* str, size_t maxlen) {
    size_t len = 0;
    while (len < maxlen && str[len] != '\0') {
        len++;
    }
    return len;
}

char* concatenate_data(const char* str1, const char* str2, size_t n_bytes) {
    static char result[MAX_RESULT_SIZE];

    /* Check for NULL pointers */
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    /* Validate n_bytes */
    if (n_bytes == 0 || n_bytes > MAX_INPUT_SIZE) {
        return NULL;
    }

    size_t len1 = safe_strnlen(str1, n_bytes);
    size_t len2 = safe_strnlen(str2, n_bytes);

    /* Check for overflow */
    if (len1 + len2 >= MAX_RESULT_SIZE) {
        return NULL;
    }

    /* Manually copy strings */
    size_t idx = 0;
    size_t i;

    /* Copy first string */
    for (i = 0; i < len1 && idx < MAX_RESULT_SIZE - 1; i++) {
        result[idx] = str1[i];
        idx++;
    }

    /* Copy second string */
    for (i = 0; i < len2 && idx < MAX_RESULT_SIZE - 1; i++) {
        result[idx] = str2[i];
        idx++;
    }

    result[idx] = '\0';

    return result;
}
