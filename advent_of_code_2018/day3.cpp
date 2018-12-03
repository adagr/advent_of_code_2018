#include "pch.h"

#include "advent_of_code.hpp"
#include <iostream>
#include <unordered_map>
#include <unordered_set>

void getLine(const std::string& line, int &column, int &row, int &width, int &height) {
  size_t at{line.find("@")};
  size_t comma = line.find(",");
  size_t colon = line.find(":");
  size_t x = line.find("x");
  column = std::stoi(line.substr(at + 2, comma - 2 - at));
  row = std::stoi(line.substr(comma + 1, colon - 1 - comma));
  width = std::stoi(line.substr(colon + 2, x - 2 - colon));
  height = std::stoi(line.substr(x + 1, line.length() - 1 - x));
}

void AdventOfCode::day3a(std::vector<std::string> lines) {
  std::unordered_map<int, std::unordered_map<int, int>> fabric{};
  int overlap{};
  for (const auto &line : lines) {
    int column{}, row{}, width{}, height{};
    getLine(line, column, row, width, height);
    for (int i = column; i < column + width; ++i)
      for (int j = row; j < row + height; ++j) {
        if (fabric[i][j] == 1)
          ++overlap;
        ++fabric[i][j];
      }
  }
  std::cout << overlap << "\n";
}

void AdventOfCode::day3b(std::vector<std::string> lines) {
  std::unordered_map<int, std::unordered_map<int, int>> fabric{};
  for (const auto &line : lines) {
    int column{}, row{}, width{}, height{};
    getLine(line, column, row, width, height);
    for (int i = column; i < column + width; ++i)
      for (int j = row; j < row + height; ++j)
        ++fabric[i][j];
  }

  for (const auto &line : lines) {
    int column{}, row{}, width{}, height{};
    getLine(line, column, row, width, height);
    bool overlap{false};
    for (int i = column; i < column + width; ++i) {
      for (int j = row; j < row + height; ++j)
        if (fabric[i][j] > 1) {
          overlap = true;
          break;
        }
      if (overlap)
        break;
    }
    if (!overlap) {
      std::cout << line.substr(1, line.find("@") - 2) << "\n";
      return;
    }
  }
}