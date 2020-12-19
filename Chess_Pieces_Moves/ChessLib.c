#include "ChessLib.h"
#include <stdio.h>
#include <stdlib.h>

int **generateChessTable(struct Poz position, struct Poz *possiblePositions){ // this func. will take possible positions and generate matrix.
                                                                   // empty positions will be filled with 0 's.
                                                                   // possible moves will be 1 's. tas will be 2.
    int i, j, k=0;
    int **printableArray = (int **)calloc(8, sizeof(int *));
    for (i = 0; i < 8; i++) {
        printableArray[i] = (int *)calloc(8, sizeof(int));
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (position.yatay == (8-i) && position.dusey == j + 'a') {
                printableArray[i][j] = 2;
            }else{
                printableArray[i][j] = 0;
            }
            while (possiblePositions[k].dusey != 0) { // i = 3, j = 4
                if ((possiblePositions[k].yatay == (8-i)) && (possiblePositions[k].dusey == j+'a')){
                    printableArray[i][j] = 1;
                }
                k++;
            }
            k=0;
        }
    }
    return printableArray;
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

void hareketYazdir(char tas, struct Poz ilkPozisyon){
    struct Poz *(*satrancFonksiyonlari[]) (struct Poz) = {&hareketAt, &hareketFil, //  creating array of
                                                          &hareketSah, &hareketKale,// func. pointer
                                                          &hareketPiyon, &hareketVezir};
    struct Poz *output;
    int **output2;
    switch (tas){
        case 'a':
            output = satrancFonksiyonlari[0] (ilkPozisyon);break;
        case 'f':
            output = satrancFonksiyonlari[1] (ilkPozisyon);break;
        case 's':
            output = satrancFonksiyonlari[2] (ilkPozisyon);break;
        case 'k':
            output = satrancFonksiyonlari[3] (ilkPozisyon);break;
        case 'p':
            output = satrancFonksiyonlari[4] (ilkPozisyon);break;
        case 'v':
            output = satrancFonksiyonlari[5] (ilkPozisyon);break;
    }
    output2 = generateChessTable(ilkPozisyon, output);
    printChessTable(output2);
}

struct Poz *hareketSah(struct Poz old){
    // this func. return an array of possible positions.
    int i, j, k=0;
    struct Poz *possiblePositions = (struct Poz *)calloc(8, sizeof(struct Poz));
    struct Poz new;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if( !((j==1) && (i==1)) ){
                new.yatay = old.yatay+(i-1);
                new.dusey = old.dusey+(j-1);
                possiblePositions[k++] = new;
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
    if(old.yatay == 2){
        struct Poz *foo = (struct Poz *)calloc(2, sizeof(struct Poz));
        for (i = 0; i < 2; i++) {
            new.yatay = old.yatay + (i+1);
            new.dusey = old.dusey;
            foo[i] = new;
        }
        possiblePositions = foo;
    }else{
            struct Poz *foo = (struct Poz *)calloc(1, sizeof(struct Poz));
            new.yatay = old.yatay + 1;
            new.dusey = old.dusey;
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
            if (old.yatay == (j+1) || old.dusey == (i+'a')) {
                new.yatay = (j+1);
                new.dusey = i+'a';
                if (!(new.dusey == 'e' && new.yatay == 4)) {
                    possiblePositions[k++] = new;
                }
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
        new.dusey = i+'a';
        k = new.dusey - old.dusey;
        new.yatay = old.yatay + k;
        if (new.yatay > 0){
            if (!(new.dusey == 'e' && new.yatay == 4)) {
                possiblePositions[j++] = new;
            }
        }
        new.yatay = old.yatay - k;
        if (new.yatay > 0){
            if (!(new.dusey == 'e' && new.yatay == 4)) {
                possiblePositions[j++] = new;
            }
        }
    }
    // this func. made with kan, ter, gozyasi.
    return possiblePositions;
}

struct Poz *hareketVezir(struct Poz old){
    // this func. return an array of possible positions.
    int i, j, k=0;
    struct Poz *possiblePositions = (struct Poz *)calloc(27, sizeof(struct Poz));
    struct Poz new;
    // plus code.
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (old.yatay == (j+1) || old.dusey == (i+'a')) {
                new.yatay = (j+1);
                new.dusey = i+'a';
                if(!((old.dusey == new.dusey) && (old.yatay == new.yatay))){ // it was showing the old position as possible position before this if.
                    possiblePositions[k++] = new;
                }
            }
        }
    }j = 0;
    // cross code.
    for (i = 0; i < 8; i++) {
        new.dusey = i+'a';
        j = new.dusey - old.dusey;
        new.yatay = old.yatay + j;
        if (new.yatay > 0){
            if(old.dusey != new.dusey && old.yatay != new.yatay){
                possiblePositions[k++] = new;
            }
        }
        new.yatay = old.yatay - j;
        if (new.yatay > 0){
            if(old.dusey != new.dusey && old.yatay != new.yatay){
                possiblePositions[k++] = new;
            }
        }
    }
    return possiblePositions;
}

struct Poz *hareketAt(struct Poz old){
    // this func. return an array of possible positions.
    // max. 8 possible moves.
    int i, j, k = 0, l = 0, m = 0;
    struct Poz *possiblePositions;
    struct Poz new;
    possiblePositions = (struct Poz *)calloc(8, sizeof(struct Poz));
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            k = (j+'a') - old.dusey; // k -> yatay farki
            l = (8-(i+1)) - old.yatay; // l -> dusey farki
            if ((k == 1 || k == -1) && (l == 2 || l == -2)) { // yataydaki fark 1 ise ve duseydeki fark 2 ise
                new.yatay = i+1;
                new.dusey = j+'a';
                possiblePositions[m++] = new;
            }
            if ((k == 2 || k == -2) && (l == 1 || l == -1)) { // yataydaki fark 2 ise ve duseydeki fark 1 ise
                new.yatay = i+1;
                new.dusey = j+'a';
                possiblePositions[m++] = new;
            }
        }
    }
    return possiblePositions;
}
