#include "HangMan.h"
///Getters
//Get the word length
int HangMan::GetWordLength() { return Word.length(); }
//Get the ammount of tries that the player has already had
int HangMan::GetTriesHad() { return TriesHad; }
//Get the status of how far dead the player is
int HangMan::GetHangManHangingStatus() { return HangManHangingStatus; }
//Get the letters that the player has already entered
std::string HangMan::GetLettersHad() { return LetterSeen; }

//Check the word's validity
EWordStatus HangMan::GetWordValidity(std::string Letter)
{
	if (Letter.length() != 1) {
		return EWordStatus::InvalidLength;
	}
	else if (isalpha(Letter[0]) == false) {
		return EWordStatus::NotALetter;
	}
	else if (std::string::npos != LetterSeen.find(toupper(Letter[0]))) {
		return EWordStatus::AlreadyHad;
	}
	else {
		return EWordStatus::Valid;
	}
	return EWordStatus();
}

//Submit the word for the system to check
GEuessSubmitStatus HangMan::SubmitGuess(std::string guess){
		//Add guess to letters already had list
		LetterSeen.append(guess);
		//Add another try to the try counter
		TriesHad++;
		for (auto Letter : Word) {
			if (Letter == guess[0]) {
				//The user has their guess was in the word
				return GEuessSubmitStatus::Correct;
			}
		}
		//Hang them a little more
		HangManHangingStatus++;
		//The user their guess was not in the word
		return GEuessSubmitStatus::Incorrect;
}

std::string HangMan::GetWord()
{
	return Word;
}


