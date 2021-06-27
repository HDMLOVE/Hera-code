/******************************************
 * Filename : 4.c
 * Time     : 2021-06-20 06:37
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include <stdio.h>

#include "4.h"


int main(int argc, char * argv[]){

    float x, y, c;
    printf("please input x and y:\n");
    scanf("%f%f", &x, &y);
    c = x>y?x:y;
    printf("Max of (%f, %f) is %f\n", x, y, c);

    return 0;
}
