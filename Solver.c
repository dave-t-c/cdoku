#include <printf.h>
#include <stdbool.h>
#include "constants.h"

//
// Created by David Cook on 08/09/2023.
//

/**
 * Identifies if the board with a choice of this char is valid
 * @param board Board array
 * @param row Possible row
 * @param column Possible column
 * @param choice Choice of character
 */
bool isValidBoard(char** board, int row, int column, char choice){
    /*
     * What makes a board valid in sudoku?
     * Need to check against the row
     * - There cannot be another one of the char in a row
     * Need to check against the column
     * - There cannot be another one of the char in the column
     * Need to check the grid
     * - There cannot be another one of the char in the grid (currently 3x3 as working on 9x9 grid)
     * - Can be worked out by sqrt (width) or sqrt (height) as grid will be square
     */
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            char currentChar = board[i][j];
            printf("%c", currentChar);
        }
        printf("\n");
    }

    return false;
}