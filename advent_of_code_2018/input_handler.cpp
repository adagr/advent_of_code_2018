#include "pch.h"
#include "input_handler.hpp"
#include <fstream>>

InputHandler::InputHandler(std::string fileName) { readFile(fileName); }

const std::vector<std::string>& InputHandler::getLines() const {
  return lines_; 
}

void InputHandler::readFile(std::string fileName) {
  lines_.clear();
  std::string line;
  std::ifstream myfile(fileName);
  if (!myfile.is_open())
    return;
  while (getline(myfile, line))
    lines_.push_back(line);
  myfile.close();
}