#ifndef CONCATENATE_H
#define CONCATENATE_H

#include <stddef.h>

/**
 * Concatenate two strings with size limit
 * @param str1 First string (not NULL)
 * @param str2 Second string (not NULL)
 * @param n_bytes Maximum bytes to consider from each string
 * @return Pointer to concatenated result or NULL on error
 */
/*@null@*/ /*@dependent@*/
char* concatenate_data(/*@null@*/ const char* str1,
                       /*@null@*/ const char* str2,
                       size_t n_bytes)
    /*@modifies nothing@*/;

#endif /* CONCATENATE_H */
