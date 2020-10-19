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

class Quiz {

    fs::path questionsFile;

    std::string getLastLine();

    bool fileExists();

public:

    Quiz(const std::string& fileName);

    Quiz(const char* fileName);

    size_t lastQuestionIndex();

    bool addQuizQuestions();

};

#endif //QUIZMAKER_QUIZ_H
