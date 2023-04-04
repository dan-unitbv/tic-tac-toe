#include "board.h"

Board::Board()
{
    InitBoard();
    turn = WhoGoesFirst();
}

void Board::InitBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '\0';
        }
    }
}

void Board::MarkAndChangeTurn(int row, int column) {
    board[row][column] = turn;
    occupiedPositionsCount++;
    if (turn == 'X')
    {
        turn = 'O';
    }
    else
    {
        turn = 'X';
    }
}

char Board::WhoGoesFirst()
{
    srand(time(NULL));

    int coin = (rand() % 2) + 1;

    if (coin == 1)
    {
        return 'X';
    }
    else if (coin == 2)
    {
        return 'O';
    }
}

char Board::IsWinner()
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return board[0][0];
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return board[1][0];
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return board[2][0];
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return board[0][0];
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return board[0][1];
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return board[0][2];
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    if (GetOccupiedPositionsCount() == 9)
    {
        return 'D';
    }

    return '\0';
}

char Board::GetTurn()
{
    return turn;
}

void Board::SetTurn(char t)
{
    turn = t;
}

int Board::GetOccupiedPositionsCount()
{
    return occupiedPositionsCount;
}

bool Board::IsAlreadyMarked(int row, int column)
{
    if (board[row][column] != '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}


