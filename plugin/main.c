/******************************************
 * Filename : main.c
 * Time     : 2021-06-11 00:51
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include <stdio.h>
#include <dlfcn.h>

#include "register_plugins.h"

int main(int argc, char *argv[]){

    void *context = 0;
    context = dlopen("./libMath.so", RTLD_LAZY);
    if (NULL == context){
        log_error("dlopen error");
        return -1;
    }
    return 0;
}