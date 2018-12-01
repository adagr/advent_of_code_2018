#include "pch.h"
#include <iostream>
#include "advent_of_code.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

void AdventOfCode::day1a() {
	std::string line;
	std::ifstream myfile("day1.txt");
	if (!myfile.is_open())
		return;
	int sum{};
	while (getline(myfile, line)) {
		sum += std::stoi(line);
	}
	std::cout << sum << "\n";
	myfile.close();
}

void AdventOfCode::day1b() {
  std::string line;
  std::ifstream myfile("day1.txt");
  if (!myfile.is_open())
    return;
  std::vector<int> frequencies{};
  while (getline(myfile, line)) {
    frequencies.push_back(std::stoi(line));
  }
  myfile.close();

  std::unordered_map<int, bool> uniqueFrequencies{};
  uniqueFrequencies[0] = true;
  int sum{};
  while (true) {
    for (const auto &frequency : frequencies) {
      sum += frequency;
      if (uniqueFrequencies[sum]) {
        std::cout << sum << "\n";
        return;
      }
      uniqueFrequencies[sum] = true;
    }
  }
}