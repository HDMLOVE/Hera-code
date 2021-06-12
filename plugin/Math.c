/******************************************
 * Filename : Math.c
 * Time     : 2021-06-11 00:44
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include "Math.h"
#include "register_plugins.h"

int twoSum(int a, int b){
    return a+b+10;
}

void clean(void){
    return;
}

register_plugin_fn(Math, twoSum, clean);