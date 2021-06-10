/******************************************
 * Filename : Math.h
 * Time     : 2021-06-11 00:44
 * Author   : 小骆
 * Dcription: 
*******************************************/

#ifndef HERA_CODE_MATH_H
#define HERA_CODE_MATH_H

#define _DEBUG
#ifndef _DEBUG
    #define log_debug(format, ...) printf("[DEBUG][func:%s line:%d ]"format"\n", __FUNCTION__, __LINE__, ##__VA_ARGS__);
    #define log_info(format,  ...) printf("[INFO ][func:%s line:%d ]"format"\n", __FUNCTION__, __LINE__, ##__VA_ARGS__);
    #define log_error(format, ...) printf("[ERROR][func:%s line:%d ]"format"\n", __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
    #define log_debug(format, ...)
    #define log_info(format, ...)
    #define log_error(format, ...)
#endif

#endif
