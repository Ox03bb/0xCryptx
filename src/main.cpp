#include <encryption/polybius.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    string raw = "abcdefg";

    polybius cipher;
    string ch = cipher.encrypt(raw);
    cout << ch << '\n';
    string che = cipher.decrypt(ch);
    cout << che << '\n';
    // cout << "==================" << '\n';
    // cout << cipher.decrypt(ch, 3);

    return 0;
}
