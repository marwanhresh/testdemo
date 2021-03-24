/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

// function which scan an unsigned int namber in a safe way
unsigned int scanValidUnsignedInt()
{
	long long int number;
	while (!(std::cin >> number) || number < 0 || number > std::numeric_limits<unsigned int>::max()) 
	{
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "invalid input, please re-enter: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard bad input
	return (unsigned int)number;
}

// function which scan an integer namber in a safe way
Direction scanDirection()
{
	string option;
	cout << "Enter '1' for vertical direction" << endl;
	cout << "Enter anything else for horizontal direction" << endl;
	getline(cin, option);
	return option == "1" ? Direction::Vertical : Direction::Horizontal;
}

int main() {
	ariel::Board board;
	unsigned int row, column, length;
    string option, userMessage;
	Direction dir;
	while(true)
	{
		cout << "Welcome to my message board" << endl;
		cout << "Enter 'post' for posting a message to the board" << endl;
		cout << "Enter 'read' for reading a message from the board" << endl;
		cout << "Enter 'exit' for exit" << endl;
		cout << "Enter anything else for show the board" << endl;
		cout << "Your choice: ";
		getline(cin, option);

		if (option == "post")
		{
			cout << "Posting a message to the board" << endl;
			cout << "Enter the row" << endl;
			row = scanValidUnsignedInt();
			cout << "Enter the column" << endl;
			column = scanValidUnsignedInt();
			dir = scanDirection();
			cout << "Enter your message" << endl;
			getline(cin, userMessage);
			board.post(row, column, dir, userMessage);
		}
		else if (option == "read")
		{
			cout << "Read message from the board" << endl;
			cout << "Enter the row" << endl;
			row = scanValidUnsignedInt();
			cout << "Enter the column" << endl;
			column = scanValidUnsignedInt();
			dir = scanDirection();
			cout << "Enter message length" << endl;
			length = scanValidUnsignedInt();
			cout << board.read(row, column, dir, length) << endl;  
		}
		else if (option == "exit")
		{
			cout << "Good bye!" << endl;
			break;
		}
		else
		{
			cout << "The board:" << endl;
			board.show();
		}
		cout << endl;
	}
}

