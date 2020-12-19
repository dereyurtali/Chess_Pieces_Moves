#include <stdio.h>
#include "ChessLib.h"

int main() {
    int i;
    //int **board = createChessTable();
    //printChessTable(board);
    
    struct Poz fav;
    fav.dusey = 'e';
    fav.yatay = 4;
    //char tas = 's';
    
    
    struct Poz *possiblePositions = hareketSah(fav);
    printf("\n\n--------SAH----------\n");
    for (i = 0; i < 8; i++) {
        printf("possible pos. number %d : %c %d\n",i+1,possiblePositions[i].dusey,possiblePositions[i].yatay);
    }
    
    printf("\n\n--------------------\n\n");
    printf("\n\n--------PIYON----------\n");
    possiblePositions = hareketPiyon(fav);
    for (i = 0; i < 2; i++) {
        if(!(possiblePositions[i].yatay==0)){
     printf("possible pos. number %d : %c %d\n",i+1,possiblePositions[i].dusey,possiblePositions[i].yatay);
            //printf("the arr. of pos. pos. has just 1 value");
        }
    }
    
    printf("\n\n--------------------\n\n");
    printf("\n\n--------KALE----------\n");
    possiblePositions = hareketKale(fav);
    for (i = 0; i < 14; i++) {
     printf("possible pos. number %d : %c %d\n",i+1,possiblePositions[i].dusey,possiblePositions[i].yatay);
        //printf("the arr. of pos. pos. has just 1 value");
    }
    
    printf("\n\n--------------------\n\n");
    printf("\n\n--------FIL----------\n");
    possiblePositions = hareketFil(fav);
    for (i = 0; i < 13; i++) {
     printf("possible pos. number %d : %c %d\n",i+1,possiblePositions[i].dusey,possiblePositions[i].yatay);
        //printf("the arr. of pos. pos. has just 1 value");
    }

    printf("\n\n--------------------\n\n");
    printf("\n\n--------VEZIR----------\n");
    possiblePositions = hareketVezir(fav);
    for (i = 0; i < 27; i++) {
     printf("possible pos. number %d : %c %d\n",i+1,possiblePositions[i].dusey,possiblePositions[i].yatay);
        //printf("the arr. of pos. pos. has just 1 value");
    }
    

    
    printf("\n\n--------------------\n\n");
    printf("\n\n--------AT----------\n");
    possiblePositions = hareketAt(fav);
   
    for (i = 0; i < 8; i++) {
     printf("possible pos. number %d : %c %d\n",i+1,possiblePositions[i].dusey,possiblePositions[i].yatay);
    }
    
    return 0;
}
