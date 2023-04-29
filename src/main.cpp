#include "textgen.h"
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
	} else {
		std::cout << "file dont open";
	}
	fs.close();
	Markov gen = Markov(text, NPREF);
	std::cout << gen.Generator(MAXGEN);
}
