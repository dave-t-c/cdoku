//
// Created by David Cook on 14/09/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Importer.h"
#include "constants.h"

char** importBoard(char* filePath){
    FILE* fp = fopen(filePath, "r");

    if (fp == NULL){
        if (errno != 0) {
            fprintf(stderr, "Could not open %s: %s\n", filePath, strerror(errno));
            exit(1);
        }
    }

    char fileRow[MAX_FILE_CHAR_WIDTH];

    char** importedBoard = malloc(BOARD_WIDTH * BOARD_HEIGHT * sizeof(char));
    int importedRowIndex = 0;
    while (!feof(fp)) {
        fgets(fileRow, MAX_FILE_CHAR_WIDTH, fp);

        char* importedRow = malloc(BOARD_WIDTH * sizeof(char));
        int columnIndex = 0;
        char* token;
        char* separator = ",";
        token = strtok(fileRow, separator);
        while (token != NULL){
            importedRow[columnIndex] = *token;
            token = strtok(NULL, separator);

            columnIndex++;
        }

        importedBoard[importedRowIndex] = malloc(BOARD_WIDTH * sizeof(char));
        strcpy(importedBoard[importedRowIndex], importedRow);
        free(importedRow);
        importedRowIndex++;
    }

    fclose(fp);

    return importedBoard;
}
