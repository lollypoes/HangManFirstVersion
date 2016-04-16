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
