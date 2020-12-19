#ifndef ChessLib_h
#define ChessLib_h

#include <stdio.h>

#endif /* ChessLib_h */

struct Poz{
    short yatay;
    char dusey;
};

void printChessTable(int **);

int **generateChessTable(struct Poz, struct Poz *);

void hareketYazdir(char, struct Poz);

struct Poz *hareketSah(struct Poz);

struct Poz *hareketPiyon(struct Poz);

struct Poz *hareketKale(struct Poz);

struct Poz *hareketFil(struct Poz);

struct Poz *hareketVezir(struct Poz);

struct Poz *hareketAt(struct Poz);

	
