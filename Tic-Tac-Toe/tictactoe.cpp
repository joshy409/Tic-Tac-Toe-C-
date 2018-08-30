#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Board {

public:
	//3x3 2D vector board
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
		return gameboard[0][0] == mark and gameboard[0][1] == mark and gameboard[0][2] == mark or //row 1
			gameboard[1][0] == mark and gameboard[1][1] == mark and gameboard[1][2] == mark or //row 2
			gameboard[2][0] == mark and gameboard[2][1] == mark and gameboard[2][2] == mark or //row 3
			gameboard[0][0] == mark and gameboard[1][0] == mark and gameboard[2][0] == mark or //column 1
			gameboard[0][1] == mark and gameboard[1][1] == mark and gameboard[2][1] == mark or //column 2
			gameboard[0][2] == mark and gameboard[1][2] == mark and gameboard[2][2] == mark or //column 3
			gameboard[0][0] == mark and gameboard[1][1] == mark and gameboard[2][2] == mark or //diagonal left to right
			gameboard[2][0] == mark and gameboard[1][1] == mark and gameboard[0][2] == mark; //diagonal right to left
	}
};

class Player{
public:
	Player(string _name, string _mark) 
		: name(_name), mark(_mark) {}

	//updates the gameboard with X or O 
	void move(vector<vector<string>>& gameboard) {
		int space = 0;
		//user input error handling
		while (true) {
			cout << name + " Make your move! (1-9) ";
			cin >> space;
			cout << endl;
			space--;
			if (cin.fail()) {
				cout << "Invalid Move!: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			else if (space >= 9 or space <= -1) {
				cout << "Invalid Move!" << endl;
				continue;
			}
			else if (gameboard[space / 3][space % 3] == to_string(space + 1)) {
				break;
			}
			else {
				cout << "Invalid Move!" << endl;
				continue;
			}
		}

		//board positions can be translated in terinary
		gameboard[space/3][space%3] = mark;
	}

	string getName() {
		return name;
	}

	string getMark() {
		return mark;
	}

private:
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
	string winner = "";
	//game logic infinite loop until a player wins or there are no more spaces left 
	while (moves < 9) {
		//player 1's turn
		player1.move(board.gameboard);
		board.printgameboard();
		moves++;
		//check if player 1 won with the  move
		if(board.checkwin(player1.getMark())) {
			winner = player1.getName();
			break;
		}
		//player 2's turn
		player2.move(board.gameboard);
		board.printgameboard();
		moves++;
		//check if player 2 won with the move
		if (board.checkwin(player2.getMark())) {
			winner = player2.getName();
			break;
		}
	}

	//if loop was broken because the board was full it is a tie
	if (moves == 9) {
		cout << "It's a Tie!" << endl;
	} 
	else {
		cout << winner + " Wins!" << endl;
	}

	system("pause");
}