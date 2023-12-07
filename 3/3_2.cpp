
#include <cctype>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

const char gear = '*';
const size_t LENGTH = 140;

int gearRatio(std::string lines[LENGTH], size_t i, size_t j);
int convertToInteger(std::string &s, size_t &start);
int evaluate(std::string lines[]);

int main() {
	std::string lines[LENGTH + 1];
	std::ifstream input;
	input.open("data.txt", std::ios::in);
	if (input.is_open()) {
		for (int counter = 0; getline(input, lines[counter]); ++counter);
		std::cout << "Risultato: " << evaluate(lines) << std::endl;
		input.close();
	} else std::cout << "File non presente!" << std::endl;
	return 0;
}


int evaluate(std::string lines[LENGTH]) {
	int sum = 0;
	for (size_t i = 0; i < LENGTH - 1; ++i) {
		for (size_t j = 0; j < lines[i].length(); ++j) {
			if (lines[i][j] == gear) sum += gearRatio(lines, i, j);
		}
	}
	return sum;
}

int gearRatio(std::string lines[LENGTH], size_t i, size_t j) {
	int first = 0;
	int second = 0;
	int n = 0;
	int iMax = (i != LENGTH - 1)? i + 1 : i;
	int jMax = (j != lines[i].length() - 1)? j + 1 : j;
	if (i != 0) --i;
	if (j != 0) --j;
	while (i <= iMax) {
		size_t cursor = j;
		while (cursor <= jMax) {
			if (std::isdigit(lines[i][cursor])) {
				n = convertToInteger(lines[i], cursor);
				if (first == 0) first = n;
				else if (second == 0) second = n;
			}
			++cursor;
		}
		++i;
	}
	return first * second;
}

int convertToInteger(std::string &s, size_t &start) {
	int n = 0;
	while (std::isdigit(s[start]) && start >= 0) start--;
	while (std::isdigit(s[++start])) {
		n *= 10;
		n += s[start] - '0';
	}
	start--;
	return n;
}
