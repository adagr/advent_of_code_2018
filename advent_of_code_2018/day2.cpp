#include "pch.h"

#include "advent_of_code.hpp"
#include "input_handler.hpp"
#include <iostream>
#include <unordered_map>

void AdventOfCode::day2a(std::vector<std::string> lines) {
  unsigned twoOfAKind{};
  unsigned threeOfAKind{};
  for (const auto &line : lines) {
    std::unordered_map<char, unsigned> map;
    for (const auto &c : line)
      ++map[c];
    bool twoFound{false};
    bool threeFound{false};
    for (const auto &item : map) {
      if (!twoFound && item.second == 2) {
        twoFound = true;
        ++twoOfAKind;
      } else if (!threeFound && item.second == 3) {
        threeFound = true;
        ++threeOfAKind;
      }
    }
  }
  std::cout << twoOfAKind << " * " << threeOfAKind << " = "
            << twoOfAKind * threeOfAKind << "\n";
}

void AdventOfCode::day2b(std::vector<std::string> lines) {
  for (const auto &line : lines) {
    for (const auto &line2 : lines) {
      if (line == line2)
        continue;
      bool differ{false};
      for (unsigned i{}; i < line.size(); ++i) {
        if (!differ && line[i] != line2[i])
          differ = true;
        else if (line[i] != line2[i]) {
          differ = false;
          break;
        }
      }
      if (differ) {
        std::cout << line << " " << line2 << "\n";
        return;
      }
    }
  }
}