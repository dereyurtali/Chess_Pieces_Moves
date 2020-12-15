#include "ChessLib.h"
#include <stdio.h>
#include <stdlib.h>



/*struct Poz{
    short yatay;
    char dusey;
};
*/


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
        puts("");
    }
}


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
