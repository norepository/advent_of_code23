
#include <cctype>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

const char notValid = '.';
const size_t LENGTH = 140;

int nCifresOf(int n);
bool isSymbol(char &c);
bool symbolIsNear(std::string lines[LENGTH], size_t i, size_t j, size_t l);
int convertToInteger(std::string &s, size_t start);
bool equals(const std::string &a, size_t start, const std::string &b);
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
	for (size_t i = 0; i < LENGTH; ++i) {
		for (size_t j = 0; j < lines[i].length(); ++j) {
			//debug lines
			if (std::isdigit(lines[i][j])) {
				int n = convertToInteger(lines[i], j);
				int l = nCifresOf(n);
				bool symbolNear = symbolIsNear(lines, i, j, l);
				if (symbolNear) sum += n;
				j += l; 
				std::cout << "Riga: " << i + 1 << " Numero: " << n << " Simboli vicini: " << symbolNear << std::endl;
			}
		}
	}
	return sum;
}



bool symbolIsNear(std::string lines[LENGTH], size_t i, size_t j, size_t l) {
	if (j != 0) { j--; l++; }
	for (size_t cursor = 0; cursor < l + 1 && j + cursor < lines[i].length() - 1; ++cursor) {
		if (isSymbol(lines[i][j + cursor])) return true;
		if (i != 0 && isSymbol(lines[i - 1][j + cursor])) return true;
		if (i != LENGTH - 1 && isSymbol(lines[i + 1][j + cursor])) return true;
	}
	return false;
}


bool isSymbol(char &c) {
	if (!isdigit(c) && c != notValid) return true;
	return false;
}

int nCifresOf(int n) {
	int i = 0;
	while (n != 0) {
		n /= 10;
		i++;
	}
	return i;
}

int convertToInteger(std::string &s, size_t start) {
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

