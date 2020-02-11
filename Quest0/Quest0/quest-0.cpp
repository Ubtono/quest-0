/*
        HANGMAN
*/
#include <iostream>
#include <string>
#include <random>
#include <ctype.h>

using namespace std;

void fillLetters (char, string);
int chooseRandomCountry ();
void pauseConsole ();
void printGameBoard (string);
char processUserInput ();
void clearConsole ();
bool isGameDone (string);
void printGameOver (string guess);
bool isGameSuccessful (string currentGuess);
void printNumberOfTries ();

const int numCountries = 30;
int padding = 3; // number of spaces on each side of the word

// These variables are important to keep in mind
const int maxNumberGuesses = 10;
int currentGuessNumber = 0;
string currentGuessString = "";
string correctCountry = "";

string countries [] = {
    "senegal",
    "serbia",
    "seychelles",
    "singapore",
    "slovakia",
    "slovenia",
    "somalia",
    "spain",
    "sudan",
    "suriname",
    "swaziland",
    "sweden",
    "switzerland",
    "syria",
    "taiwan",
    "tajikistan",
    "tanzania",
    "thailand",
    "togo",
    "tonga",
    "tunisia",
    "turkey",
    "turkmenistan",
    "tuvalu",
    "uganda",
    "ukraine",
    "uruguay",
    "uzbekistan",
    "vanuatu",
    "venezuela",
};

int main () {
    clearConsole();

    correctCountry = countries[chooseRandomCountry()];

    // this will initialize the currentGuess String to
    // be the same length as the chosen county but contain only asterisks
	currentGuessString = std::string(correctCountry.length(), '*');

    while (isGameDone(currentGuessString) == false) {
        printGameBoard(currentGuessString);
        printNumberOfTries();
        char userGuess = processUserInput();
        fillLetters(userGuess, correctCountry);

        clearConsole();
    }

    printGameOver(currentGuessString);
	cout << endl << endl << "Thanks for Playing!" << endl << endl;
}

bool isGameDone (string currentGuess) {
	return (isGameSuccessful(currentGuess) || (currentGuessNumber >= maxNumberGuesses));
}

bool isGameSuccessful (string currentGuess) {
    return (currentGuess == correctCountry);
}

void printGameOver(string currentGuess) {

	printGameBoard(correctCountry);
	if (isGameSuccessful(currentGuess)) {
		cout << endl << "CONGRATS! You guessed it!";
	}
	else {
		cout << endl << "INCORRECT" << endl;
	}
}
void printGameBoard(string guess) {
	int width = guess.length() + 2 * padding; // Ignore warning: Overflow impossible with given strings
                         
	cout << "+";
	for (int i{ 0 }; i < width; i++) {
		cout << "-";
	}
	cout << "+" << endl << "|";
	for (int p{ 0 }; p < padding; p++) {
		cout << " ";
	}
	cout << guess;
	for (int p{ 0 }; p < padding; p++) {
		cout << " ";
	}
	cout << "|" << endl << "|";
	for (int p{ 0 }; p < padding; p++) {
		cout << " ";
	}
	for (int s{ 0 }; s < guess.length(); s++) {
		cout << "_";
	}
	for (int p{ 0 }; p < padding; p++) {
		cout << " ";
	}
	cout << "|" << endl << "+";
	for (int i{ 0 }; i < width; i++) {
		cout << "-";
	} 
	cout << "+" << endl;
}

void printNumberOfTries () {
	int guessesLeft = maxNumberGuesses - currentGuessNumber;
	cout << "Guesses Left: " << guessesLeft << endl;
}

char processUserInput () {
	char input;
	cout << "Guess a Letter: ";
	cin >> input;
	currentGuessNumber++;

    return input;
}

void fillLetters (char guessChar, string secretWord) {
	string filledWord = "";
	for (int i{}; i < secretWord.length(); i++) {
		if (guessChar == secretWord.at(i)) { // user guessed correct letter 
			filledWord = filledWord.append(secretWord, i, 1);
		}
		else if (currentGuessString.at(i) == secretWord.at(i)) { // this letter has already been correctly guessed
			filledWord = filledWord.append(secretWord, i, 1);
		}
		else {
			filledWord = filledWord.append("*");
		}
	}
	currentGuessString = filledWord;
}


void pauseConsole () {
    std::string temp;
    std::cout << "Enter to continue... ";
    std::getline(std::cin, temp);
}

void clearConsole () {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    	system("cls");
    #else
        system("clear");
    #endif
}

int chooseRandomCountry () {
    random_device seed;
    default_random_engine engine(seed());
    uniform_int_distribution<int> dist(0, numCountries-1);

    return dist(engine);
}
