#pragma once
#include <iostream>
enum class EWordStatus {
	Valid,
	AlreadyHad,
	NotALetter,
	InvalidLength
};
class HangMan {
private:
	std::string Word = "HangMan";
	int WordLength = 0;
	int HangManHangingStatus = 0;
	std::string LettersHad[];
public:
	EWordStatus GetWordValidity(std::string Letter);
	int GetWordLength();
	int GetTriesHad();
	int GetHangManHangingStatus();
	std::string GetLettersHad();
	void Reset();
};