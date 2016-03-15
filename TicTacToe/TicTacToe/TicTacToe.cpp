#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 9; i++) {
		moves[i] = '-';
	}
}

void TicTacToe::reset()
{
	cout << "\n\n\n\n\n\n\n\n\n" << endl;
	for (int i = 0; i < 9; i++) {
		moves[i] = '-';
	}
	print();
}

void TicTacToe::print()
{
	if (!over()) {
		cout << "turn: " << turn << "\n------------" << endl;
		cout << "1	2  3\n" <<
			"A" << moves[0] << moves[1] << moves[2] <<
			"B" << moves[3] << moves[4] << moves[5] <<
			"C" << moves[6] << moves[7] << moves[8] << 
			"\n------------" << endl;
		
		if (!player2Turn)
			cout << "player 1's turn:" << endl;
		else 
			cout << "player 2's turn:" << endl;
	}
	else
		cout << "the game is over!";
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

	if (moves[0] == moves[1] && moves[1] == moves[2]) {
		return true; //if the game is won
	}
	if (moves[0] == moves[3] && moves[3] == moves[6]) {
		return true; //if the game is won
	}
	if (moves[3] == moves[4] && moves[4] == moves[5]) {
		return true; //if the game is won
	}
	if (moves[1] == moves[4] && moves[4] == moves[7]) {
		return true; //if the game is won
	}
	if (moves[6] == moves[7] && moves[7] == moves[8]) {
		return true; //if the game is won
	}
	if (moves[2] == moves[5] && moves[5] == moves[8]) {
		return true; //if the game is won
	}
	if (moves[0] == moves[4] && moves[4] == moves[5]) {
		return true; //if the game is won
	}
	if (moves[2] == moves[4] && moves[4] == moves[6]) {
		return true; //if the game is won
	}

	return false; // if the game is not won yet
}

int TicTacToe::move(int col, char row)
{
	if (col > 0 && col < 4) {
		if (!player2Turn) {
				switch (row) {
				case 'A':
					if (moves[col - 1] == '-')
					{
						moves[col - 1] = 'O';
						turn++;
					}
					else {
						return 1;
					}
					break;
				case 'B':
					if (moves[col + 2] == '-') {
						moves[col + 2] = 'O';
						turn++;
					}
					else {
						return 1;
					}
					break;
				case 'C':
					if (moves[col + 5] == '-') {
						moves[col + 5] = 'O';
						turn++;
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
			else if (player2Turn) {
				switch (row) {
				case 'A':
					if (moves[col - 1] == '-') {
						moves[col - 1] = 'X';
						turn++;
					}
					else {
						return 1;
					}
					break;
				case 'B':
					if (moves[col + 2] == '-') {
						moves[col + 2] = 'X';
						turn++;
					}
					else {
						return 1;
					}
					break;
				case 'C':
					if (moves[col + 5] == '-') {
						moves[col + 5] = 'X';
						turn++;
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
