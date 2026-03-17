#pragma once
#include <random>
#include <fstream>
#include <string>

inline int randomInt(int min, int max)
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution dis(min, max);
	return dis(mt);
}

inline std::string readFile(std::string filename)
{
	std::vector<std::string> lines;
	std::string line;
	std::ifstream myFile(filename);
	while (getline(myFile, line))
	{
		lines.push_back(line);
	}

	return lines[randomInt(0, lines.size() - 1)];
}
