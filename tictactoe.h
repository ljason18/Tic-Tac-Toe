// Header file for tictactoe.c
#ifndef TICTACTOE_H
#define TICTACTOE_H


extern void printboard(char **Board, int board_sz);
extern char** createboard(int board_sz);
extern int isdraw(char **Board, int board_sz);
extern char winningmove(char **Board, int board_sz, int row, int col);
extern int play_tictactoe(int board_sz, int computer_enabled, int connect3);
extern int getmove(char **Board, int board_sz);
extern char connect3win(char **Board, int board_sz, int row, int col);

#endif
