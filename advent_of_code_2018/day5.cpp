#include "pch.h"

#include "advent_of_code.hpp"
#include <iostream>
#include <cmath>

void AdventOfCode::day5a(std::vector<std::string> lines) {
  std::string line{lines[0]};
  for (int i{}; i < line.size() - 1; ++i) {
    if (std::abs(line[i] - line[i + 1]) == 32) {
      line = line.substr(0, i) + line.substr(i+2, line.size() - i);
      i -= 2;
      if (i < 0)
        i = -1;
    }
  }
  std::cout << line.size() << "\n";
}

void AdventOfCode::day5b(std::vector<std::string> lines) {
  int shortestPoly{INT_MAX};
  for (int i = 'A'; i < 'Z'; ++i) {
    std::string line{lines[0]};
    for (int j{}; j < line.size(); ++j) {
      if (line[j] == i || line[j] == i + 32) {
        line = line.substr(0, j) + line.substr(j + 1, line.size() - j);
        j -= 2;
      } else if (std::abs(line[j] - line[j + 1]) == 32) {
        line = line.substr(0, j) + line.substr(j + 2, line.size() - j);
        j -= 2;
        if (j < 0)
          j = -1;
      }
    }
    if (line.size() < shortestPoly)
      shortestPoly = line.size();
  }
  std::cout << shortestPoly << "\n";
}