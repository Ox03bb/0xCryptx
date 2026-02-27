#include <encryption/scytale.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    string raw = "this is a text";

    scytale cipher;
    string ch = cipher.encrypt(raw, 3);
    cout << ch << '\n';
    cout << "==================" << '\n';
    cout << cipher.decrypt(ch, 3);

    return 0;
}
