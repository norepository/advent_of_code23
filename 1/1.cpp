#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

const int N_CIFRES = 9;

const std::string numbers[N_CIFRES] = {
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

bool equals(const std::string &a, size_t start, const std::string &b) {
	if (a.length() < start + b.length()) return false;
	for (size_t i = start, j = 0; i < a.length() && j < b.length(); ++i, ++j) {
		if (a[i] != b[j]) return false;
	}
	return true;
}

int evaluate(std::string &line, std::size_t &cursor) {
	for (size_t i = 0; i < N_CIFRES; i++) {
		if (isdigit(line[cursor])) return line[cursor] - '0';
		else if (equals(line, cursor, numbers[i])) {
			cursor += numbers[i].length() - 2;
			return i + 1;
		}
	}
	return 0;
}

int takeIntegers(std::string line) {
	int first = 0;
	int last = 0;
	int n = 0;
	for (size_t i = 0; i < line.length(); ++i) {
		n = evaluate(line, i);
		if (first == 0) first = n;
		if (n != 0) last = n;
	}
	if (last == 0) last = first;
	return first * 10 + last;
}

int main() {
	std::string line = " ";
	std::ifstream input;
	input.open("data.txt", std::ios::in);
	if (input.is_open()) {
		int sum = 0;
		while (getline(input, line)) {
			int temp = takeIntegers(line);
			std::cout << line << "  Nmbers:" << temp << std::endl;
			sum += temp;
		}
		std::cout << sum << std::endl;
		input.close();
	} else std::cout << "File non presente!" << std::endl;
	return 0;
}