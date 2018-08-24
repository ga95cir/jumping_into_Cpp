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

void init_board(string board[][3]);
void display_board(string board[][3]);
void make_move(string board[][3], int player);
bool check_win(string board[][3], bool game);
int change_player(int player);


/*
At start of game, maybe write a text to explain the rules.
*/
int main()
{
    string board[3][3];
    init_board(board);
    display_board(board);

    int player = 1;
    bool game = true;
    while (game)
    {
        make_move(board, player);
        game = check_win(board, game);
        display_board(board);
        player = change_player(player);
    }
    return 0;
}

void init_board(string board[][3])
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            board[i][j] = "-";
        }
    }
}

void display_board(string board[3][3])
{
    for (int i=0; i<3; i++)
    {
        cout << " ----------- " << endl;
        cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | " << endl;
    }
    cout << " ----------- " << endl;
}

void make_move(string board[][3], int player)
{
    bool bo = true;
    int row;
    int col;
    while (bo)
    {
        bool row_bool = true;
        while (row_bool)
        {
            row_bool = false;
            cout << "Player " << player << " please pick row 0, 1 or 2: " << endl;
            cin >> row;
            if (row!=0 && row!=1 && row!=2)
            {
                cout << "Invalid row! Row must be 0, 1 or 2!" << endl;
                cout << "Please try again." << endl;
                row_bool = true;
                continue;
            }
        }

        bool col_bool = true;
        while (col_bool)
        {
            col_bool = false;
            cout << "and column 0, 1 or 2: " << endl;
            cin >> col;
            if (col!=0 && col!=1 && col!=2)
            {
                cout << "Invalid column! Column must be 0, 1 or 2!" << endl;
                cout << "Please try again." << endl;
                col_bool = true;
                continue;
            }
        }

        if (board[row][col]=="X" || board[row][col]=="O")
        {
            cout << "Invalid move! Please try again!" << endl;
            continue;                                               // continue takes you back to the beginning of while-loop
        }
        else if (player==1)
        {
            board[row][col] = "X";
            bo = false;
            continue;
        }
        else if (player==2)
        {
            board[row][col] = "O";
            bo = false;
            continue;
        }
    }
}

bool check_win(string board[][3], bool game)
{
    bool pl1_row0 = (board[0][0]=="X" && board[0][1]=="X" && board[0][2]=="X");
    bool pl1_row1 = (board[1][0]=="X" && board[1][1]=="X" && board[1][2]=="X");
    bool pl1_row2 = (board[2][0]=="X" && board[2][1]=="X" && board[2][2]=="X");
    bool pl1_col0 = (board[0][0]=="X" && board[1][0]=="X" && board[2][0]=="X");
    bool pl1_col1 = (board[0][1]=="X" && board[1][1]=="X" && board[2][1]=="X");
    bool pl1_col2 = (board[0][2]=="X" && board[1][2]=="X" && board[2][2]=="X");
    bool pl1_dia1 = (board[0][0]=="X" && board[1][1]=="X" && board[2][2]=="X");
    bool pl1_dia2 = (board[2][0]=="X" && board[1][1]=="X" && board[0][2]=="X");

    if (pl1_row0 || pl1_row1 || pl1_row2 || pl1_col0 || pl1_col1 || pl1_col2 || pl1_dia1 || pl1_dia2)
    {
        cout << "Player 1 wins!" << endl;
        game = false;
    }

    bool pl2_row0 = (board[0][0]=="O" && board[0][1]=="O" && board[0][2]=="O");
    bool pl2_row1 = (board[1][0]=="O" && board[1][1]=="O" && board[1][2]=="O");
    bool pl2_row2 = (board[2][0]=="O" && board[2][1]=="O" && board[2][2]=="O");
    bool pl2_col0 = (board[0][0]=="O" && board[1][0]=="O" && board[2][0]=="O");
    bool pl2_col1 = (board[0][1]=="O" && board[1][1]=="O" && board[2][1]=="O");
    bool pl2_col2 = (board[0][2]=="O" && board[1][2]=="O" && board[2][2]=="O");
    bool pl2_dia1 = (board[0][0]=="O" && board[1][1]=="O" && board[2][2]=="O");
    bool pl2_dia2 = (board[2][0]=="O" && board[1][1]=="O" && board[0][2]=="O");

    if (pl2_row0 || pl2_row1 || pl2_row2 || pl2_col0 || pl2_col1 || pl2_col2 || pl2_dia1 || pl2_dia2)
    {
        cout << "Player 2 wins!" << endl;
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
