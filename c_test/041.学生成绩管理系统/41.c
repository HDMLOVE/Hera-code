/******************************************
 * Filename : 41.c
 * Time     : 2021-06-24 00:38
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include "41.h"

/* 程程表名称 */
char schoolwork[SWN][NAMELEN+1] = {"Chinese", "Mathematic", "English"};

int total[SWN];         //总分
FILE *stfpt;            //文件指针
char stuf[FNAMELEN];    //文件名


int readrecord(FILE *fpt, struct record *rpt){
    char buf[BUFLEN];
    int i;
    if(fscanf(fpt, "%s", buf) != 1){
        return 0;   //文件结束
    }
    strncpy(rpt->name, buf, NAMELEN);

    return 0;
}

int main(int argc, char *argv[]){

}