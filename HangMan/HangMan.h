#pragma once
#include <iostream>
#include <map>
enum class EWordStatus {
	Valid,
	AlreadyUsed,
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
	GEuessCheckStatus SubmitGuess(std::string);
	void Reset();
	void SetUp();
	void SetUp2();
	std::string word{ "Hello" };
	std::map<char, bool> LetterSeen;
	char Test[26]{ { 'A' },{ 'B' },{ 'C' },{ 'D' },{ 'E' },{ 'F' },{ 'G' },{ 'H' },{ 'I' },{ 'J' },{ 'K' },{ 'L' },{ 'M' },{ 'N' },{ 'O' },{ 'P' },{ 'Q' },{ 'R' },{ 'S' },{ 'T' },{ 'U' },{ 'V' },{ 'W' },{ 'X' },{ 'Y' },{ 'Z' }};
};