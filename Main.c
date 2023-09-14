//
// Created by David Cook on 08/09/2023.
//

#include <stdio.h>
#include "Solver.h"
#include "Printer.h"
#include "Importer.h"

int main(int argc, char* argv[]){

    if (argc > 2 || argc < 2){
        printf("Invalid arguments, expected file path\n");
        return 1;
    }

    char** board = importBoard(argv[1]);
    printf("Input board:\n");
    outputBoard(board);

    solveForIndex(board, 0, 0);

    printf("Final board:\n");
    outputBoard(board);

    return 0;
}
