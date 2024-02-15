
//hangman game:
/* a console-based hangman game where players guess letters to uncover a hidden word. Implement logic to track the number of attempts and provide hints if needed*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void displayHangman(int wrongAttempts) {
    std::cout << "  +---+" << std::endl;
    std::cout << "  |   |" << std::endl;

    if (wrongAttempts >= 1) {
        std::cout << "  O   |" << std::endl;
    } else {
        std::cout << "      |" << std::endl;
    }

    if (wrongAttempts == 2) {
        std::cout << " /";
    } else if (wrongAttempts == 3) {
        std::cout << " /|";
    } else if (wrongAttempts >= 4) {
        std::cout << " /|\\";
    }
    std::cout << "  |" << std::endl;

    if (wrongAttempts == 5) {
        std::cout << " /    |" << std::endl;
    } else if (wrongAttempts >= 6) {
        std::cout << " / \\  |" << std::endl;
    } else {
        std::cout << "      |" << std::endl;
    }

    std::cout << "      |" << std::endl;
    std::cout << "=========" << std::endl;
}

int main() {
    std::string words[] = {"apple", "banana", "orange", "strawberry", "grape", "pineapple"};
    const int numWords = sizeof(words) / sizeof(words[0]);

    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        srand(time(0));
        std::string word = words[rand() % numWords];
        std::string hiddenWord(word.length(), '_');

        int wrongAttempts = 0;
        const int maxWrongAttempts = 6;

        std::cout << "Hangman Game" << std::endl;
        std::cout << "Guess the word!" << std::endl;

        while (wrongAttempts < maxWrongAttempts) {
            std::cout << std::endl;
            displayHangman(wrongAttempts);

            std::cout << "Word: " << hiddenWord << std::endl;

            char guess;
            std::cout << "Enter your guess: ";
            std::cin >> guess;

            bool found = false;
            for (int i = 0; i < word.length(); ++i) {
                if (word[i] == guess) {
                    hiddenWord[i] = guess;
                    found = true;
                }
            }

            if (hiddenWord == word) {
                std::cout << "Congratulations! You guessed the word correctly: " << word << std::endl;
                break;
            }

            if (!found) {
                wrongAttempts++;
                std::cout << "Wrong guess! Try again." << std::endl;
            }
        }

        std::cout << std::endl;
        displayHangman(wrongAttempts);

        if (wrongAttempts == maxWrongAttempts) {
            std::cout << "Sorry, you couldn't guess the word. The word was: " << word << std::endl;
        }
        
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "Thank you for playing Hangman!" << std::endl;

    return 0;
}

/*
Developed a Hangman game in C++ utilizing procedural programming concepts.Implemented key functionalities such as word selection, letter guessing, and feedback display.
Incorporated interactive hangman figure based on the number of incorrect guesses. 
*/