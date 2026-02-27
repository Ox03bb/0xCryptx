#include <encryption/vigenere.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    string raw = "AbcdE";

    vigenere cipher;
    string ch = cipher.encrypt(raw, "KEY");
    cout << ch << '\n';
    // string che = cipher.decrypt(ch);
    // cout << che << '\n';
    // cout << "==================" << '\n';
    // cout << cipher.decrypt(ch, 3);

    return 0;
}
