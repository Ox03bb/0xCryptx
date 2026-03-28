#include "encryption/polybius.h"
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string polybius::encrypt(std::string raw, vector<vector<char>> arr, const char *x_key,
                         const char *y_key) {
    string enc;

    int xl = strlen(x_key);
    int yl = strlen(y_key);

    if (xl != (int)arr.size() || yl != (int)arr[0].size()) {
        return "Invalid key size";
    }

    for (char c : raw) {
        pos p = arr_find(arr, c);
        if (p.row == -1 || p.col == -1) {
            return "Invalid " + string(1, c) + " character in raw string";
        }
        enc += x_key[p.row];
        enc += y_key[p.col];
    }
    return enc;
}

string polybius::decrypt(std::string raw, vector<vector<char>> arr, const char *x_key,
                         const char *y_key) {
    string dec;

    for (size_t i = 0; i < raw.length(); i += 2) {
        char x = raw[i];
        char y = raw[i + 1];

        int row = vec_find(x_key, x);
        int col = vec_find(y_key, y);

        if (row == -1 || col == -1) {
            return "Invalid key value";
        }

        dec += arr[row][col];
    }
    return dec;
}

// helper functions
pos polybius::arr_find(vector<vector<char>> arr, char c) {
    int rl = arr.size();
    int cl = arr[0].size();
    for (int r = 0; r < rl; r++) {
        for (int col = 0; col < cl; col++) {
            if (arr[r][col] == c) {
                return {r, col};
            }
        }
    }
    return {-1, -1};
}

int polybius::vec_find(const char *vec, char c) {
    int len = strlen(vec);
    for (int i = 0; i < len; i++) {
        if (vec[i] == c) {
            return i;
        }
    }
    return -1;
}
