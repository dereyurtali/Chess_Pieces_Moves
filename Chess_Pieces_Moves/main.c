#include <stdio.h>
#include "ChessLib.h"

int main() {
    struct Poz fav;
    fav.dusey = 'e';
    fav.yatay = 4;
    char tas;
    printf("At icin 'a', Fil icin 'f', Sah icin 's', \nKale icin 'k', Piyon icin 'p', Vezir icin 'v' giriniz:\n");
    scanf("%c",&tas);
    printf("\n\n");
    hareketYazdir(tas, fav);
    return 0;
}
