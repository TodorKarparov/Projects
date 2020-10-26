//
// Created by tkk on 19/10/2020.
//
#include "Quiz.h"

Quiz::Quiz(const std::string& fileName)
{
	questionsFilePath = "./QuizResources/" + fileName;
}

Quiz::Quiz(const char* fileName)
{
	std::string path("./QuizResources/");
	questionsFilePath = path + fileName;
}

std::string Quiz::getLastLine() const
{
	std::ifstream in(questionsFilePath);
	std::string line;
	while (in >> std::ws && std::getline(in, line)) // skip empty lines
		;

	return line;
}

std::string Quiz::getLine(size_t index) const
{
	std::fstream file(questionsFilePath);
	file.seekg(std::ios::beg);
	for (int i = 0; i < index - 1; ++i)
	{
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::string line;
	file >> line;
	return line;
}

bool Quiz::removeIndex(std::string& line)
{
	for (auto i = line.begin(); i != line.end(); i++)
	{
		if (*i == '.') {
			line.erase(line.begin(), i + 1);
			return true;
		}
	}

	return false;
}

bool Quiz::fileExists(const char* fileName)
{
	std::string path = "./";
	bool exists = false;
	for (const auto& entry : fs::directory_iterator(path))
	{
		if (entry.path() == "./QuizResources")
		{
			exists = true;
		}
	}

	if (!exists)
	{
		return false;
	}

	if (!strcmp(fileName, ""))
	{
		return true; //asking for empty file name equals asking if dir exists
	}

	exists = false;

	path = "./QuizResources";
	std::string filePath("./QuizResources/");
	filePath = filePath + fileName;
	for (const auto& entry : fs::directory_iterator(path))
	{
		if (entry.path() == filePath)
		{
			exists = true;
		}
	}

	return exists;
}

size_t Quiz::getQuestionIndex(const std::string& line)
{
	if (line.empty())
	{
		return 0;
	}
	size_t index = 0;

	size_t i;
	for (i = 0; line[i] != '.'; ++i)
	{
		//get the last digit of the index
	}

	//revert one step to not point at '.' position
	--i;

	//convert the index to an actual number type size_t
	for (size_t j = 0; i != SIZE_MAX; ++j)
	{
		index = index + (line[j] - 48) * pow(10, i);
		i--;
	}

	return index;
}

size_t Quiz::lastQuestionIndex() const
{
	if (!fileExists(questionsFileName.c_str()))
	{
		return 0;
	}

	return getQuestionIndex(getLastLine());
}

bool Quiz::addQuizQuestions()
{
	if (!fileExists(""))
	{
		bool success = fs::create_directory("./QuizResources");
		if (!success)
		{

			return false;
		}
	}

	std::fstream quizFile(questionsFilePath, std::ios::app);
	if (!quizFile.is_open())
	{
		std::cerr << "File not open!";
		return false;
	}

	std::string input;
	std::getline(std::cin, input);
	size_t startIndex = lastQuestionIndex() + 1;
	std::string question = std::to_string(startIndex++);

	while (!input.empty())
	{
		question = question.append(".").append(input);
		question.append("\n"); //add new line after each entry for human readability
		quizFile << question;
		input.clear();
		question.clear();
		quizFile.clear();
		std::getline(std::cin, input);
		question = std::to_string(startIndex++);
	}

	quizFile.close();

	return true;
}

bool Quiz::getRandomQuestions(size_t N, std::vector<std::string>& questionsList)
{
	if (!fileExists(questionsFileName.c_str()))
	{
		return false;
	}

	size_t numberOfQuestions = lastQuestionIndex();
	if (N > numberOfQuestions)
	{
		N = numberOfQuestions;
	}

	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed1);
	std::uniform_int_distribution<size_t> distribution(1, numberOfQuestions);
	std::unordered_set<size_t> chosenQuestions;
	size_t question;
	for (size_t i = 0; i < N; i++)
	{
		question = distribution(generator);
		while (chosenQuestions.contains(question))
		{
			question = distribution(generator);
		}
		chosenQuestions.insert(question);
	}
	std::string line;
	for (unsigned long chosenQuestion : chosenQuestions)
	{
		line = getLine(chosenQuestion);
		if (removeIndex(line))
		{
			questionsList.push_back(line);
		}
		else
		{
			return false;
		}
	}

	return true;
}