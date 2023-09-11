//
// Created by David Cook on 08/09/2023.
//

#ifndef CDOKU_SOLVER_H
#define CDOKU_SOLVER_H

#include <stdbool.h>

bool solveForIndex(char** board, int row, int col);

bool isValidBoard(char** board, int row, int col, char choice);

#endif //CDOKU_SOLVER_H
