#pragma once
#include <iostream>
#include <set>
enum class EWordStatus {
	Valid,
	AlreadyHad,
	NotALetter,
	InvalidLength
};
enum class GEuessCheckStatus{
	Correct,
	Incorrect
};
class HangMan {
private:
	std::string Word = "HangMan";
	int WordLength = 0;
	int HangManHangingStatus = 0;
	//std::string LettersHad[];
public:
	EWordStatus GetWordValidity(std::string Letter);
	int GetWordLength();
	int GetTriesHad();
	int GetHangManHangingStatus();
	std::string GetLettersHad();
	bool SubmitGuess(std::string);
	void Reset();
	std::string LetterSeen;
};