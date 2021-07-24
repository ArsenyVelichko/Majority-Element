#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

int findMostFrequent(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Empty numbers vector");
    }

    int fastIt = 0;
    int slowIt = 0;
    while (fastIt < numbers.size()) {
        if (numbers[slowIt] != numbers[fastIt]) {
            if (numbers[slowIt + 1] != numbers[slowIt]) {
                slowIt = fastIt;
            } else {
                slowIt++;
            }
        }
        fastIt++;
    }
    return numbers[slowIt];
}

int main() {
    std::ifstream file("tests.txt");
    if (!file.is_open()) {
        std::cout << "File wasn't opened";
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream numberStream(line);
        std::vector<int> numbers;

        int number;
        while (numberStream >> number) {
            numbers.push_back(number);
        }

        try {
            std::cout << findMostFrequent(numbers) << std::endl;
        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}