#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 9; i++) {
		moves[i] = '-';
	}
	turn = 1;
	player1Turn = true;
}

void TicTacToe::reset()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThe game is over! play again:" << endl;
	for (int i = 0; i < 9; i++) {
		moves[i] = '-';
	}
}

void TicTacToe::print()
{
		cout << "turn: " << turn << "\n------------" << endl;
		cout << "  1  2  3\n" <<
			"A " << moves[0] << "  " << moves[1] << "  " << moves[2] << "\n" <<
			"B " << moves[3] << "  " << moves[4] << "  " << moves[5] << "\n" <<
			"C " << moves[6] << "  " << moves[7] << "  " << moves[8] << "\n" <<
			"------------" << endl;

		if (!player1Turn)
			cout << "player 2's turn:" << endl;
		else
			cout << "player 1's turn:" << endl;
}

bool TicTacToe::over()
{
	/*
		for (int i = 0; i < 9; i++) {
			if (!(i % 3) == 0) { //checks if i is in collumn A
				if (moves[i] == moves[i + 1] && moves[i + 1] == moves[i])
					return true;
			}
			else if (moves[i] == moves[i + 3] && moves[i + 3] == moves[i + 6])
				return true;
		}
	*/

	if (turn > 9) 
		return true;

	if (moves[0] == moves[1] && moves[1] == moves[2] && moves[0] != '-') {
		return true; //if the game is won
	}
	if (moves[0] == moves[3] && moves[3] == moves[6] && moves[0] != '-') {
		return true; //if the game is won
	}
	if (moves[3] == moves[4] && moves[4] == moves[5] && moves[3] != '-') {
		return true; //if the game is won
	}
	if (moves[1] == moves[4] && moves[4] == moves[7] && moves[1] != '-') {
		return true; //if the game is won
	}
	if (moves[6] == moves[7] && moves[7] == moves[8] && moves[6] != '-') {
		return true; //if the game is won
	}
	if (moves[2] == moves[5] && moves[5] == moves[8] && moves[2] != '-') {
		return true; //if the game is won
	}
	if (moves[0] == moves[4] && moves[4] == moves[5] && moves[0] != '-') {
		return true; //if the game is won
	}
	if (moves[2] == moves[4] && moves[4] == moves[6] && moves[2] != '-') {
		return true; //if the game is won
	}

	return false; // if the game is not won yet
}

int TicTacToe::move(int col, char row)
{
	if (col > 0 && col < 4) {
		if (!player1Turn) {
				switch (row) {
				case 'A':
					if (moves[col - 1] == '-')
					{
						moves[col - 1] = 'O';
						turn++;
						player1Turn = true;
					}
					else {
						return 1;
					}
					break;
				case 'B':
					if (moves[col + 2] == '-') {
						moves[col + 2] = 'O';
						turn++;
						player1Turn = true;
					}
					else {
						return 1;
					}
					break;
				case 'C':
					if (moves[col + 5] == '-') {
						moves[col + 5] = 'O';
						turn++;
						player1Turn = true;
					}
					else {
						return 1;
					}
					break;
				default:
					return 1;
					break;
				}
			}
			else if (player1Turn) {
				switch (row) {
				case 'A':
					if (moves[col - 1] == '-') {
						moves[col - 1] = 'X';
						turn++;
						player1Turn = false;
					}
					else {
						return 1;
					}
					break;
				case 'B':
					if (moves[col + 2] == '-') {
						moves[col + 2] = 'X';
						turn++;
						player1Turn = false;
					}
					else {
						return 1;
					}
					break;
				case 'C':
					if (moves[col + 5] == '-') {
						moves[col + 5] = 'X';
						turn++;
						player1Turn = false;
					}
					else {
						return 1;
					}
					break;
				default:
					return 1;
					break;
				}
			}
	}
	else 
		return 1;

	return 0;
}


TicTacToe::~TicTacToe()
{
}
