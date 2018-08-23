/*
Write a small tic-tac-toe program that allows two players to
play tic-tac-toe competitively. Your program should check to
see if either player has won, or if the board is filled
completely (with the game ending in a tie).
Bonus: can you make your program detect if the game cannot be
won by either side before the entire grid is filled?
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int init_board();
void display_board(int board[][3]);
void make_move(int board[][3]; int player);
void check_win(int board[][3]);
int change_player(int player);


/*
At start of game, maybe write a text to explain the rules.
*/
int main()
{
    int board[3][3] = init_board();
    int player = 1;
    while (1)
    {
        display_board(board);
        make_move(board, player);
        check_win(board);
        player = change_player();
    }
    return 0;
}

