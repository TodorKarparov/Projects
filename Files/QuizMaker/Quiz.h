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
#include <vector>
#include <random>
#include <unordered_set>
#include <limits>

namespace fs = std::filesystem;

class Quiz
{

	fs::path questionsFilePath;
	std::string questionsFileName;

	[[nodiscard]] std::string getLastLine() const;

	static bool fileExists(const char*);

	static size_t getQuestionIndex(const std::string&);

	[[nodiscard]] size_t lastQuestionIndex() const;

	static bool removeIndex(std::string&);

	[[nodiscard]] std::string getLine(size_t index) const;

public:

	explicit Quiz(const std::string& fileName);

	explicit Quiz(const char* fileName);

	bool addQuizQuestions();

	bool getRandomQuestions(size_t, std::vector<std::string>&);

};

#endif //QUIZMAKER_QUIZ_H
