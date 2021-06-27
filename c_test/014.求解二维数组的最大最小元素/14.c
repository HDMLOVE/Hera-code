/******************************************
 * Filename : 14.c
 * Time     : 2021-06-21 00:38
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include "14.h"
#include <stdio.h>

int main(){
    int min, max;

    int row,col,n;
    /* 输入方阵的阶次 */
    printf("Please input the order of matrix:\n");
    scanf("%d", &n);
    printf("Please input the elements of matrix, \n from a[0][0] to [%d][%d]\n", n-1, n-1);
    for (row=0; row<n; row++){
        for(col=0; col<n; col++){
            scanf("%d", &a[row][col]);
        }
    }

    return 0;
}