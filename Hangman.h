#ifndef Hangman_h
#define Hangman_h

#include <iostream>
using namespace std;

class Hangman {
	friend ostream& operator<<(ostream&, Hangman&);
	friend istream& operator>>(istream&, Hangman&);

private:
	static string words[10];
	string wordName;
	bool* chosenLetters;
	char letter;
	int numOfMistakes;
	int wordLength;

public:
	Hangman();
	~Hangman();
	const int getMistakes();
	bool checkValue();
	const bool isWordComplete();
	Hangman& operator++();
};

#endif