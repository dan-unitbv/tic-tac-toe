#include "Board.h"

Board::Board()
{
	board[0][0] = '1';
	board[0][1] = '2';
	board[0][2] = '3';
	board[1][0] = '4';
	board[1][1] = '5';
	board[1][2] = '6';
	board[2][0] = '7';
	board[2][1] = '8';
	board[2][2] = '9';
}

void Board::DisplayBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X' || board[i][j] == 'O')
				std::cout << std::setw(4) << board[i][j];
			else
				std::cout << std::setw(4) << "-";
		}
		std::cout << std::endl;
	}
}

void Board::DisplayBoardInit()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << std::setw(4) << board[i][j];
		}
		std::cout << std::endl;
	}
}

void Board::MarkBoard(char position, char playerSymbol)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == position)
			{
				board[i][j] = playerSymbol;
				validMovesCount++;
			}
		}
	}
}

bool Board::IsValidPosition(char position)
{
	if (position >= '1' && position <= '9')
		return true;
	else
		return false;
}

bool Board::IsAlreadyMarked(char position)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == position)
				return true;
		}
	}
	return false;
}

bool Board::IsWinner()
{
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
		return true;
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
		return true;
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
		return true;
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
		return true;
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
		return true;
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
		return true;
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return true;
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return true;
	else
		return false;
}

int Board::GetValidMovesCount()
{
	return validMovesCount;
}