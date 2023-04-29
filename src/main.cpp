#include "markov.h"
#include <iostream>
#include <fstream>

int main() {
	const int NPREF = 2;
	const int MAXGEN = 1000;
	setlocale(LC_ALL, "Russian");
	std::string text = " ";
	std::string line;
	std::ifstream fs("text.txt");
	if (fs.is_open()) {
		while (getline(fs, line)) {
			text += line;
		}
	}
	else {
		std::cout << "file dont open";
	}
	fs.close();
	//std::cout << text + "\n";
	std::string text1 = "one fish two fish red fish blue fish";
	Markov gen = Markov(text1, NPREF);
	std::cout << gen.Generator(1000);
	prefix pref = prefix();
	pref.push_back("one");
	pref.push_back("fish");
	std::string s = gen.statetab[pref][0];
	std::cout << "\n";
	std::cout << s;
}
