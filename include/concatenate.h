#ifndef CONCATENATE_H
#define CONCATENATE_H

#include <stddef.h>

/* Buffer size constants */
enum {
    MAX_INPUT_SIZE = 100,
    MAX_RESULT_SIZE = 201
};

/**
 * Concatenate two strings with size limit
 * @param str1 First string (not NULL)
 * @param str2 Second string (not NULL)
 * @param n_bytes Maximum bytes to consider from each string
 * @return Pointer to concatenated result or NULL on error
 */
/*@null@*/ char* concatenate_data(const char* str1, const char* str2, size_t n_bytes);

#endif /* CONCATENATE_H */
