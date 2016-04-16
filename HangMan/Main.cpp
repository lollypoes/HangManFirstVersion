#include <iostream>
#include <string>
std::string Word = "HangMan";
int main() {
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

		//Check guess validity (is it a single letter?
		//If the guess is valid
			//Submit Guess for checking against the word
		//If not
			//Return appropreate error

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
	}
}