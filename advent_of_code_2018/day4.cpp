#include "pch.h"

#include "advent_of_code.hpp"
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <map>

class Timestamp {

public:
  Timestamp() = default;
  Timestamp(std::string line)
      : year{std::stoi(line.substr(1, 4))}, month{std::stoi(line.substr(6, 2))},
        day{std::stoi(line.substr(9, 2))}, hour{std::stoi(line.substr(12, 2))},
        minute{std::stoi(line.substr(15, 2))}, line{line} {}

  std::string line;

  friend std::ostream &operator<<(std::ostream &os, const Timestamp &dt) {
    os << dt.year << '-' << dt.month << '-' << dt.day << ':' << dt.hour << ':'
       << dt.minute << " " << dt.line.substr(19, dt.line.length() - 19);
    return os;
  }

  friend bool operator<(const Timestamp &lhs, const Timestamp &rhs) {
    if (lhs.year == rhs.year) {
      if (lhs.month == rhs.month) {
        if (lhs.day == rhs.day) {
          if (lhs.hour == rhs.hour) {
            return lhs.minute <= rhs.minute;
          }
          return lhs.hour <= rhs.hour;
        }
        return lhs.day <= rhs.day;
      }
      return lhs.month <= rhs.month;
    }
    return lhs.year <= rhs.year;
  }

  const int &operator-(const Timestamp &rhs) {
    return this->minute - rhs.minute;
  }

  int year, month, day, hour, minute;
};

void AdventOfCode::day4a(std::vector<std::string> lines) {
  std::set<Timestamp> list;
  for (auto &line : lines) {
    list.emplace(*(new Timestamp(line)));
  }

  std::unordered_map<int, std::map<int, int>> bestMinute{};
  int currentGuard{};
  Timestamp startTime;
  std::unordered_map<int, int> sleepTime{};
  for (auto line : list) {
    size_t guard = line.line.find("#");
    if (guard != std::string::npos)
      currentGuard = std::stoi(line.line.substr(guard + 1, line.line.find(" begins") - (guard - 1)));
    else if (line.line.find("wakes up") != std::string::npos) {
      for (int i{startTime.minute}; i < line.minute; ++i)
        bestMinute[currentGuard][i]++;
      sleepTime[currentGuard] += line - startTime;
    }
    else if (line.line.find("falls asleep") != std::string::npos)
      startTime = line;
  }

  std::pair<int, int> bestGuard{};
  for (auto &guard : sleepTime) {
    if (guard.second > bestGuard.second)
      bestGuard = guard;
  }
  std::pair<int, int> asd{};
  for (auto minute : bestMinute[bestGuard.first]) {
    if (minute.second > asd.second)
      asd = minute;
  }

  std::cout << bestGuard.first << " " << asd.first << " = " << bestGuard.first * asd.first << "\n";

  // PART 2
  
  int longestMinute{};
  bestGuard = std::pair<int, int>{};
  for (auto &guard : bestMinute) {
    for (auto &minute : guard.second) {
      if (minute.second > longestMinute) {
        longestMinute = minute.second;
        bestGuard = std::make_pair(guard.first, minute.first);
      }
    }
  }
  std::cout << bestGuard.first * bestGuard.second << "\n";
}

void AdventOfCode::day4b(std::vector<std::string> lines) {}