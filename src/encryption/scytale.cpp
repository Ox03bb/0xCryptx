#include "encryption/scytale.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

string scytale::encrypt(string raw, int rows, char extra) {
    raw.erase(remove(raw.begin(), raw.end(), ' '), raw.end());
    transform(raw.begin(), raw.end(), raw.begin(), ::toupper);

    double len = raw.length();
    int cols = ceil(len / rows);
    int extra_char = (cols * rows) - len;

    vector<vector<char>> arr(rows, vector<char>(cols));

    int cnt = 0;
    int th = rows - extra_char; // treshhold
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if ((r >= th) && (c == cols - 1)) {
                arr[r][c] = extra;
            } else if (cnt < len) {
                arr[r][c] = raw[cnt];
                cnt++;
            } else {
                arr[r][c] = extra;
            }
        }
    }

    return read_col(arr);
}


string scytale::decrypt(string raw, int rows, char extra) {
    raw.erase(remove(raw.begin(), raw.end(), extra), raw.end());

    double len = raw.length();
    int cols = ceil(len / rows);

    vector<vector<char>> arr(rows, vector<char>(cols));

    int cnt = 0;
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            arr[r][c] = raw[cnt];
            cnt++;
        }
    }

    return read_row(arr);
}

string scytale::read_row(vector<vector<char>> arr) {
    string str;

    int lnt_row = arr.size();
    int lnt_clo = arr[0].size();

    for (int r = 0; r < lnt_row; r++) {
        for (int c = 0; c < lnt_clo; c++) {
            str += arr[r][c];
        }
    }
    return str;
}

string scytale::read_col(vector<vector<char>> arr) {
    string str;

    int lnt_row = arr.size();
    int lnt_clo = arr[0].size();

    for (int c = 0; c < lnt_clo; c++) {
        for (int r = 0; r < lnt_row; r++) {
            str += arr[r][c];
        }
    }
    return str;
}


// debug

void scytale::print_grid(const vector<vector<char>> &arr) {
    for (const auto &row : arr) {
        for (const auto &ch : row) {
            cout << ch << ' ';
        }
        cout << '\n';
    }
}