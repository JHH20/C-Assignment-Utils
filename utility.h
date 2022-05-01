#ifndef UTILITY_H
#define UTILITY_H

#include <sys/types.h>
#include <stdio.h>

/* Wrap standard functions with helpful checks */

void *malloc_req(size_t size);

void *calloc_req(size_t count, size_t size);

void *realloc_req(void *ptr, size_t size);

FILE* fopen_req(const char *filename, const char *mode);

// glibc getline() but removing trailing newline
ssize_t readline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);

// buf_ptr is dynamically (re)-allocated and returns number of bytes or -1
ssize_t read_bfile(const char *filename, char **buf_ptr);

#endif
