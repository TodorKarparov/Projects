#include "Quiz.h"


int main()
{
	Quiz a("quiz.txt");
	std::vector<std::string> questions;
	bool success = a.getRandomQuestions(3, questions);
	if (success)
	{
		for (const std::string& x : questions)
		{
			std::cout << x << std::endl;
		}
	}

	return 0;
}
