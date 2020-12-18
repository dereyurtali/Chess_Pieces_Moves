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
    }return table;
}

void printChessTable(int **table){
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d\t",table[i][j]);
        }
        printf("\n\n");
    }
}
/*

void hareketYazdir(char tas, struct Poz ilkPozisyon){
    struct Poz *(*satrancFonksiyonlari[]) (struct Poz) = {&hareketAt, &hareketFil, //  creating array of
                                                          &hareketSah, &hareketKale,// func. pointer
                                                          &hareketPiyon, &hareketVezir};
    switch (tas){
        case 'a':
            satrancFonksiyonlari[0] (ilkPozisyon);break;
        case 'f':
            satrancFonksiyonlari[1] (ilkPozisyon);break;
        case 's':
            satrancFonksiyonlari[2] (ilkPozisyon);break;
        case 'k':
            satrancFonksiyonlari[3] (ilkPozisyon);break;
        case 'p':
            satrancFonksiyonlari[4] (ilkPozisyon);break;
        case 'v':
            satrancFonksiyonlari[5] (ilkPozisyon);break;
    }
}
 */

struct Poz *hareketSah(struct Poz old){
    // this func. return an array of possible positions.
    int i, j, k=0;
    struct Poz *possiblePositions = (struct Poz *)calloc(8, sizeof(struct Poz));
    struct Poz p1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if( !((j==1) && (i==1)) ){
                p1.dusey = old.dusey+(i-1);
                p1.yatay = old.yatay+(j-1);
                possiblePositions[k] = p1;
                k++;
            }
        }
    }
    return possiblePositions;
}

struct Poz *hareketPiyon(struct Poz old){
    // this func. return an array of possible positions.
    // return arr. can have one value or two. depends on the first position.
    int i;
    struct Poz *possiblePositions;
    struct Poz p1;
    if(old.dusey == 2){
        struct Poz *foo = (struct Poz *)calloc(2, sizeof(struct Poz));
        for (i = 0; i < 2; i++) {
            p1.dusey = old.dusey + (i+1);
            p1.yatay = old.yatay;
            foo[i] = p1;
        }
        possiblePositions = foo;
    }else{
            struct Poz *foo = (struct Poz *)calloc(1, sizeof(struct Poz));
            p1.dusey = old.dusey + 1;
            p1.yatay = old.yatay;
            foo[0] = p1;
            possiblePositions = foo;
    }
    return possiblePositions;
}

