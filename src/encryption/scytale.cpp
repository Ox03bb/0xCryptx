#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class scytale {
  public:
    static string encript(string raw, int rows, char extra = '#') {

        raw.erase(remove(raw.begin(), raw.end(), " "), raw.end());
        transform(raw.begin(), raw.end(), raw.begin(), ::toupper);

        int len = raw.length();
        int cols = ceil(len / rows);
        int extra_char = (cols * rows) - len;

        vector<vector<char>> arr(rows, vector<char>(cols));

        int cnt = 0;
        int th = rows - extra_char; // treshhold
        for (int r = 0; r <= rows; r++) {
            for (int c = 0; c <= cols; c++) {
                if ((rows > th) && (cols == c)) {
                    arr[r][c] = raw[cnt];
                    cnt++;
                } else {
                    arr[r][c] = extra;
                }
            }
        }

        return read_row(arr);
    }

  private:
    static string read_row(vector<vector<char>> arr) {
        string str;

        int lnt_row = arr.size();
        int lnt_clo = arr[0].size();

        int cnt = 0;
        for (int r = 0; r < lnt_row; r++) {
            for (int c = 0; c < lnt_clo; c++) {
                str[cnt] = arr[r][c];
                cnt++;
            }
        }
        return str;
    }

    static string read_col(vector<vector<char>> arr) {
        string str;

        int lnt_row = arr.size();
        int lnt_clo = arr[0].size();

        int cnt = 0;
        for (int c = 0; c < lnt_clo; c++) {
            for (int r = 0; r < lnt_row; r++) {
                str[cnt] = arr[r][c];
                cnt++;
            }
        }
        return str;
    }
};