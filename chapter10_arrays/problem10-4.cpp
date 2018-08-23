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

void init_board(int board[][3]);
void display_board(int board[][3]);
void make_move(int board[][3], int player);
bool check_win(int board[][3], bool game);
int change_player(int player);


/*
At start of game, maybe write a text to explain the rules.
*/
int main()
{
    int board[3][3];
    init_board(board);
    int player = 1;
    bool game = true;
    while (game)
    {
        display_board(board);
        make_move(board, player);
        game = check_win(board, game);
        player = change_player(player);
    }
    return 0;
}

void init_board(int board[][3])
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            board[i][j] = 0;
        }
    }
}

void display_board(int board[3][3])
{
    for (int i=0; i<3; i++)
    {
        cout << " - - - " << endl;
        cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | " << endl;
    }
    cout << " - - - " << endl;
}

void make_move(int board[][3], int player)
{
    bool bo = true;
    int row = 0;
    int col = 0;
    while (bo)
    {
        cout << "Player " << player << " please pick row: " << endl;
        cin >> row;
        cout << "and column: ";
        cin >> col;

        if (board[row][col]==1 || board[row][col]==2)
        {
            cout << "Invalid move! Please try again!" << endl;
        }
        else
        {
            board[row][col] = player;
            bo = false;
        }
    }
}

bool check_win(int board[][3], bool game)
{
    int win;
    int tie;

    win = board[0][0] + board[0][1] + board[0][2];
    if (win==3)
    {
        cout << "Player 1 wins!" << endl;
        game = false;
    }
    if (win==6)
    {
        cout << "Player 2 wins!" << endl;
        game = false;
    }
    win = board[1][0] + board[1][1] + board[1][2];
    if (win==3)
    {
        cout << "Player 1 wins!" << endl;
        game = false;
    }
    if (win==6)
    {
        cout << "Player 2 wins!" << endl;
        game = false;
    }
    win = board[2][0] + board[2][1] + board[2][2];
    if (win==3)
    {
        cout << "Player 1 wins!" << endl;
        game = false;
    }
    if (win==6)
    {
        cout << "Player 2 wins!" << endl;
        game = false;
    }

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (board[i][j]==1 || board[i][j]==2)
            {
                tie += 1;
            }
        }
    }

    if (tie==9)
    {
        cout << "It's a tie!" << endl;
        game = false;
    }

    return game;
}

int change_player(int player)
{
    if (player==1)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
