/*
Make your tic-tac-toe game into a game that allows
boards bigger than 3x3 but requires four-in-a-row
to win. Allow the players to specify the size of the
board while the program in running.
(Hint: right now, you have to define your board to
be a fixed size at compile time, so you may need to
limit the maximum size of the board.)
*/

#include <iostream>
#include <cstdlib>
using namespace std;

void init_board(string board[][100], int n);
void display_board(string board[][100], int n);
void make_move(string board[][100], int n, int player);
bool check_win(string board[][100], int n, bool game);
int change_player(int player);


int main()
{
    cout << '\n';
    cout << "****************************************************************" << endl;
    cout << "*                                                              *" << endl;
    cout << "*               Welcome to the tic-tac-toe game!               *" << endl;
    cout << "*       Player 1 has symbol X and player 2 has symbol O.       *" << endl;
    cout << "* The board will have size NxN and you need 4-in-a-row to win! *" << endl;
    cout << "*                                                              *" << endl;
    cout << "****************************************************************" << endl;
    cout << '\n';

    int n;
    cout << "Please enter the size of the board (has to be 4 <= N <= 100):" << endl;
    cout << "N = ";
    cin >> n;
    cout << '\n';

    // Size has to be fixed by hand, since
    // dynamic memory allocation is only covered
    // in chapter 14.
    string board[100][100];
    init_board(board, n);
    display_board(board, n);

    int player = 1;
    int round = 1;
    bool game = true;
    while (game)
    {
        make_move(board, n, player);
        game = check_win(board, n, game);
        display_board(board, n);
        player = change_player(player);
        if (round==n*n)
        {
            cout << "It's a draw!" << endl;
            cout << '\n';
            break;
        }
        round++;
    }
    return 0;
}

void init_board(string board[][100], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            board[i][j] = "-";
        }
    }
}

void display_board(string board[][100], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << " | " << board[i][j];
        }
        cout << " | " << endl;
    }
}

void make_move(string board[][100], int n, int player)
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
            cout << "Player " << player << " please pick row: " << endl;
            cin >> row;
            if (row>=n || row<0)
            {
                cout << "Invalid row! Row must be 0 < row < n!" << endl;
                cout << "Please try again." << endl;
                row_bool = true;
                continue;
            }
        }

        bool col_bool = true;
        while (col_bool)
        {
            col_bool = false;
            cout << "and column: " << endl;
            cin >> col;
            if (col>=n || col<0)
            {
                cout << "Invalid column! Column must be 0 < col < n!" << endl;
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

bool check_win(string board[][100], int n, bool game)
{
    bool pl1_row;
    bool pl1_col;
    bool pl1_dia1;
    bool pl1_dia2;

    bool pl2_row;
    bool pl2_col;
    bool pl2_dia1;
    bool pl2_dia2;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n-4; j++)
        {
            pl1_row = (board[i][j]=="X" && board[i][j+1]=="X" && board[i][j+2]=="X" && board[i][j+3]=="X");
            pl1_col = (board[j][i]=="X" && board[j+1][i]=="X" && board[j+2][i]=="X" && board[j+3][i]=="X");
            if (pl1_row || pl1_col)
            {
                cout << "Player 1 wins!" << endl;
                game = false;
                break;
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n-4; j++)
        {
            pl2_row = (board[i][j]=="O" && board[i][j+1]=="O" && board[i][j+2]=="O" && board[i][j+3]=="O");
            pl2_col = (board[j][i]=="O" && board[j+1][i]=="O" && board[j+2][i]=="O" && board[j+3][i]=="O");
            if (pl2_row || pl2_col)
            {
                cout << "Player 2 wins!" << endl;
                game = false;
                break;
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            pl1_dia1 = (board[i][j]=="X" && board[i+1][j+1]=="X" && board[i+2][j+2]=="X" && board[i+3][j+3]=="X");
            pl1_dia2 = (board[n-1-i][j]=="X" && board[n-1-i-1][j+1]=="X" && board[n-1-i-2][j+2]=="X" && board[n-1-i-3][j+3]=="X");
            if (pl1_dia1 || pl1_dia2)
            {
                cout << "Player 1 wins!" << endl;
                game = false;
                break;
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            pl2_dia1 = (board[i][j]=="O" && board[i+1][j+1]=="O" && board[i+2][j+2]=="O" && board[i+3][j+3]=="O");
            pl2_dia2 = (board[n-1-i][j]=="O" && board[n-1-i-1][j+1]=="O" && board[n-1-i-2][j+2]=="O" && board[n-1-i-3][j+3]=="O");
            if (pl2_dia1 || pl2_dia2)
            {
                cout << "Player 2 wins!" << endl;
                game = false;
                break;
            }
        }
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
