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
    struct Poz new;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if( !((j==1) && (i==1)) ){
                new.dusey = old.dusey+(i-1);
                new.yatay = old.yatay+(j-1);
                possiblePositions[k] = new;
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
    struct Poz new;
    if(old.dusey == 2){
        struct Poz *foo = (struct Poz *)calloc(2, sizeof(struct Poz));
        for (i = 0; i < 2; i++) {
            new.dusey = old.dusey + (i+1);
            new.yatay = old.yatay;
            foo[i] = new;
        }
        possiblePositions = foo;
    }else{
            struct Poz *foo = (struct Poz *)calloc(1, sizeof(struct Poz));
            new.dusey = old.dusey + 1;
            new.yatay = old.yatay;
            foo[0] = new;
            possiblePositions = foo;
    }
    return possiblePositions;
}

struct Poz *hareketKale(struct Poz old){
    // this func. return an array of possible positions.
    int i, j, k=0;
    struct Poz *possiblePositions = (struct Poz *)calloc(14, sizeof(struct Poz));
    struct Poz new;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (old.dusey == (j+1) || old.yatay == (i+'a')) {
                new.dusey = (j+1);
                new.yatay = i+'a';
                possiblePositions[k] = new;
                k++;
            }
        }
    }
    return possiblePositions;
}

struct Poz *hareketFil(struct Poz old){
    // this func. return an array of possible positions.
    int i, j = 0, k=0;
    struct Poz *possiblePositions = (struct Poz *)calloc(16, sizeof(struct Poz));
    struct Poz new;
    for (i = 0; i < 8; i++) {
        new.yatay = i+'a';
        k = new.yatay - old.yatay;
        new.dusey = old.dusey + k;
        if (new.dusey > 0){
            possiblePositions[j] = new;
            j++;
        }
        new.dusey = old.dusey - k;
        if (new.dusey > 0){
            possiblePositions[j] = new;
            j++;
        }
    }
    // this func. made with kan, ter, gozyasi.
    return possiblePositions;
}

struct Poz *hareketVezir(struct Poz old){
    int i, j, k=0;
    struct Poz *possiblePositions = (struct Poz *)calloc(27, sizeof(struct Poz));
    struct Poz new;
    // plus code.
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (old.dusey == (j+1) || old.yatay == (i+'a')) {
                new.dusey = (j+1);
                new.yatay = i+'a';
                if(!((old.yatay == new.yatay) && (old.dusey == new.dusey))){ // it was showing the old position as possible position before this if.
                    possiblePositions[k] = new;
                    k++;
                }
            }
        }
    }j = 0;
    // cross code.
    for (i = 0; i < 8; i++) {
        new.yatay = i+'a';
        j = new.yatay - old.yatay;
        new.dusey = old.dusey + j;
        if (new.dusey > 0){
            if(old.yatay != new.yatay && old.dusey != new.dusey){
                possiblePositions[k] = new;
                k++;
            }
        }
        new.dusey = old.dusey - j;
        if (new.dusey > 0){
            if(old.yatay != new.yatay && old.dusey != new.dusey){
                possiblePositions[k] = new;
                k++;
            }
        }
    }
    return possiblePositions;
}

struct Poz *hareketAt(struct Poz old){
    struct Poz *possiblePositions;
    possiblePositions = (struct Poz *)calloc(0, sizeof(struct Poz));
    return possiblePositions;
}
