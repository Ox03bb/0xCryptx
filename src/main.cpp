#include <hashing/md5.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    string raw = "aa";

    md5 cipher;
    string ch = cipher.hash(raw);
    cout << ch << '\n';

    return 0;
}
