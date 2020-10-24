//
// Created by tkk on 19/10/2020.
//

#ifndef QUIZMAKER_QUIZ_H
#define QUIZMAKER_QUIZ_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <filesystem>
#include <cmath>

namespace fs = std::filesystem;

class Quiz
{

	fs::path questionsFilePath;
	std::string questionsFileName;


	std::string getLastLine();

	bool fileExists(const char *);

	size_t lastQuestionIndex();

public:

	Quiz(const std::string& fileName);

	Quiz(const char* fileName);

	bool addQuizQuestions();

	bool getRandomQuestions(size_t);

};

#endif //QUIZMAKER_QUIZ_H
