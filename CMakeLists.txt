cmake_minimum_required(VERSION 3.26)
project(cdoku C)

set(CMAKE_C_STANDARD 11)

add_executable(cdoku
        Main.c
        Solver.h
        Solver.c
        constants.h
        Printer.h
        Printer.c
        Importer.c
        Importer.h
)
