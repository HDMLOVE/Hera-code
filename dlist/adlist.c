/******************************************
 * Filename : adlist.c
 * Time     : 2021-06-09 02:09
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include <stdio.h>

#include "adlist.h"

list *listCreate(void ){
    struct list *list;
    list = malloc(sizeof(*list));
    if(NULL == list){
        return NULL;
    }
    list->head = list->tail = NULL;
    list->len = 0;
    list->dup = NULL;
    list->free = NULL;
    list->match = NUll;
    
    return list;
}
