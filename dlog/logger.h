/******************************************
 * Filename : logger.h
 * Time     : 2021-06-20 06:08
 * Author   : 小骆
 * Dcription: 
*******************************************/

#ifndef HERA_CODE_LOGGER_H
#define HERA_CODE_LOGGER_H

enum logger_level{
    DEBUG,
    INFO,
    ERROR,
};

#define LOG(LEVEL, fmt...) log_func(level, __FILE__, __LINE__, fmt)

void log_func(
        enum logger_level level,
        const char *filename,
        const int line,
        const char *fmt, ...
        );

#endif
