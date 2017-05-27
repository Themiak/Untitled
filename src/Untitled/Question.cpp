#include "stdafx.h"
#include "Question.h"

Question::Question()
{
}
Question::~Question()
{
}
void Question::setQuestion(std::string str)
{
	question = str;
}
void Question::setA(std::string str)
{
	A.answerABCD = str;
}
void Question::setB(std::string str)
{
	B.answerABCD = str;
}
void Question::setC(std::string str)
{
	C.answerABCD = str;
}
void Question::setD(std::string str)
{
	D.answerABCD = str;
}
void Question::setCorrect(char a)
{
	switch (a)
	{
	case 'A':
		A.correct = true;
		break;
	case 'B':
		B.correct = true;
		break;
	case'C':
		C.correct = true;
		break;
	case'D':
		D.correct = true;
		break;
	default:;
	}
}