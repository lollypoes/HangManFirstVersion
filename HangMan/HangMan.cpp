#include "HangMan.h"
EWordStatus HangMan::GetWordValidity(std::string Letter)
{
	if (Letter.length() != 1) {
		return EWordStatus::InvalidLength;
	}
	else if (isalpha(Letter[0]) == false) {
		return EWordStatus::NotALetter;
	}
	else {
		return EWordStatus::Valid;
	}
	return EWordStatus();
}

bool HangMan::SubmitGuess(char guess){
		if (0 < LetterSeen.count(guess)) // already tried
			return false;
		else {
			LetterSeen.insert(guess);
			return true; //for testing return that it is valid
		}
	return false;
}


