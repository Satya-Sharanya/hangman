//hangman game:
/* a console-based hangman game where players guess letters to uncover a hidden word. Implement logic to track the number of attempts and provide hints if needed*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayHangman(int wrongAttempts) {
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;

    if (wrongAttempts >= 1) {
        cout << "  O   |" << endl;
    } else {
        cout << "      |" << endl;
    }

    if (wrongAttempts == 2) {
        cout << " /";
    } else if (wrongAttempts == 3) {
        cout << " /|";
    } else if (wrongAttempts >= 4) {
        cout << " /|\\" ;
    }
    cout << "  |" << endl;

    if (wrongAttempts == 5) {
        cout << " /    |" << endl;
    } else if (wrongAttempts >= 6) {
        cout << " / \\  |" << endl;
    } else {
        cout << "      |" << endl;
    }

    cout << "      |" << endl;
    cout << "=========" << endl;
}

int main() {
    string words[] = {"apple", "banana", "orange", "strawberry", "grape", "pineapple"};
    const int numWords = sizeof(words) / sizeof(words[0]);

    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        srand(time(0));
        string word = words[rand() % numWords];
        string hiddenWord(word.length(), '_');

        int wrongAttempts = 0;
        const int maxWrongAttempts = 6;

        cout << "Hangman Game" << endl;
        cout << "Guess the word!" << endl;

        while (wrongAttempts < maxWrongAttempts) {
            cout << endl;
            displayHangman(wrongAttempts);

            cout << "Word: " << hiddenWord << endl;

            char guess;
            cout << "Enter your guess: ";
            cin >> guess;

            bool found = false;
            for (int i = 0; i < word.length(); ++i) {
                if (word[i] == guess) {
                    hiddenWord[i] = guess;
                    found = true;
                }
            }

            if (hiddenWord == word) {
                cout << "Congratulations! You guessed the word correctly: " << word << endl;
                break;
            }

            if (!found) {
                wrongAttempts++;
                cout << "Wrong guess! Try again." << endl;
            }
        }

        cout << endl;
        displayHangman(wrongAttempts);

        if (wrongAttempts == maxWrongAttempts) {
            cout << "Sorry, you couldn't guess the word. The word was: " << word << endl;
        }
        
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thank you for playing Hangman!" << endl;

    return 0;
}


/*
Developed a Hangman game in C++ utilizing procedural programming concepts.Implemented key functionalities such as word selection, letter guessing, and feedback display.
Incorporated interactive hangman figure based on the number of incorrect guesses. 
*/
