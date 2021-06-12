/******************************************
 * Filename : log.h
 * Time     : 2021-06-12 15:30
 * Author   : 小骆
 * Dcription: 
*******************************************/

#ifndef HERA_CODE_LOG_H
#define HERA_CODE_LOG_H

#define _DEBUG
#ifdef _DEBUG
#define log_debug(format, ...) printf("[\033[1;32;40mDEBUG\033[0m][%s,%s,%d] "format"\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define log_info(format,  ...) printf("[\033[1;33;40mINFO \033[0m][%s,%s,%d] "format"\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define log_error(format, ...) printf("[\033[1;31;40mERROR\033[0m][%s,%s,%d] "format"\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define log_debug(format, ...)
#define log_info(format, ...)
#define log_error(format, ...)
#endif

#endif
