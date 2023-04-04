#include "Game.h"
#include "Board.h"

void Game::PlayerVsPlayer()
{
	Board board;
	char player1, player2, playerSymbol;
	int position;
	PlayerTurn playerTurn;

	srand(time(NULL));

	std::cout << "+-------------+" << std::endl;
	board.DisplayBoardInit();
	std::cout << "+-------------+" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter symbol for player 1: ";
	std::cin >> player1;
	std::cout << "Enter symbol for player 2: ";
	std::cin >> player2;

	std::cout << std::endl;
	std::cout << "Flipping a coin..." << std::endl;
	int coin = (rand() % 2 + 1);
	coin--;
	if (coin == 0)
		std::cout << "Player 1 is starting.";
	else
		std::cout << "Player 2 is starting.";
	std::cout << std::endl;

	while (board.GetValidMovesCount() < 9)
	{
		std::cout << std::endl;
		if (board.GetValidMovesCount() % 2 == coin)
		{
			playerTurn = firstPlayer;
			playerSymbol = player1;
			std::cout << "Player " << playerTurn << "'s turn. ";
		}
		else
		{
			playerTurn = secondPlayer;
			playerSymbol = player2;
			std::cout << "Player " << playerTurn << "'s turn. ";
		}
		std::cout << "Enter your position: ";
		std::cin >> position;
		std::cout << std::endl;
		position--;
		if (position <= 1 && position >= 9)
		{
			std::cout << "Invalid position! Please try another." << std::endl;
		}
		else
		{
			char pos = position + 49;
			if (!board.IsValidPosition(pos))
			{
				std::cout << "Invalid position! Please try another." << std::endl;
			}
			else
			{
				if (board.IsAlreadyMarked(pos))
				{
					board.MarkBoard(pos, playerSymbol);
					board.DisplayBoard();
				}
				else
				{
					std::cout << "Position already marked! Please try another." << std::endl;
				}
			}
		}
		if (board.IsWinner())
		{
			
			std::cout << std::endl << "Player " << playerTurn << " wins!" << std::endl;
			break;
		}
		if (board.GetValidMovesCount() == 9)
		{
			std::cout << std::endl << "Draw!" << std::endl;
			break;
		}
	}
}

void Game::PlayerVsComputer()
{
	Board board;
	char player, computer, playerSymbol;
	int position;

	srand(time(NULL));

	std::cout << "+-------------+" << std::endl;
	board.DisplayBoardInit();
	std::cout << "+-------------+" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter symbol for yourself: ";
	std::cin >> player;
	std::cout << "Enter symbol for computer: ";
	std::cin >> computer;

	std::cout << std::endl;
	std::cout << "Flipping a coin..." << std::endl;
	int coin = (rand() % 2 + 1);
	coin--;
	if (coin == 0)
		std::cout << "You are starting.";
	else
		std::cout << "Computer is starting.";
	std::cout << std::endl;

	while (board.GetValidMovesCount() < 9)
	{
		std::cout << std::endl;
		if (board.GetValidMovesCount() % 2 == coin)
		{
			playerSymbol = player;
			std::cout << "Your turn. ";
			std::cout << "Enter your position: ";
			std::cin >> position;
			std::cout << std::endl;
			position--;
			if (position <= 1 && position >= 9)
			{
				std::cout << "Invalid position! Please try another." << std::endl;
			}
			else
			{
				char pos = position + 49;

				if (!board.IsValidPosition(pos))
				{
					std::cout << "Invalid position! Please try another." << std::endl;
				}
				else
				{
					if (board.IsAlreadyMarked(pos))
					{
						board.MarkBoard(pos, playerSymbol);
						board.DisplayBoard();
					}
					else
					{
						std::cout << "Position already marked! Please try another." << std::endl;
					}
				}
			}
			if (board.IsWinner())
			{

				std::cout << std::endl << "You win!" << std::endl;
				break;
			}
			if (board.GetValidMovesCount() == 9)
			{
				std::cout << std::endl << "Draw!" << std::endl;
				break;
			}
		}
		else
		{
			playerSymbol = computer;
			std::cout << "Computer's turn. ";
			std::cout << "Computer is thinking..." << std::endl;
			position = (rand() % 9 + 1);
			std::cout << std::endl;
			if (position <= 1 && position >= 9)
			{
				std::cout << "Invalid position! Please try another." << std::endl;
			}
			else
			{
				char pos = position + 49;
				board.IsValidPosition(pos);

				if (!board.IsValidPosition(pos))
				{
					std::cout << "Invalid position! Please try another." << std::endl;
				}
				else
				{
					if (board.IsAlreadyMarked(pos))
					{
						board.MarkBoard(pos, playerSymbol);
						board.DisplayBoard();
					}
					else
					{
						std::cout << "Position already marked! Please try another." << std::endl;
					}
				}
			}
			if (board.IsWinner())
			{

				std::cout << std::endl << "Computer wins!" << std::endl;
				break;
			}
			if (board.GetValidMovesCount() == 9)
			{
				std::cout << std::endl << "Draw!" << std::endl;
				break;
			}
		}
	}
}

void Game::PlayGame()
{
	std::cout << "Press 'a' to play the game, in console, player vs. player." << std::endl;
	std::cout << "Press 'b' to play the game, in console, player vs. computer." << std::endl;
	std::cout << "Press 'c' to exit." << std::endl;

	std::string option;
	bool menu = true;
	while (menu == true)
	{
		std::cin >> option;
		std::cout << std::endl;
		if (option.length() == 1)
			switch (option[0])
			{
			case 'a':
			{
				PlayerVsPlayer();
				std::cout << "Would you like to play again or perhabs try another mode? (Y / N)" << std::endl;
				char answer;
				std::cout << std::endl;
				std::cin >> answer;
				if (answer == 'Y' || answer == 'y')
				{
					system("cls");
					std::cout << "Press 'a' to play the game, in console, player vs. player." << std::endl;
					std::cout << "Press 'b' to play the game, in console, player vs. computer." << std::endl;
				}
				else
				{
					menu = false;
				}
				break;
			}
			case 'b':
			{
				PlayerVsComputer();
				std::cout << "Would you like to play again or perhabs try another mode? (Y / N)" << std::endl;
				char answer;
				std::cout << std::endl;
				std::cin >> answer;
				if (answer == 'Y' || answer == 'y')
				{
					system("cls");
					std::cout << "Press 'a' to play the game, in console, player vs. player." << std::endl;
					std::cout << "Press 'b' to play the game, in console, player vs. computer." << std::endl;
				}
				else
				{
					menu = false;
				}
				break;
			}
			case 'c':
			{
				menu = false;
				break;
			}
			default:
			{
				if (option[0] < 'a' || option[0] > 'c')
				{
					std::cout << "Not an option, try again:" << std::endl;
					std::cout << std::endl;
				}
			}
			}
	}
}