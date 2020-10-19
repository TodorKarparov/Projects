//
// Created by tkk on 19/10/2020.
//

#include "Quiz.h"

Quiz::Quiz(const std::string& fileName)
{
    questionsFile = "./QuizResources/" + fileName;
}

Quiz::Quiz(const char* fileName)
{
    std::string path("./QuizResources/");
    questionsFile = path + fileName;
}

std::string Quiz::getLastLine()
{
    std::ifstream in(questionsFile);
    std::string line;
    while (in >> std::ws && std::getline(in, line)) // skip empty lines
        ;

    return line;
}

bool Quiz::fileExists()
{
    std::string path = "./QuizResources/";
    for (const auto & entry : fs::directory_iterator(path))
    {
        if (entry.path() == questionsFile)
        {
            return true;
        }
    }

    return false;
}

size_t Quiz::lastQuestionIndex() {
    if (!fileExists()) {
        return 0;
    }

    std::string lastLine = getLastLine();
    size_t index = 0;

    size_t i;
    for (i = 0; lastLine[i] != '.'; ++i) {
        //get the last digit of the index
    }

    //go back before the '.'
    i--;

    //convert the index to an actual number type size_t

    for (size_t j = 0; i >= 0; ++j) {
        index = index + (lastLine[j] - 48) * pow(10, i);
        --i;
    }

    return index;
}

bool Quiz::addQuizQuestions()
{
    std::fstream quizFile(questionsFile, std::ios::app);
    if (!quizFile.is_open())
    {
        std::cerr << "File not open!";
        return false;
    }

    std::string input;
    std::getline(std::cin, input);

    while (!input.empty())
    {
        input.push_back('\n'); //add new line after each entry for human readability
        quizFile.write(input.c_str(), input.size());
        input.clear();
        std::getline(std::cin, input);
    }

    quizFile.close();

    return true;
}