#define _GNU_SOURCE

#include "utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugging.h"

void *malloc_req(size_t size) {
    void *result = malloc(size);
    if (result == NULL)
    {
        errlog("malloc failed!\n");
    }

    return result;
}

void *calloc_req(size_t count, size_t size) {
    void *result = calloc(count, size);
    if (result == NULL)
    {
        errlog("calloc failed!\n");
    }

    return result;
}

void *realloc_req(void *ptr, size_t size) {
    void *result = realloc(ptr, size);
    if (result == NULL)
    {
        errlog("realloc failed!\n");
    }

    return result;
}

FILE* fopen_req(const char *filename, const char *mode) {
    FILE* fp = fopen(filename, mode);
    if (fp == NULL)
    {
        errlog("fopen(%s, %s) failed!\n", filename, mode);
    }

    return fp;
}

// returns number of chars read before stripping or -1 on failure / EoF
ssize_t readline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream) {
    ssize_t result = getline(lineptr, n, stream);
    (*lineptr)[strcspn(*lineptr, "\n")] = '\0';

    return result;
}

ssize_t read_bfile(const char *filename, char **buf_ptr) {
    // Reference: https://stackoverflow.com/a/22059317
    FILE* fp = fopen_req(filename, "rb");
    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    rewind(fp);

    *buf_ptr = realloc_req(*buf_ptr, len * sizeof(char));
    size_t result = fread(*buf_ptr, 1, len, fp);
    int err = ferror(fp);
    fclose(fp);

    if (err != 0 || result != len)
        errlog("readfile(%s) failed! read %ld / %ld bytes\n", filename, result, len);

    return result;
}
