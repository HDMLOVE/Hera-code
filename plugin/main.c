/******************************************
 * Filename : main.c
 * Time     : 2021-06-11 00:51
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include <stdio.h>
#include <dlfcn.h>

#include "register_plugins.h"
#include "log.h"

int main(int argc, char *argv[]){

    void *context = 0;
    context = dlopen("./libMath.so", RTLD_LAZY);
    if (NULL == context){
        log_error("dlopen error");
        return -1;
    }

    typedef struct mod_private* (*fun)(void);
    fun md = 0;
    /* 根据动态链接操作句柄与符号，返回符号对应的地址 */
    md = (fun)dlsym(context, "register_declare_Math");
    if(md == NULL){
        log_error("dlsym error");
        return -1;
    }
    struct mod_private *sum;
    sum = md();
    log_debug("func:%d", sum->init(0, 0));
    return 0;
}
