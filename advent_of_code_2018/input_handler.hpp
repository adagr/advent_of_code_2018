#pragma once
#include <vector>
#include <string>

class InputHandler {

public:
  InputHandler() = default;
  ~InputHandler() = default;

  const std::vector<std::string>& getLines() const;
  void readFile(std::string fileName);

private:
  std::vector<std::string> lines_;
};