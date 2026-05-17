#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char, int> freq;
    // check all rows
    int i = 0;
    int j = 0;
    while (i < 9) {
        while (j < 9) {
            char curr = board[i][j];
            if (curr != '.') {
                freq[curr]++;
                if (freq[curr] > 1) {
                    return false;
                }
            }
            j++;
        }

        freq.clear();
        cout << "\n row" << i << " passes check";
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    // now column checks
    while (i < 9) {
        while (j < 9) {
            char curr = board[j][i];
            if (curr != '.') {
                freq[curr]++;
                if (freq[curr] > 1) {
                    return false;
                }
            }
            j++;
        }

        freq.clear();
        cout << "\n column" << i << " passes check";
        j = 0;
        i++;
    }

    // now for each box
    vector<pair<int, int>> centers = {{1, 1}, {4, 1}, {7, 1}, {1, 4}, {4, 4},
                                      {7, 4}, {1, 7}, {4, 7}, {7, 7}};
    i = 0;
    j = 0;
    int boxNum = 1;
    freq.clear();
    while (boxNum <= 9) {
        pair<int, int> p = centers[boxNum - 1];

        for (i = p.first - 1; i <= p.first + 1; i++) {
            for (j = p.second - 1; j <= p.second + 1; j++) {
                cout << "\ni - " << i << "j - " << j;
                char curr = board[i][j];
                if (curr != '.') {
                    freq[curr]++;
                    if (freq[curr] > 1) {
                        cout << "char - " << curr << " repeated ";
                        return false;
                    }
                }
            }
        }
        freq.clear();
        cout << "\nBox" << boxNum++ << "cleared";
    }

    return true;
}
