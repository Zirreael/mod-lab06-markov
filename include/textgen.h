#pragma once
#include <stdlib.h>
#include <string>
#include <map>
#include <deque>
#include <vector>
#include <stdexcept>

typedef std::deque<std::string> prefix;
typedef std::vector<std::string> suffix;

class Markov {
public:
	std::map<prefix, suffix> statetab;
	Markov(std::string text, int nPref);
	Markov(std::map<prefix, suffix> table);
	std::string Generator(int maxLen);
};

std::vector<std::string> split(std::string str, std::string delimiter);