#pragma once
#include <string>


class Question
{
public:
	Question();
	~Question();
	void setQuestion(std::string str);
	void setA(std::string str);
	void setB(std::string str);
	void setC(std::string str);
	void setD(std::string str);
	void setCorrect(char a);
	answer A, B, C, D;
	std::string question;
};

