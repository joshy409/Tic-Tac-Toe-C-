/*
Create a Tic Tac Toe game.You are free to use any IDE you like.

Here are the requirements :

2 players should be able to play the game(both sitting at the same computer)
The board should be printed out every time a player makes a move
You should be able to accept input of the player position and then place a symbol on the board

 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9

*/

#include <iostream>
#include <string>
using namespace std;


void printboard()
{
	cout << "   " << "|" << "   " << "|" << endl;
	cout << "-----------" << endl;
	cout << "   " << "|" << "   " << "|" << endl;
	cout << "-----------" << endl;
	cout << "   " << "|" << "   " << "|" << endl;

}

int main() 
{
	cout << "Welcome to Tic Tac Toe!\n" << endl;
	printboard();
}