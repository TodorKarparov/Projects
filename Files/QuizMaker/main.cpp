#include <iostream>
#include "Quiz.h"


int main()
{
	Quiz a("quiz.txt");
	std::cout << a.addQuizQuestions();
	return 0;
}
