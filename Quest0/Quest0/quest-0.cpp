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
const int maxNumberGuesses = 4;
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
}

bool isGameDone (string currentGuess) {
    /*  This function determines if the game is over */

    return true; // placeholder
}

bool isGameSuccessful (string currentGuess) {
    /*  This function determines if a player succesfully
        guessed all of the characters
    */

    return false; // placeholder
}

void printGameOver (string currentGuess) {
    /*
        This function will print out the game board with a message at the bottom
        "CONGRATS" if the the player was successful and "YOU FAILED" if they werent.
    */
}

void printGameBoard (string guess) {
    /*
        This function will print out a rectangle to contain the
        current guess and the line

        The width of the box is the length of the guess string + 2*padding.
        The padding defines the number of spaces on either side of the underline
    */
}

void printNumberOfTries () {
    /* this function will print out the number of tries that the user has attempted
        as well as a message
    */
}

char processUserInput () {
    /*
        This function will print out a message for the user to enter a character
        The character will then be returned,
    */

    return 'n'; // placeholder
}

void fillLetters (char guessChar, string secretWord) {
    /*
        This function will modify the global variable currentGuessString.
        If any characters in the secretWord match with the guessChar, those
        characters in currentGuessString need to be changed.
    */
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
