#include <iostream>
#include <fstream>

#include "similarity.h"


int main()
{
	// read file called txtfiles/text.txt
	std::ifstream file("txtfiles/text.txt");
	std::string str;
	std::vector<std::string> phrases;
	while (std::getline(file, str))
	{
		phrases.push_back(str);
	}
	file.close();

	Similarity similarity(phrases);

	while (true)
	{
		std::cout << "Enter a phrase: ";
		std::getline(std::cin, str);
		if (str == "quit")
		{
			break;
		}

		std::unordered_map<std::string, double> results;
		for (const auto& phrase: phrases)
		{
			results[phrase] = angle_dot(similarity.get_vector(str), similarity.get_vector(phrase));
		}

		std::cout << "Results:" << std::endl;
		for (uint32_t i = 0; i < std::min(10, static_cast<int>(results.size())); i++)
		{
			double max = 0;
			std::string max_phrase;
			for (const auto& result: results)
			{
				if (result.second > max)
				{
					max = result.second;
					max_phrase = result.first;
				}
			}
			std::cout << max << " : " << max_phrase << std::endl;
			results.erase(max_phrase);
		}
	}


	return 0;
}