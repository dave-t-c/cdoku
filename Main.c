//
// Created by David Cook on 08/09/2023.
//

#include <stdio.h>
#include "Solver.h"

int main(int argc, char* argv[]){
    printf("Hello world \n");
    char *board[] = {
            "53..7....",
            "6..195...",
            ".98....6.",
            "8...6...3",
            "4..8.3..1",
            "7...2...6",
            ".6....28.",
            "...419..5",
            "....8..79"
    };

    isValidBoard(board, 0, 0, 0);
}
