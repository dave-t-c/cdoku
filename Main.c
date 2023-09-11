//
// Created by David Cook on 08/09/2023.
//

#include <stdio.h>
#include "Solver.h"
#include "constants.h"

int main(int argc, char* argv[]){
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

    printf("Original board:\n");
    for(int i = 0; i < BOARD_WIDTH; ++i){
        for(int j = 0; j < BOARD_HEIGHT; ++j){
            char currentChar = board[i][j];
            printf("%c", currentChar);
        }
        printf("\n");
    }

    solveForIndex(board, 0, 0);

    printf("Final board:\n");
    for(int i = 0; i < BOARD_WIDTH; ++i){
        for(int j = 0; j < BOARD_HEIGHT; ++j){
            char currentChar = board[i][j];
            printf("%c", currentChar);
        }
        printf("\n");
    }

    return 0;
}
