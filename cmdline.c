// Parses the command line and sets necessary variables
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int play_tictactoe(int board_sz, int computer_enabled, int connect3);

int main(int argc, char *argv[])
{
    srand(time(0));
    int size = 3;
    int comp = 0;
    int opt;
    int connect3 = 0;

    // Checks the command line
    while ((opt = getopt(argc, argv, "s:ihc")) != -1)
    {
        switch(opt)
        {
        	case 's':
                size = atoi(optarg);
                break;

        	case 'i':
                comp = 1;
                break;

        	case 'h':
                printf("Usage: tictactoe [-s <board_size>] [-i] [-c] [-h]\n");
                return 0;

	        case 'c':
                connect3 = 1;
                break;

        	case '?':
                printf("Try ./tictactoe -h for more information\n");
                system("./tictactoe -h");
                return 0;

        } // switch
    }  // while

    // Checks that size is within range
    if (size < 3 || size > 10)
    {
        printf("Invalid size value. Board must be from 3x3 to 10x10\n");
        return 0;
    } // if

    // Runs the game loop
    play_tictactoe(size, comp, connect3);
    return 0;
} // main
