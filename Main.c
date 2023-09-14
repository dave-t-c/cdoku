//
// Created by David Cook on 08/09/2023.
//

#include <stdio.h>
#include "Solver.h"
#include "Printer.h"
#include "Importer.h"

int main(int argc, char* argv[]){

    char** board = importBoard(argv[1]);
    printf("Input board:\n");
    outputBoard(board);

    solveForIndex(board, 0, 0);

    printf("Final board:\n");
    outputBoard(board);

    return 0;
}
