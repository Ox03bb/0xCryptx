#ifndef VIGEMERE_H
#define VIGEMERE_H

#include <string>
#include <vector>

class vigenere {
  public:
    static std::string encrypt(std::string raw, std::string key);
    static std::string decrypt(std::string raw, std::string key);

  private:
    static char k_adder(char c, char k);
    static char k_sub(char c, char k);
};

#endif // VIGEMERE_H