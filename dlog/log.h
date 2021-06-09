/******************************************
 * Filename : log.h
 * Time     : 2021-06-10 01:00
 * Author   : 小骆
 * Dcription: 
*******************************************/

#ifndef HERA_CODE_LOG_H
#define HERA_CODE_LOG_H

#define _DEBUG  /* 日志模块的总开关，注释掉将会关闭日志输出 */

#ifdef _DEBUG
    #define _log_debug(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define _log_debug(format, ...)
#endif

/*
 * define the log level
 * */
enum LOG_LEVEL{
    LOG_LEVEL_OFF = 0,
    LOG_LEVEL_DEBUG = 20,
    LOG_LEVEL_WARNING = 40,
    LOG_LEVEL_INFO = 60,
    LOG_LEVEL_ERROR = 80,
    LOG_LEVEL_FATAL = 100
};

#define log_debug(farmat, ...) \
        do{                    \
        _log_debug("[DEBUG] file:%s func:%s line:%d"farmat"\n", \
        __func__, __FILE__, __LINE__, ##__VA_ARGS__);           \
        }while(0);

#define log_warn(farmat, ...) \
        do{                    \
        _log_debug("[WARN ] file:%s func:%s line:%d"farmat"\n", \
        __func__, __FILE__, __LINE__, ##__VA_ARGS__);           \
        }while(0);

#define log_info(farmat, ...) \
        do{                    \
        _log_debug("[INFO] file:%s func:%s line:%d"farmat"\n", \
        __func__, __FILE__, __LINE__, ##__VA_ARGS__);           \
        }while(0);

#define log_error(farmat, ...) \
        do{                    \
        _log_debug("[ERROR] file:%s func:%s line:%d"farmat"\n", \
        __func__, __FILE__, __LINE__, ##__VA_ARGS__);           \
        }while(0);

#define log_fatal(farmat, ...) \
        do{                    \
        _log_debug("[FATAL] file:%s func:%s line:%d"farmat"\n", \
        __func__, __FILE__, __LINE__, ##__VA_ARGS__);           \
        }while(0);
#endif
