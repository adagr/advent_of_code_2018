#include "pch.h"

#include "advent_of_code.hpp"
#include <iostream>
#include <unordered_set>
#include "input_handler.hpp"

void AdventOfCode::day1a(std::vector<std::string> lines) {
	int sum{};
  for (const auto &line : lines)
		sum += std::stoi(line);
	std::cout << sum << "\n";
}

void AdventOfCode::day1b(std::vector<std::string> lines) {
  std::vector<int> frequencies{};
  for (const auto &line : lines)
    frequencies.push_back(std::stoi(line));

  std::unordered_set<int> uniqueFrequencies{};
  uniqueFrequencies.emplace(0);
  int sum{};
  while (true) {
    for (const auto &frequency : frequencies) {
      if (!uniqueFrequencies.emplace(sum += frequency).second) {
        std::cout << sum << "\n";
        return;
      }
    }
  }
}