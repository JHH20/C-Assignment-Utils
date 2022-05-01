#include "str_utility.h"

#include <string.h>
#include <stdbool.h>

#include "utility.h"

char* str_clone(char* str) {
    size_t len = strlen(str) + 1; // Count terminating null byte
    char* result = malloc_req(sizeof(char) * len);
    strcpy(result, str);
    return result;
}

// Split string by delim in-place, maxsplit < 0 for unlimited
size_t str_split(char*** tokens_ptr, char* str, char delim, int maxsplit) {
    size_t count = 0;
    size_t str_len = strlen(str);

    char* token_start = str;
    for(int i = 0; i < str_len && (count < maxsplit || maxsplit < 0); ++i)
    {
        if (str[i] == delim)
        {
            ++count;
            *tokens_ptr = (char**) realloc_req(*tokens_ptr, sizeof(char*) * count);

            (*tokens_ptr)[count - 1] = token_start;
            token_start = &(str[i + 1]);
            str[i] = '\0';
        }
    }

    // Last token processing
    ++count;
    *tokens_ptr = (char**) realloc_req(*tokens_ptr, sizeof(char*) * count);
    (*tokens_ptr)[count - 1] = token_start;

    return count;
}

// Check if str starts with prefix
bool str_prefix(char* str, char* prefix) {
    return strncmp(prefix, str, strlen(prefix)) == 0;
}

char* str_join(char* str1, char* str2) {
    // Reference: https://stackoverflow.com/a/8465083
    char* result = malloc_req(strlen(str1) + strlen(str2) + 1);
    strcpy(stpcpy(result, str1), str2);
    return result;
}
