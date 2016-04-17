#include "HangMan.h"
EWordStatus HangMan::GetWordValidity(std::string Letter)
{
	if (Letter.length() != 1) {
		return EWordStatus::InvalidLength;
	}
	else if (isalpha(Letter[0]) == false) {
		return EWordStatus::NotALetter;
	}
	else if (std::string::npos != LetterSeen.find(toupper(Letter[0]))) { // already tried
		return EWordStatus::AlreadyHad;
	}
	else {
		return EWordStatus::Valid;
	}
	return EWordStatus();
}

GEuessSubmitStatus HangMan::SubmitGuess(std::string guess){
		LetterSeen.append(guess);
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


