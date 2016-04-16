#include "HangMan.h"
#include <set>

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

GEuessCheckStatus HangMan::SubmitGuess(std::string Guess)
{
	LetttersHad.insert(Guess[0]).second;
	return GEuessCheckStatus();
}

void HangMan::SetUp()
{
	for (char letter : word)
	{
		if (set.insert(letter).second)
			std::cout << letter << " successfully inserted." << std::endl;
	}
}
