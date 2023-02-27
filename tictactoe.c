// Methods for playing tictactoe
#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"

// Prints the board
void printboard( char** Board, int board_sz )
{
    // Prints the column numbers
    printf(" |");
    for (int size = 0; size < board_sz; size++)
    {
        printf("%d|", size);
    } // for
    putchar('\n');

    // Prints the rows and each spot
    for(int row = 0; row < board_sz; ++row)
    {
    	printf("%c|", 'a' + row);
    	for( int col = 0; col < board_sz; ++col )
        {
      		printf("%c|", Board[row][col]);
    	} // for
        printf("\n");
    } // for
} // printboard

// Creates tic tac toe board
char** createboard(int board_sz)
{
    char** B = calloc(board_sz, sizeof(char*) );

    // Space for board
    for(int i = 0; i < board_sz; ++i)
    {
    	B[i] = calloc(board_sz, sizeof(char));
    } // for

    for(int j = 0; j < board_sz; ++j)
    {
    	for(int k = 0; k < board_sz; ++k)
        {
      		B[j][k] = ' ';
    	} // for
    } // for
    return B;
} // createboard

// Returns true if the game is a draw
int isdraw(char** Board, int board_sz) {
    for(int i = 0; i < board_sz; ++i) {
        for(int j = 0; j < board_sz; ++j) {
            if (Board[i][j] == ' ') {
                // Empty square, so game ain't over yet
                return 0;
            } // if
        } // for
    } // for
    // No empty squares, so it's a draw
    return 1;
} // isdraw

// Returns 'X' if (row, col) was a winning move for X
// Returns 'Y' if (row, col) was a winning move for Y
// Returns ASCII value 0 otherwise
char winningmove( char** Board, int board_sz, int row, int col )
{
    char player = Board[row][col];
    // Check horizontal win
    for (int co = 0; co < board_sz; co++)
    {
        // Ends loop when it doesnt match
        if (Board[row][co] != player)
        {
            break;
        } // if
        // Assumes win if end of loop
        if (co == board_sz - 1)
        {
            return player;
        } // if
    } // for
    // Check vertical win
    for (int ro = 0; ro < board_sz; ro++)
    {
        // Ends loop when it doesnt match
        if (Board[ro][col] != player)
        {
            break;
        } // if
        // Assumes win if end of loop
        if (ro == board_sz - 1)
        {
            return player;
        } // if
    } // for
    // Checks forward diagonal win
    if (row == col) {
        for (int ind = 0; ind < board_sz; ind++)
        {
            // Ends loop when it doesnt match
            if (Board[ind][ind] != player)
            {
                break;
            } // if
            // Assumes win if end of loop
            if (ind == board_sz - 1)
            {
                return player;
            } // if
        } // for
    } // if
    // Checks reverse diagonal win
    if (row + col == board_sz - 1)
    {
        for (int in = board_sz - 1; in >= 0; in--)
        {
            // Ends loop when it doesnt match
            if (Board[in][board_sz - 1 - in] != player)
            {
                break;
            } // if
            // Assumes win if end of loop
            if (in == 0)
            {
                return player;
            } // if
        } // for
    } //if
    return 0;
} // winninmove

// Runs the loop for one game of tictactoe
int play_tictactoe(int board_sz, int computer_enabled)
{
    char winner = '\0';
    char row;
    char col;
    char turn = 'X';
    char **Board = createboard(board_sz);

    // Used to continue after comp pick
    char cont;
    char secchar;
    // Invalid move boolean equivalent
    int inval = 0;
    // Space occupied boolean equivalent
    int spcocp = 0;

    // Standard game loop
    while( !winner && !isdraw(Board, board_sz) )
    {
        system("clear");
        printboard(Board, board_sz);

    	// Get Move
        // Prints whether computer moves are enabled/disabled
        if (computer_enabled)
        {
            printf("Computer 'O' moves are 'enabled'\n");
        }
        else
        {
            printf("Computer 'O' moves are 'disabled'\n");
        } // if

        printf( "Player's %c turn (qq to quit)\n", turn );

        // Prints message if cant make move
        if (inval || spcocp)
        {
            if (spcocp) {
                printf("Square is occupied; try again.\n");
                spcocp = 0;
            } // if
            if (inval)
            {
                printf("Invalid row or col value; try again.\n");
                inval = 0;
            } // if
        } // if
        // Computer rand move or prompt player X for input
        if (computer_enabled && turn == 'O')
        {
            row = rand() % (board_sz) + 97;
            col = rand() % (board_sz) + 48;

            // Checks to see if space is occupied
            while (Board[row - 'a'][col - '0'] != ' ')
            {
                row = rand() % (board_sz) + 97;
                col = rand() % (board_sz) + 48;
            } // while

            printf("(%c) Computer picks (%c%c) (hit a key and press enter to continue) ",
            	turn, row, col);
            fflush(stdout);
            scanf(" %c", &cont);
            secchar = getchar();
            // Checks if player wants to quit during comp turn
            if (cont == 'q' && secchar == 'q')
            {
                return 0;
            } // if
            putchar('\n');
        }
        else
        {
            printf("------ Suggested move: ");
            getmove(Board, board_sz);
            printf( "(%c) Enter Move (row column) Example: a 1 ---> ", turn );
            fflush(stdout);
            scanf(" %c %c", &row, &col);
        } // if

        // If input equals qq, quit the program
        if (row == 'q' && col == 'q')
        {
            return 0;
        } // if

        // Checks to see if input is invalid
        if (row < 'a' || row > ('a' + board_sz - 1) || col < '0' || col > ('0' + board_sz -1))
        {
            inval = 1;
            continue;
        } // if

    	// Make move if square is free
    	int rowind = row - 'a';
    	int colind = col - '0';
    	if (Board[rowind][colind] == ' ')
    	{
            if (!computer_enabled || turn != 'O')
            {
                printf("Move is %c %c (%d, %d)\n", row, col, rowind, colind);
            } // if

            Board[rowind][colind] = turn;

            if (turn == 'X')
            {
                turn = 'O';
      		}
            else
            {
                turn = 'X';
      		} // if
      		winner = winningmove( Board, board_sz, rowind, colind );
    	}
        else
        {
      		spcocp = 1;
        } // if
    } // while

    // Game over - print board & declare finish
    printboard(Board, board_sz);

    if (winner == 'X' || winner == 'O')
    {
        printf("Congratulations %c!\n", winner);
    }
    else
    {
    	printf("Game ends in a draw.\n");
    } // if

    return 0;
} // play_tictactoe

// Returns a valid move
int getmove(char **Board, int board_sz)
{
    int r;
    int c;
    // Loops til it finds an empty space
    while (1)
    {
        r = (rand() % (board_sz) + 97) - 'a';
        c = (rand() % (board_sz) + 48) - '0';
        if (Board[r][c] == ' ' )
        {
            printf("(%c", r + 97);
            printf("%d)\n", c);
            return 0;
        } // if
    } // while
    return 0;
} // getMove
