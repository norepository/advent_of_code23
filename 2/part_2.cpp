
#include <cctype>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

const int N_COLORS = 3;

struct Colors {
	const std::string name;
	int max;
};



int firstInteger(std::string &s, int &start);
bool equals(const std::string &a, size_t start, const std::string &b);
int power(std::string &game);

int main() {
	std::string line = " ";
	std::ifstream input;
	input.open("input.txt", std::ios::in);
	if (input.is_open()) {
		int result = 0;
		for (int counter = 1; getline(input, line); ++counter) {
			int temp = power(line);
			std::cout << "Gioco numero: " << counter << " Power: " << temp << std::endl;
			result += temp;
		}
		std::cout << "Risultato: " << result << std::endl;
		input.close();
	} else std::cout << "File non presente!" << std::endl;
	return 0;
}


int power(std::string &game) {
	Colors colors[N_COLORS] = {
		{"red", 0},
		{"green", 0},
		{"blue", 0}
	};
	int cursor = 0;
	while(game[cursor++] != ':');
	++cursor; //mi porto alla prima cifra
	while (cursor != game.length()) {
		int n = firstInteger(game, cursor);
		++cursor; //mi porto al primo carattere
		for (size_t i = 0; i < N_COLORS; ++i) {
			if (equals(game, cursor, colors[i].name) && n > colors[i].max) colors[i].max = n;
		}
	}

	int p = 1;
	for (int i = 0; i < N_COLORS; ++i) p *= colors[i].max;
	return p;
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
