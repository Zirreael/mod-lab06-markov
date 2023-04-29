// Copyright 2023 Zirraeal VisualStudio
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
    explicit Markov(std::string text, int nPref);
    explicit Markov(std::map<prefix, suffix> table);
    std::string Generator(int maxLen);
};

std::vector<std::string> split(std::string str, std::string delimiter);
