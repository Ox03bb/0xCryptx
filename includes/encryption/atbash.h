#ifndef ATBASH_H
#define ATBASH_H

#include <string>

class atbash {
  public:
    static std::string encrypt(std::string raw);
    static std::string decrypt(std::string raw);

  private:
    static char miror(char c);
};

#endif // ATBASH_H