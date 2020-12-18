#include <stdio.h>
#include "ChessLib.h"

int main() {
    int i;
    int **board = createChessTable();
    printChessTable(board);
    
    struct Poz fav;
    fav.dusey = 2;
    fav.yatay = 'd';
    //char tas = 's';
    
    
    struct Poz *possiblePositions = hareketSah(fav);
    for (i = 0; i < 8; i++) {
        printf("possible pos. number %d : %c %d\n",i+1,possiblePositions[i].yatay,possiblePositions[i].dusey);
    }
    
    printf("\n\n--------------------\n\n");
    
    possiblePositions = hareketPiyon(fav);
    for (i = 0; i < 2; i++) {
        if(!(possiblePositions[i].yatay==0)){
            printf("possible pos. number %d : %c %d\n",i+1,possiblePositions[i].yatay,possiblePositions[i].dusey);
            //printf("the arr. of pos. pos. has just 1 value");
        }
    }
    
    printf("\n\n--------------------\n\n");
    
    
    
    
    return 0;
}
