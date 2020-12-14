#include <stdio.h>
#include "ChessLib.h"

int main() {
    int **board = createChessTable();
    printChessTable(board);
    
    
    return 0;
}
