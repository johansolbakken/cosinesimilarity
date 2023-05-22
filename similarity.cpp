#include "similarity.h"

std::vector<std::string> phrase_to_words(const std::string& phrase)
{
	std::vector<std::string> words;
	std::string word;
	for (auto c: phrase)
	{
		if (isalpha(c))
		{
			word += tolower(c);
		}
		else if (c == ' ')
		{
			words.push_back(word);
			word = "";
		}
	}
	words.push_back(word);
	return words;
}

double angle_dot(const Vector& vector1, const Vector& vector2)
{
	assert(vector1.size() == vector2.size());

	double dot = 0;
	for (size_t i = 0; i < vector1.size(); i++)
	{
		dot += vector1[i] * vector2[i];
	}

	double length1 = 0;
	for (auto i: vector1)
	{
		length1 += i * i;
	}

	double length2 = 0;
	for (auto i: vector2)
	{
		length2 += i * i;
	}

	return dot / (sqrt(length1) * sqrt(length2));
}

Similarity::Similarity(const std::vector<std::string>& world)
{
	for (const auto& phrase: world)
	{
		for (const auto& word: phrase_to_words(phrase))
		{
			word_bank.insert(word);
		}
	}
}

void Similarity::add_phrase(const std::string& phrase)
{
	for (const auto& word: phrase_to_words(phrase))
	{
		word_bank.insert(word);
	}
}

Vector Similarity::get_vector(const std::string& phrase)
{
	std::vector<uint32_t> vector(word_bank.size(), 0);
	for (const auto& word: phrase_to_words(phrase))
	{
		auto it = word_bank.find(word);
		if (it != word_bank.end())
		{
			vector[std::distance(word_bank.begin(), it)]++;
		}
	}
	return vector;
}
