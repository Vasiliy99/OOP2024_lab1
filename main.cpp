#include "Header1.h"
int main()
{

	int stop = 0;
	int comm = 0;
	std::string crossword1;
	std::string word;
	while (stop != 1)
	{
		Put_comm();
		std::cin >> comm;
		while (!std::cin)
		{
			ErVVOD();
			std::cout << "Input Error!" << std::endl;
			std::cin >> comm;
		}

		switch (comm)
		{
		case 0:
		{
			stop = 1;
			break;
		}
		case 1:
		{
			std::cout << "Input your crossword word" << std::endl;

			std::cin.ignore();
			std::getline(std::cin, crossword1);

			std::vector <std::string> results{};

			try
			{
				results = Available_Words(crossword1);
				std::cout << "Found words:" << std::endl;
				for (int i = 0; i < results.size(); i++)
				{
					std::cout << results[i] << std::endl;
				}
			}

			catch (const std::string& error_message)
			{
				std::cout << error_message << std::endl;
			}

			results.clear();
			break;
		}
		case 2:
		{
			std::cout << "Input your crossword word" << std::endl;

			std::cin.ignore();
			std::getline(std::cin, word);

			char* crossword2 = new char[word.size() + 1];

			for (int i = 0; i < word.size(); i++)
			{
				crossword2[i] = word[i];
			}
			crossword2[word.size()] = '\0';

			std::vector <char*> results2{};

			try
			{
				results2 = Available_Words(crossword2);
				std::cout << "Found words:" << std::endl;
				for (int i = 0; i < results2.size(); i++)
				{
					std::cout << i << ": ";
					char* now = results2[i];
					for (int j = 0; j < word.size(); j++)
					{
						std::cout << now[j];
					}						
					delete[] now;
					std::cout << std::endl;
				}
			}

			catch (const std::string& error_message)
			{
				std::cout << error_message << std::endl;
			}

			word.clear();
			delete[] crossword2;

			results2.clear();
			break;
		}
		default:
		{
			std::cout << "Error input!" << std::endl;
			break;
		}
		}
	}
	return 0;
}
