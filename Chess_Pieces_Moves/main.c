#include <stdio.h>
#include "ChessLib.h"

int main() {
    struct Poz fav;
    fav.dusey = 'e';
    fav.yatay = 4;
    char tas = 's';
    hareketYazdir(tas, fav);
    return 0;
}
