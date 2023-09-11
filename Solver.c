#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "constants.h"
#include "Solver.h"

//
// Created by David Cook on 08/09/2023.
//

/**
 * Solve the board for the current indexes
 * @param board board to solve.
 * @param row row to solve.
 * @param col column to solve.
 */
#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma ide diagnostic ignored "bugprone-too-small-loop-variable"
bool solveForIndex(char *board[], int row, int col) {
    if (row == BOARD_HEIGHT){
        return true;
    }

    // If the col is the max width,
    // move on to the next row.
    if (col == BOARD_WIDTH){
        return solveForIndex(board, row + 1, 0);
    }

    char existingChar = board[row][col];

    if (existingChar != '.'){
        return solveForIndex(board, row, col + 1);
    }

    for(char currChoice = '1'; currChoice <= '9'; currChoice++){
        // If the board is valid with this char at this index
        bool isValid = isValidBoard(board, row, col, currChoice);
        if (isValid) {


            char* existingRow = malloc(BOARD_WIDTH * sizeof(char));
            strcpy(existingRow, board[row]);
            existingRow[col] = currChoice;

            board[row] = malloc(BOARD_WIDTH * sizeof(char));
            strcpy(board[row], existingRow);
            free(existingRow);

            // If we can complete the puzzle from here with this move, return true;
            bool canComplete = solveForIndex(board, row, col + 1);
            if (canComplete){
                return true;
            } else {
                // Otherwise reset
                board[row][col] = '.';
            }
        }
    }

    return false;
}
#pragma clang diagnostic pop


/**
 * Checks if the choice can be used in the current row.
 * @param board array of array of chars.
 * @param row row to check
 * @param choice current choice
 * @return true if valid, false if not
 */
bool isValidRow(char** board, int row, char choice){
    char* boardRow = board[row];
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        char currEntry = boardRow[i];
        if (currEntry == choice) {
            return false;
        }
    }
    return true;
}

/**
 * Checks if the choice can be used in a row
 * @param board array of array of  chars
 * @param column column to check
 * @param choice choice to test
 * @return true if valid, false if not
 */
bool isValidColumn(char** board, int column, char choice){
    for (int row = 0; row < BOARD_HEIGHT; ++row) {
        char currEntry = board[row][column];
        if (currEntry == choice){
            return false;
        }
    }
    return true;
}

/**
 * Determines if the choice can be placed into the square
 * @param board Array of array of chars
 * @param row row to check
 * @param column column to check
 * @param choice choice to test
 * @return true if valid, false if not
 */
bool isValidSquare(char** board, int row, int column, char choice) {
    int initialRow = (row / GRID_WIDTH) * GRID_WIDTH;
    int initialColumn = (column / GRID_WIDTH) * GRID_WIDTH;

    for(int i = initialRow; i < initialRow + GRID_WIDTH; ++i){
        for (int j = initialColumn; j < initialColumn + GRID_WIDTH; ++j) {
            char currChar = board[i][j];
            if(currChar == choice)
            {
                return false;
            }
        }
    }

    return true;
}

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
     * - Can be worked out by sqrt (width) or sqrt (height) as grid will be square - currently using const
     */

    bool validRow = isValidRow(board, row, choice);
    if (!validRow){
        return false;
    }

    bool validColumn = isValidColumn(board, column, choice);
    if (!validColumn){
        return false;
    }

    bool validBox = isValidSquare(board, row, column, choice);
    if (!validBox){
        return false;
    }

    return true;
}
