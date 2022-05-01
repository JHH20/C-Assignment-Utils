#include "debugging.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

// Log level = -1 for disabling all logging
// Otherwise, print all logging equal or greater than log level or -1
static const int _LOG_LVL = -1;
static bool _do_logging(int lvl) {
    return _LOG_LVL >= 0 && (lvl < 0 || lvl >= _LOG_LVL);
}

void logging(int lvl, char* format, ...) {
    if (!_do_logging(lvl)) return;

    fprintf(stderr, "[i] ");

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

// Always print unless log level = -1
void errlog(char* format, ...) {
    if (_do_logging(-1)) {
        fprintf(stderr, "[-] Error: ");

        va_list args;
        va_start(args, format);
        vfprintf(stderr, format, args);
        va_end(args);
    }

    exit(1);
}

void byteslog(int lvl, int n, char* arr) {
    if (!_do_logging(lvl)) return;

    fprintf(stderr, "[i] ");

    int i;
    for (i = 0; i < n; ++i) {
        fprintf(stderr, "%02x ", arr[i]);
        if (i % 16 == 15) fprintf(stderr, "\n    ");
        else if (i % 4 == 3) putc(' ', stderr);
    }
    if (i % 16 != 0) putc('\n', stderr);
}
