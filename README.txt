Source files include:
    cmdline.c
    tictactoe.c
    tictactoe.h
    Makefile

How to compile the program:
    Can be compiled with the provided Makefile by using the make command OR
    Manually compile using gcc command with -Wall and -pedantic options

Assumptions:
    Use ./tictactoe to run the program for a default game of tictactoe

    Additionally, you can run the program using options
        ./tictactoe [-s <board_size>] [-i] [-c] [-h]

    -s decides the size of the board, if -s is not used, size is assumed to be 3
    -i enables computer randomized moves if used, or otherwise disabled if not
    -c changes win conditions to be 3 in a row for all board sizes
    -h uses if help is needed, prints out info regarding the options allowed

Known Limitations & Errors:
    Board size must between 3 and 10 inclusively otherwise it leads to an error

    Running the program using any options other than -s -i -c or -h will lead to an error

    Input for moves must be a pair consisting of a char and integer value respectively
    in that order with any other order of values leading to a invalid move prompting
    user to try again.

    Trying to make a move on an occupied space will lead to an message prompting
    user to try again.
