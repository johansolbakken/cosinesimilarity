#pragma once

#include <vector>
#include <string>
#include <set>

using Vector = std::vector<uint32_t>;

std::vector<std::string> phrase_to_words(const std::string& phrase);


class Similarity
{
public:
	explicit Similarity(const std::vector<std::string>& world = {});

	void add_phrase(const std::string& phrase);

	Vector get_vector(const std::string& phrase);

private:
	std::set<std::string> word_bank;
};

double angle_dot(const Vector& vector1, const Vector& vector2);
