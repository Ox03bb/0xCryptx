#ifndef POLYBIUS_H
#define POLYBIUS_H

#include <string>
#include <vector>

struct pos {
    int row;
    int col;
};

class polybius {
  public:
    // Default 8x8 grid
    inline static const std::vector<std::vector<char>> default_arr = {
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}, {'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'}, {'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f'},
        {'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'}, {'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
        {'w', 'x', 'y', 'z', '1', '2', '3', '4'}, {'5', '6', '7', '8', '9', '0', '.', ','}};

    static std::string encrypt(std::string raw, std::vector<std::vector<char>> arr = default_arr,
                               const char *x_key = "12345678", const char *y_key = "12345678");
    static std::string decrypt(std::string raw, std::vector<std::vector<char>> arr = default_arr,
                               const char *x_key = "12345678", const char *y_key = "12345678");

  private:
    static pos arr_find(std::vector<std::vector<char>> arr, char c);
    static int vec_find(const char *vec, char c);
};

#endif // POLYBIUS_H