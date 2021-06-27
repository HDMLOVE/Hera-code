/******************************************
 * Filename : 13.c
 * Time     : 2021-06-21 00:20
 * Author   : 小骆
 * Dcription: 
*******************************************/

#include "13.h"
#include <stdio.h>

#define ROW 3
#define COL 4

int main(int argc,  char *argv[]){

    int matrixA[ROW][COL], matrixB[COL][ROW];
    int i,j;

    printf("Enter elements of the matriA, ");
    printf("%d*%d:", ROW, COL);

    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            scanf("%d", &matrixA[i][j]);
        }
    }

    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            matrixB[j][i]=matrixA[i][j];
        }
    }
    printf("MatrixB, ");
    printf("%d*%d:\n", COL, ROW);
    for(i=0; i<COL; i++){
        for(j=0; j<ROW; j++){
            printf("%8d", matrixB[i][j]);
        }
        printf("\n");
    }
    printf("\n Press Any Key to Quit...\n");
    getchar();
    return 0;
}