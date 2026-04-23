#ifndef DES_H
#define DES_H

#include <string>
#include <vector>

using namespace std;

class DES {
  public:
    static string encrypt(string raw, int shift);
    static string decrypt(string raw, int shift);

  private:
    static string permutation(string raw, bool invert = 0);
};

#endif // DES_H