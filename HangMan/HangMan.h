#pragma once
#include <iostream>
enum class EWordStatus {
	Valid,
	AlreadyHad,
	NotALetter
};
class HangMan {
private:
	std::string Word = "HangMan";
	int WordLength = 0;
	int HangManHangingStatus = 0;
	std::string LettersHad[];
public:
	EWordStatus GetWordValidity();
	int GetWordLength();
	int GetTriesHad();
	int GetHangManHangingStatus();
	std::string GetLettersHad();
	void Reset();
};