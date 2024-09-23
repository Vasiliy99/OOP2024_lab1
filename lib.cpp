#include "Header1.h"

std::vector<std::string> Available_Words(const std::string& crossword)
{
	std::vector<std::string> result{};

	for (int i = 0; i < crossword.size(); i++)
	{
		if (crossword[i] != '?' and (int(crossword[i]) > 122 or int(crossword[i]) < 65 or (int(crossword[i]) > 90 and int(crossword[i]) < 97)))
		{
			result.clear();
			throw std::string{ "Unable crossword word!" };
		}
	}

	std::string line;
	std::ifstream in("TextFile1.txt");
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			if (line.size() - 1 == crossword.size())
			{
				for (int i = 0; i < crossword.size(); i++)
				{
					if (crossword[i] != line[i] and crossword[i] != '?')
					{
						break;
					}
					if ((crossword[i] == line[i] or crossword[i] == '?') and i == crossword.size() - 1)
					{
						result.push_back(line);
					}
				}
			}
		}
	}
	in.close();
	return result;
}

std::vector <char*> Available_Words(const char* crossword)
{

	std::vector<char*> result{};

	int i = 0;
	while (crossword[i] != '\0')
	{
		i++;
	}
	int size1 = i;

	for (i=0; i<size1; i++)
	{
		if (crossword[i] != '?' and (int(crossword[i]) > 122 or int(crossword[i]) < 65 or (int(crossword[i]) > 90 and int(crossword[i]) < 97)))
		{
			result.clear();
			throw std::string{ "Unable crossword word!" };
		}
	}

	std::string line;
	std::ifstream in("TextFile1.txt");
	if (in.is_open())
	{
		while (std::getline(in, line))
		{

			if (line.size() - 1 == size1)
			{
				for (i = 0; i < size1; i++)
				{
					if (crossword[i] != line[i] and crossword[i] != '?')
					{
						break;
					}
					if ((crossword[i] == line[i] or crossword[i] == '?') and i == size1 - 1)
					{
						char* line1 = new char[line.size()];
						for (i = 0; i < line.size(); i++)
						{
							line1[i] = line[i];
							std::cout << line1[i];
						}
						std::cout << std::endl;
						result.push_back(line1);
					}
				}
			}
		}
	}
	in.close();
	return result;
}

void ErVVOD()
{
	std::cout << "Input Error!" << std::endl;
	scanf("%*[^\n]%*c");
	std::cin.clear();
}

void Put_comm()
{
	std::cout << std::endl;
	std::cout << "Choose command:" << std::endl;
	std::cout << "0 - close programm" << std::endl;
	std::cout << "1 - find available words with string type" << std::endl;
	std::cout << "2 - find available words with char* type" << std::endl;
	std::cout << std::endl;
}
