#pragma once
#include <iostream>
#include <set>
enum class EWordStatus {
	Valid,
	AlreadyHad,
	NotALetter,
	InvalidLength
};
enum class GEuessSubmitStatus{
	Correct,
	Incorrect
};
class HangMan {
private:
	std::string Word = "HangMan";
	int WordLength = 0;
	int HangManHangingStatus = 0;
	std::string LetterSeen;
	int TriesHad;
public:
	EWordStatus GetWordValidity(std::string Letter);
	int GetWordLength();
	int GetTriesHad();
	int GetHangManHangingStatus();
	std::string GetLettersHad();
	GEuessSubmitStatus SubmitGuess(std::string);
	void Reset();
};