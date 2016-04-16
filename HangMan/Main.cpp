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
	std::cout << "Please type in a letter!" << std::endl;
	std::getline(std::cin, Guess);

	//Check guess validity (is it a single letter?
	//If the guess is valid
		//Submit Guess for checking against the word
	//If not
		//Return appropreate error

}