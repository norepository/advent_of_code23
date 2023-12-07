
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

int firstInteger(std::string &s, size_t &start);
int evaluate(std::string &card);
void nIntegers(int array[], size_t l, std::string &s, size_t &start, char c = '\n');
bool find(int array[], size_t l, int n);

int main() {
	std::string line = " ";
	std::ifstream input;
	input.open("data.txt", std::ios::in);
	if (input.is_open()) {
		int result = 0;
		for (int counter = 1; getline(input, line); ++counter) result += evaluate(line);
		std::cout << "Risultato: " << result << std::endl;
		input.close();
	} else std::cout << "File non presente!" << std::endl;
	return 0;
}


int evaluate(std::string &card) {
    int result = 0;
    size_t cursor = 0;
    const int Nwinning = 10;
    const int Nmy = 25;

    int winningNumbers[Nwinning];
    int myNumbers[Nmy];

    while(card[cursor++] != ':');

    nIntegers(winningNumbers, Nwinning, card, cursor, '|');
    std::cout << "Ciao" << std::endl;
    nIntegers(myNumbers, Nmy, card, cursor);
    std::cout << "Numeri vincenti: ";
    for (size_t i = 0; i < Nwinning; ++i) {
        std::cout << winningNumbers[i] << " ";
        if (find(myNumbers, Nmy, winningNumbers[i])) result++;
    }
    std::cout << std::endl;
    std::cout << result << " " << pow(2, result) << std::endl;
	return pow(2, result - 1);
}

bool find(int array[], size_t l, int n) {
    for (size_t i = 0; i < l; ++i) {
        if (array[i] == n) return true;
    }
    return false;
}

void nIntegers(int array[], size_t l, std::string &s, size_t &start, char c) {
    for (size_t i = 0; i < l;) {
        if(isdigit(s[start])) array[i++] = firstInteger(s, start);
        else start++;
    }
}

int firstInteger(std::string &s, size_t &start) {
	int n = 0;
	while (std::isdigit(s[start])) n = n * 10 + s[start++] - '0';
	return n;
}


