#ifndef ChessLib_h
#define ChessLib_h

#include <stdio.h>

#endif /* ChessLib_h */

struct Poz{
    short yatay;
    char dusey;
};

int **createChessTable(void);

void printChessTable(int **);

void hareketYazdir(char, struct Poz);

struct Poz *hareketSah(struct Poz);

struct Poz *hareketVezir(struct Poz);

struct Poz *hareketFil(struct Poz);

struct Poz *hareketAt(struct Poz);

struct Poz *hareketKale(struct Poz);

struct Poz *hareketPiyon(struct Poz);
