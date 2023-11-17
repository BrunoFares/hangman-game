#include "Hangman.h"

// static variable initialisation
string Hangman::words[10] = {"MARIA", "BRUNO", "CSC213", "FNAS", "COMPUTER", 
							"JASON", "MILAN", "HANGMAN", "LONDON", "PARIS"};

// constructor
Hangman::Hangman() {
	// random number generator
	srand(static_cast<unsigned int>(time(nullptr)));
	int randNum = rand() % 10;
	
	wordLength = words[randNum].length();
	// dynamic memory allocation
	chosenLetters = new bool[wordLength];

	wordName = words[randNum];
	numOfMistakes = 0;

	for (int i = 0; i < wordLength; i++)
		chosenLetters[i] = false;
}	

// destructor
Hangman::~Hangman() { delete[] chosenLetters; }

// get function for the numOfMistakes variable
const int Hangman::getMistakes() { return numOfMistakes; }

// bool function for checking if a letter input by the user is available in the wordName variable
bool Hangman::checkValue() {
	bool isAvailable = false;

	for (int i = 0; i < wordLength; i++) {
		if (this->letter == this->wordName[i]) {
			this->chosenLetters[i] = true;
			isAvailable = true;
		}
	}

	return isAvailable;
}

// bool function to check if all the members of the chosenLetters array are true
const bool Hangman::isWordComplete() {
	for (int i = 0; i < wordLength; i++) {
		if (!chosenLetters[i])
			return false;
	}
	return true;
}

// incrementer for the numOfMistakes variable
Hangman& Hangman::operator++() {
	++numOfMistakes;
	return *this;
}

// friend function for the output of the word
ostream& operator<<(ostream& output, Hangman& word) {
	for (int i = 0; i < word.wordLength; i++) {
		word.checkValue();
		if (word.chosenLetters[i])
			output << word.wordName[i] << " ";
		else
			output << "_ ";
	}
	output << ": # of mistakes: " << word.getMistakes() << endl;
	return output;
}

// friend function for the input of the word
istream& operator>>(istream& input, Hangman& word) {
	input >> word.letter;
	return input;
}