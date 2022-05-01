#ifndef DEBUGGING_H
#define DEBUGGING_H

#include <stdio.h>

// Convert stdbool into string
#define str_bool(b) (b ? "true" : "false")

void logging(int lvl, char* format, ...);

void errlog(char* format, ...);

void byteslog(int lvl, int n, char* arr);

#endif
