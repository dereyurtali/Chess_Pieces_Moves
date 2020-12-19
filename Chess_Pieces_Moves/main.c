#include <stdio.h>
#include "ChessLib.h"

int main() {
    struct Poz fav;
    fav.dusey = 'e';
    fav.yatay = 4;
    char tas;
    printf("hangi tur tasi gormek istersiniz?\n");
    scanf("%c",&tas);
    hareketYazdir(tas, fav);
    return 0;
}
