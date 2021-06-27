/******************************************
 * Filename : 41.h
 * Time     : 2021-06-24 00:38
 * Author   : 小骆
 * Dcription: 
*******************************************/

#ifndef HERA_CODE_41_H
#define HERA_CODE_41_H

#define SWN 3 //课程数
#define NAMELEN 20
#define CODELEN 10
#define FNAMELEN 80
#define BUFLEN 80


struct record{
    char name[NAMELEN+1];
    char code[CODELEN+1];
    int  masrk[SWN];
    int  total;
}stu;

struct node{
    char name[NAMELEN+1];
    char code[CODELEN+1];
    int masks[SWN];         //各个课程的成绩
    int total;              //总分
    struct node *next;      //后继指针
}*head;

#endif
