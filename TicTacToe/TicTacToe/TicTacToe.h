#include <string>
#include <iostream>

using namespace std;

class TicTacToe
{
private:
	char moves[9];
	bool player2Turn; //keeps track of who's turn it is
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
		cout << "enter collumn" << endl;
		cin >> col;
		cout << "enter row" << endl;
		cin >> row;
		game.move(col, row);
	}
	return 0;
}