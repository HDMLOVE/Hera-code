/******************************************
 * Filename : adlist.h
 * Time     : 2021-06-09 02:09
 * Author   : 小骆
 * Dcription: 
*******************************************/

#ifndef HERA_CODE_ADLIST_H
#define HERA_CODE_ADLIST_H

/* 链表节点结构体 */
typedef struct listNode{
    struct listNode *prev;
    struct listNode *next;
    void *value;
}listNode;

/* 迭代器 */
typedef struct listIter{
    listNode *next;
    int direction;
}listIter;

typedef struct list{
    listNode *head;
    listNode *tail;
    void *(*dup)(void *ptr);
    void *(*free)(void *ptr);
    int  *(*match)(void *ptr, void *key);
    unsigned long len;
}list;

/* 作为宏定义实现的函数 */
#define listLength(l)   ((l)->len)
#define listFirst(l)    ((l)->head)
#define listLast(l)     ((l)->tail)


#endif
