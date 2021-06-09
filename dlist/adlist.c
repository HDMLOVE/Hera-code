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

/* removr all the elements from the list without destroying the list itself.*/
void listEmpty(list *list){
    unsigned long len;
    listNode *current, *next;

    len = list->len;
    while(len--){
        next = current->next;
        if(list->free)
            list->free(current->value);
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
    list->len = 0;

    return ;
}

/* free the whole list
 * This function can't failed
 * */
void listRelease(list *list){
    listEmpty(list);
    free(list);
    return;
}

/*
 * Add a new node to the list, to head, contaning the specified 'value'
 * pointer as value
 * On error, NULL is returned is performed (i.e. the
 * list remains unaltered)
 * On success the 'list' pointer you pass to the function is return.
 * */
list *listAddNodeHead(list *list, void *value){
    listNode *node;
    if ((node = malloc(sizeof(*node))) == NULL){
        return NULL;
    }
    node->value = value;
    if (list->len == 0){
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    }else{
        node->prev = NULL;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->lne++;
    return list;
}







