#include <iostream>
#include <string>
#include "HangMan.h"
void PlayGame();

int main() {
	PlayGame();
}

	void PlayGame() {
		//Set Up everything For The Game
		HangMan HangManGame;
		std::cout << "Welcome to hangman!" << std::endl;
		std::cout << std::endl;
		std::string Guess;

		//While you are NOT dead or the word is NOT guessed
		while (true) {
			//!!!MUST BE OPTIMIZED!!! Display current word status
			{
				int Count = 0;
				for (auto Letter : HangManGame.GetWord()) {
					Count++;
					//Loop through guesses already had
					bool IsLetterInWord = false;
					for (auto GuessLetter : HangManGame.GetLettersHad()) {
						if (toupper(Letter) == GuessLetter) {
							//Fine for this letter!
							IsLetterInWord = true;
							break;
						}
					}
					if (IsLetterInWord == false) {
						//Word incorrect
						if (Count < 8) {
							std::cout << " _ ";
						}
						else {
							Count = 0;
						}
					}
					else {
						std::cout << " " << Letter << "";
					}

				}
			}
			//Start of guess UI (display letters already used and ask for guess)
			{
				std::cout << std::endl << "Letters already used:     ";
				for (auto Letter : HangManGame.GetLettersHad()) {
					std::cout << Letter << ", ";
				}
				std::cout << std::endl;

				std::cout << "Please type in a letter!" << std::endl;
				std::getline(std::cin, Guess);
			}

			//Check if the input (Guess) is NOT a valid alphanumeric char, only 1 char long and has not been used before
			if (HangManGame.GetWordValidity(Guess) != EWordStatus::Valid) {
				EWordStatus WordStatus = HangManGame.GetWordValidity(Guess);
				//Check through the errors w/ a swith loop
				switch (WordStatus) {
				case EWordStatus::NotALetter:
					std::cout << "Your input was NOT an alphanumerical letter!";
					break;
				case EWordStatus::InvalidLength:
					std::cout << "Your input was the wrong length! Please insert something that is 1 character long!";
					break;
				case EWordStatus::AlreadyHad:
					std::cout << "Sorry to disturb, but you seem to have already had this character, there is no point in repeating!";
					break;
				}
			}
			else {
				Guess = toupper(Guess[0]);
				//Submit Guess for checking against the word
				GEuessSubmitStatus GuessSubmitStatus = HangManGame.SubmitGuess(Guess);
				if (GuessSubmitStatus == GEuessSubmitStatus::Correct) {
					//congratulate the user on a correct guess!
				}
				else {
					//Tell the user that the guess is incorrect
				}

			}
			//Check if have already been hung and inform the user if yes
			if (HangManGame.GetHangManHangingStatus() >= 10) {
				std::cout << "Nooooooooooooooooooooooooooooooooooo, You died :( Please try another time!" << std::endl;
				std::cout << "The word was: " + HangManGame.GetWord();
				return;

			}
			//!!!MUST BE OPTIMIZED!!! Check if the word has been guessed
			{
				int Count = 0;
				bool WordCorrect = true;
				for (auto Letter : HangManGame.GetWord()) {
					Count++;
					//Loop through guesses already had
					bool IsLetterInWord = false;
					for (auto GuessLetter : HangManGame.GetLettersHad()) {
						if (toupper(Letter) == GuessLetter) {
							//Fine for this letter!
							IsLetterInWord = true;
							break;
						}
					}
					if (IsLetterInWord == false) {
						//Word incorrect
						if (Count < 8) {
							WordCorrect = false;
						}
						else {
							Count = 0;
						}
					}
				}
				if (WordCorrect) {
					std::cout << "The word " << HangManGame.GetWord() << " was correct!";
					return;
				}
			}
		}
	}