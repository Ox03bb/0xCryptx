#include "encryption/vigenere.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

string vigenere::encrypt(string raw, string key) {
    int8_t cnt = 0;
    int8_t ln_key = key.length();

    transform(key.begin(), key.end(), key.begin(), ::toupper);

    string enc;

    for (char c : raw) {
        if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) {
            if (cnt == ln_key) {
                cnt = 0;
            }
            enc += k_adder(c, key[cnt]);
            cnt++;
        } else {
            enc += c;
        }
    }
    return enc;
};

string vigenere::decrypt(string raw, string key) {
    int8_t cnt = 0;
    int8_t ln_key = key.length();

    transform(key.begin(), key.end(), key.begin(), ::toupper);

    string dec;

    for (char c : raw) {
        if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) {
            if (cnt == ln_key) {
                cnt = 0;
            }
            dec += k_sub(c, key[cnt]);
            cnt++;
        } else {
            dec += c;
        }
    }
    return dec;
};

// helper

char vigenere::k_adder(char c, char k) {
    int8_t i = 0;
    k = k - 65;
    if (c >= 97 && c <= 122) {
        i = 97;
    } else if (c >= 65 && c <= 90) {
        i = 65;
    } else {
        return c;
    }

    return (((c + k) - i) % 26) + i;
}

char vigenere::k_sub(char c, char k) {
    int8_t i = 0;
    k = k - 65;
    if (c >= 97 && c <= 122) {
        i = 97;
    } else if (c >= 65 && c <= 90) {
        i = 65;
    } else {
        return c;
    }

    return (((c - k) - i + 26) % 26) + i;
}