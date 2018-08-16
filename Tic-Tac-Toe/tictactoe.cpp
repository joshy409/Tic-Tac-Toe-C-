#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*class Board {

public:
	//vector<string> gameboard = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	
	void printgameboard()
	{
		cout << " " + gameboard[0] + " " << "|" << " " + gameboard[1] + " " << "|" << " " + gameboard[2] + " " << endl;
		cout << "-----------" << endl;
		cout << " " + gameboard[3] + " " << "|" " " + gameboard[4] + " " << "|" << " " + gameboard[5] + " " << endl;
		cout << "-----------" << endl;
		cout << " " + gameboard[6] + " " << "|" << " " + gameboard[7] + " " << "|" << " " + gameboard[8] + " \n" << endl;
	}

	bool checkwin(string mark)
	{
		return gameboard[0] == mark and gameboard[1] == mark and gameboard[2] == mark or 
			gameboard[3] == mark and gameboard[4] == mark and gameboard[5] == mark or 
			gameboard[6] == mark and gameboard[7] == mark and gameboard[8] == mark or 
			gameboard[0] == mark and gameboard[3] == mark and gameboard[6] == mark or 
			gameboard[1] == mark and gameboard[4] == mark and gameboard[7] == mark or 
			gameboard[2] == mark and gameboard[5] == mark and gameboard[8] == mark or 
			gameboard[0] == mark and gameboard[4] == mark and gameboard[8] == mark or 
			gameboard[6] == mark and gameboard[4] == mark and gameboard[2] == mark;
	}
};*/

class Board {

public:
	vector <vector<string>> gameboard{ { "1","2","3" },
									   { "4","5","6" },
									   { "7","8","9" } };
	void printgameboard()
	{
		cout << " " + gameboard[0][0] + " " << "|" << " " + gameboard[0][1] + " " << "|" << " " + gameboard[0][2] + " " << endl;
		cout << "-----------" << endl;
		cout << " " + gameboard[1][0] + " " << "|" " " + gameboard[1][1] + " " << "|" << " " + gameboard[1][2] + " " << endl;
		cout << "-----------" << endl;
		cout << " " + gameboard[2][0] + " " << "|" << " " + gameboard[2][1] + " " << "|" << " " + gameboard[2][2] + " \n" << endl;
	}

	bool checkwin(string mark)
	{
		return gameboard[0][0] == mark and gameboard[0][1] == mark and gameboard[0][2] == mark or
			gameboard[1][0] == mark and gameboard[1][1] == mark and gameboard[1][2] == mark or
			gameboard[2][0] == mark and gameboard[2][1] == mark and gameboard[2][2] == mark or
			gameboard[0][0] == mark and gameboard[1][0] == mark and gameboard[2][0] == mark or
			gameboard[0][1] == mark and gameboard[1][1] == mark and gameboard[2][1] == mark or
			gameboard[0][2] == mark and gameboard[1][2] == mark and gameboard[2][2] == mark or
			gameboard[0][0] == mark and gameboard[1][1] == mark and gameboard[2][2] == mark or
			gameboard[2][0] == mark and gameboard[1][1] == mark and gameboard[0][2] == mark;
	}
};

class Player{
public:
	Player(string _name, string _mark) 
		: name(_name), mark(_mark) {}

	void move(vector<vector<string>>& gameboard) {
		int space = 0;
		while (true) {
			cout << name + " Make your move! (1-9) ";
			cin >> space;
			cout << endl;
			space--;
			if (gameboard[space/3][space%3] == to_string(space+1)) {
				break;
			}
			else {
				cout << "Invalid move!" << endl;
				continue;
			}
		}
		gameboard[space/3][space%3] = mark;
	}

	string name;
	string mark;
};

int main()
{
	Board board;
	Player player1("Player 1", "O");
	Player player2("Player 2", "X");
	cout << "Welcome to Tic Tac Toe!\n" << endl;
	board.printgameboard();
	int moves = 0;
	string winner;
	while (true and moves < 9) {
		player1.move(board.gameboard);
		board.printgameboard();
		moves++;
		if(board.checkwin(player1.mark)) {
			winner = player1.name;
			break;
		}

		player2.move(board.gameboard);
		board.printgameboard();
		moves++;
		if (board.checkwin(player2.mark)) {
			winner = player2.name;
			break;
		}
	}

	if (moves == 9) {
		cout << "It's a Tie!" << endl;
	}
	else {
		cout << winner + " Wins!" << endl;
	}
}