#include "HangMan.h"
EWordStatus HangMan::GetWordValidity(std::string Letter)
{
	/*bool LetterAlreadyUsed = false;
	for (int i = 0; i <= 26; i++) {
		if (LetterSeen[Test[i]] == Letter[0]) {
			LetterAlreadyUsed = true;
			break;
		}
	}*/
	if (Letter.length() != 1) {
		return EWordStatus::InvalidLength;
	}
	else if (isalpha(Letter[0]) == false) {
		return EWordStatus::NotALetter;
	}
	else if (false) {
		return EWordStatus::AlreadyUsed;
	}
	else {
		return EWordStatus::Valid;
	}
	return EWordStatus();
}

GEuessCheckStatus HangMan::SubmitGuess(std::string Guess)
{
	LetterSeen[Guess[0]] = true;
	return GEuessCheckStatus();
}
