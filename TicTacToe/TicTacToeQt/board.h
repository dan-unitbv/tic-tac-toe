#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <iomanip>
#include <ctime>

class Board
{
private:
    char board[3][3];
    int occupiedPositionsCount = 0;
    char turn;

public:
    Board();
    void InitBoard();
    void MarkAndChangeTurn(int row, int column);
    char WhoGoesFirst();
    char IsWinner();
    void SetTurn(char t);
    char GetTurn();
    int GetOccupiedPositionsCount();
    bool IsAlreadyMarked(int row, int column);
};

#endif // BOARD_H
