#ifndef SCYTALE_H
#define SCYTALE_H

#include <string>
#include <vector>

class scytale {
  public:
    static std::string encript(std::string raw, int rows, char extra = '#');

  private:
    static std::string read_row(std::vector<std::vector<char>> arr);
    static std::string read_col(std::vector<std::vector<char>> arr);
};

#endif // SCYTALE_H