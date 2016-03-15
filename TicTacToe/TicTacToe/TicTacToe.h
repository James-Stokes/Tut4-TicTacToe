#include <string>
#include <iostream>

using namespace std;

class TicTacToe
{
private:
	char moves[9];
	bool player1Turn; //keeps track of who's turn it is
	int turn; //keeps track of what turn it is

public:
	TicTacToe();
	void reset();
	int move(int col, char row);
	void print();
	bool over();
	~TicTacToe();
};

int main() {
	TicTacToe game;
	int col;
	char row;

	while (true) {
		game.print();
		cout << "\n ENTER COLLOMN:" << endl;
		cin >> col;
		cout << "\n ENTER ROW:" << endl;
		cin >> row;
		game.move(col, row);
		if (game.over()) {
			game.reset();
		}
	}
	return 0;
}