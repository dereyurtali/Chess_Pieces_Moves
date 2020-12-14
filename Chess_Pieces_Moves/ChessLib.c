#include "ChessLib.h"
#include <stdio.h>
#include <stdlib.h>

int **createChessTable(){
    int i, j;
    int **table = (int **)calloc(8, sizeof(int *));
    for (i = 0; i < 8; i++) {
        table[i] = (int *)calloc(sizeof(int), 8);
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            table[i][j] = 0;
        }
    }
    return table;
}

void printChessTable(int **table){
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d\t",table[i][j]);
        }
        puts("");
    }
    
}
