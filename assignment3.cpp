#include <iostream>
#include "Hangman.h"
using namespace std;

int main()
{
	char input;

	do {
		cout << "Welcome to the Hangman game!" << endl;
		Hangman h;

		// loops as long as the user has made less than 6 mistakes and the word is incomplete
		while (h.getMistakes() < 6 && !h.isWordComplete()) {
			cout << "Enter letter: ";
			cin >> h;
			!h.checkValue() ? ++h : h;
			cout << h << endl;
		}

		// if the user makes 6 mistakes, lose message
		if (h.getMistakes() == 6)
			cout << "Sorry! You lost the game." << endl;

		// if the user completes the word, win message
		else if (h.isWordComplete())
			cout << "Congratulations! You won the game." << endl;

		// prompts the user for another game
		cout << "Would you like to play again? (Y or N): ";
		cin >> input;

		// clears the screen
		system("cls");

		// repeats as long as the user inputs 'y' or 'Y'
	} while (input == 'Y' || input == 'y');

	return 0;
}
