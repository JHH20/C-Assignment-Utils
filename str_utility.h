#ifndef STR_UTILITY_H
#define STR_UTILITY_H

#include <string.h>
#include <stdbool.h>

// Convert stdbool into string
#define str_bool(b) (b ? "true" : "false")

// return dynamically allocated copy of string
char* str_clone(char* str);

// *tokens_ptr is dynamically (re)-allocated and *str is mutated
size_t str_split(char*** tokens_ptr, char* str, char delim, int maxsplit);

bool str_prefix(char* str, char* prefix);

// return dynamically allocated string
char* str_join(char* str1, char* str2);

#endif
