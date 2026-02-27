#include <encryption/caesar.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    string raw = "abcdefg";

    caesar cipher;
    string ch = cipher.encrypt(raw, 7);
    cout << ch << '\n';
	string che = cipher.decrypt(ch, 7);
    cout << che << '\n';
    // cout << "==================" << '\n';
    // cout << cipher.decrypt(ch, 3);

    return 0;
}
