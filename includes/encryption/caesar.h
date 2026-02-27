#ifndef CAESER_H
#define CAESER_H

#include <string>
#include <vector>


class caesar {
  public:
    static std::string encrypt(std::string raw, int shift);
    static std::string decrypt(std::string raw, int shift);

  private:
    static char overlap(char init, int val, char start, char end);
    static char shift(char c, int val);
};

#endif // CAESER_H