// Markov.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "textgen.h"

Markov::Markov(std::string text, int nPref = 2) {
    if (nPref >= text.length())
        std::cout << "error: pref > text length";
    statetab = std::map<prefix, suffix>();
    prefix pref = prefix();
    std::vector<std::string> words = split(text, " ");
    for (int i = 0; i < nPref; i++) {
        pref.push_back(words[i]);
    }
    for (int i = 0; i < words.size(); i++) {
        if (statetab.find(pref) == statetab.end()) {
            suffix suf = suffix();
            suf.push_back(words[i]);
            statetab[pref] = suf;
        } else {
            statetab[pref].push_back(words[i]);
        }
        pref.pop_front();
        pref.push_back(words[i]);
    }
}

Markov::Markov(std::map<prefix, suffix> table) {
    statetab = table;
}

std::string Markov::Generator(int maxLen) {
    std::string result;
    prefix pref = statetab.begin()->first;
    for (int i = 0; i < pref.size(); i++) {
        result += pref[i] + " ";
    }
    std::srand(1);
    while (result.length() < maxLen) {
        if (statetab.find(pref) == statetab.end()) {
            break;
        }
        suffix suf = statetab[pref];
        int numb = std::rand() % suf.size();
        result += suf[numb] + " ";
        pref.pop_front();
        pref.push_back(suf[numb]);
    }
    return result;
}

std::vector<std::string> split(std::string str, std::string delimiter) {
    size_t start = 0, end, delLengh = delimiter.length();
    std::string str1;
    std::vector<std::string> result;
    end = str.find(delimiter, start);
    while (end != std::string::npos) {
        str1 = str.substr(start, end - start);
        start = end + delLengh;
        result.push_back(str1);
        end = str.find(delimiter, start);
    }
    result.push_back(str.substr(start));
    return result;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
