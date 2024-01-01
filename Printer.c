#include <stdio.h>
#include "constants.h"

//
// Created by David Cook on 12/09/2023.
//
void outputBoard(char** board){
    for(int i = 0; i < BOARD_WIDTH; ++i){
        printf("|");
        for(int j = 0; j < BOARD_HEIGHT; ++j){
            char currentChar = board[i][j];
            printf("%c|", currentChar);
        }
        printf("\n");
    }
}