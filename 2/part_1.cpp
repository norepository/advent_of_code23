
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

const int N_COLORS = 3;
const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

struct Colors {
	const std::string name;
	const int max;
};

const Colors colors[N_COLORS] = {
	{"red", MAX_RED},
	{"green", MAX_GREEN},
	{"blue", MAX_BLUE}
};

int firstInteger(std::string &s, int &start);
bool equals(const std::string &a, size_t start, const std::string &b);
bool isPossible(std::string &game);

int main() {
	std::string line = " ";
	std::ifstream input;
	input.open("input.txt", std::ios::in);
	if (input.is_open()) {
		int result = 0;
		for (int counter = 1; getline(input, line); ++counter) {
			std::cout << "Gioco numero: " << counter << "\tPossibile: ";
			if (isPossible(line)) { result += counter; std::cout << "si" << std::endl; }
			else std::cout << "no" << std::endl;
		}
		std::cout << "Risultato: " << result << std::endl;
		input.close();
	} else std::cout << "File non presente!" << std::endl;
	return 0;
}


bool isPossible(std::string &game) {
	int cursor = 0;
	while(game[cursor++] != ':');
	++cursor; //mi porto alla prima cifra

	while (cursor != game.length()) {
		int n = firstInteger(game, cursor);
		++cursor; //mi porto al primo carattere
		for (size_t i = 0; i < N_COLORS; ++i) {
			if (equals(game, cursor, colors[i].name)) {
				if (n > colors[i].max) return false; 
				cursor += colors[i].name.length();
			}
		}
	}
	return true;
}

int firstInteger(std::string &s, int &start) {
	int n = 0;
	while (std::isdigit(s[start])) {
		n *= 10;
		n += s[start++] - '0';
	}
	return n;
}

bool equals(const std::string &a, size_t start, const std::string &b) {
	if (a.length() < start + b.length()) return false;
	for (size_t i = start, j = 0; i < a.length() && j < b.length(); ++i, ++j) {
		if (a[i] != b[j]) return false;
	}
	return true;
}
