/******************************************
 * Filename : logger.c
 * Time     : 2021-06-20 06:08
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include "logger.h"
#include <stdio.h>
#include <stdarg.h>

void  log_func(enum logger_level level,
        const char *filename,
        const int line,
        const char *fmt,
        ...
        ){
    switch (level) {
        case DEBUG:
            fprintf(stderr, "[DEBUG] ");
            break;
        case INFO:
            fprintf(stderr, "[INFO]");
        case ERROR:
            fprintf(stderr, "[ERROR]");
            break;
    }
    fprintf(stderr, "%s:%d\n    ", filename, line);
    va_list va;
    va_start(va, fmt);
    vfprintf(stderr, fmt, va);
    va_end(va);
    fprintf(stderr, "\n");
}
