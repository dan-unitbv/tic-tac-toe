#pragma once

#include <iostream>
#include <iomanip>

enum PlayerTurn { firstPlayer = 1, secondPlayer = 2 };

class Board
{
private:
	char board[3][3];
	int validMovesCount = 0;

public:
	Board();

	void DisplayBoard();
	void DisplayBoardInit();
	void MarkBoard(char position, char playerSymbol);
	bool IsValidPosition(char position);
	bool IsAlreadyMarked(char position);
	bool IsWinner();
	int GetValidMovesCount();
};