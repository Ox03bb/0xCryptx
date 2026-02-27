#include <encryption/vigenere.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    string raw = "AbcdE";

    vigenere cipher;
    string ch = cipher.encrypt(raw, "key");
    cout << ch << '\n';
	
	cout << "==================" << '\n';

    string che = cipher.decrypt(ch,"key");
    cout << che << '\n';

    return 0;
}
