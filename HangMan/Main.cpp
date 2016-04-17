#include <iostream>
#include <string>
#include "HangMan.h"
std::string Word = "HangMan";
int main() {
	//Create A new HangMan class
	HangMan HangManGame;
	std::cout << "Welcome to hangman!" << std::endl;
	for (int Letter = Word.length(); Letter > 0; Letter--) {
		std::cout << "__ ";
	}
	std::cout << std::endl;
	std::string Guess;

	//While you are NOT dead or the word is NOT guessed
	while (true) {
		std::cout << "Please type in a letter!" << std::endl;
		std::getline(std::cin, Guess);
		//Check if the input (Guess) is NOT a valid alphanumeric char, only 1 char long and has not been used before
		if (HangManGame.GetWordValidity(Guess) != EWordStatus::Valid) {
			//The word is not valid so checking for which error must occur, printing out the error to the user

			//store it in a variable for ez access
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
		else { //The input is valid
			//Convert the guess to upper case
			Guess = toupper(Guess[0]);
			//Submit Guess for checking against the word
			GEuessSubmitStatus GuessSubmitStatus = HangManGame.SubmitGuess(Guess);
			if (GuessSubmitStatus == GEuessSubmitStatus::Correct) {
				//congratulate the user on a correct guess!
			}
			else {
				//Tell the user that the guess is incorrect
			}
			std::cout << "Letters Used: " << std::endl;
			for (auto Letter : HangManGame.GetLettersHad()) {
				std::cout << Letter << ", ";
			}
		}

		//Check if you are dead
		//If you are dead
			//Tell the player they lost and this round
		//If not
			//Do Nothing
		
		//Check if the word is guessed
		//If yes
			//Congradulate the player and end round
		//If no
			//Do Nothing
		

		//print out the letters that have already been used!
		
		

	}
}