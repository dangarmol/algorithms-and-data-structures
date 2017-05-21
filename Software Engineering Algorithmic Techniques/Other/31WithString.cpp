//
//  31.cpp
//  31
//
//  Created by Daniel García Molero on 17/01/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int getNumMessages(const vector<string> &symbolList, const string &sentence, vector<vector<int>> &matrix) {
    int maxWays = 0;
    bool contains;
    for (int i = 0; i < symbolList.size(); ++i) {
        for (int j = 0; j < sentence.length(); ++j) {
            contains = true;
            if (symbolList[i].length() > 1) {
                for (int offset = 0; offset < symbolList[i].length(); ++offset) {
                    if (sentence[j + offset] != symbolList[i][offset]) {
                        contains = false;
                        break;
                    }
                }
            } else {
                if (sentence[j] != symbolList[i][0]) {
                    contains = false;
                }
            }
            if (contains) {
                for (int count = 0; count < symbolList[i].length(); ++count) {
                    matrix[i][j + count] = (matrix[i][j + count] + 1) % MOD;
                }
            }
            if (i > 0) {
                matrix[i][j] = (matrix[i][j] + matrix[i - 1][j]) % MOD;
            }
            if (i == symbolList.size() - 1) {
                if (matrix[i][j] == 0 && sentence[j] != '0') {
                    return 0;
                } else if (maxWays < matrix[i][j]) {
                    maxWays = matrix[i][j];
                }
            }
        }
    }
    for (int u = 0; u < symbolList.size(); ++u) {
        for (int v = 0; v < sentence.size(); ++v) {
            cout << matrix[u][v] << " ";
        }
        cout << endl;
    }
    return maxWays;
}

bool solve() {
    int nSymbols;
    string sentence, symbolValue;
    vector<string> symbolList;
    cin >> nSymbols;
    if (nSymbols == 0) return false;
    for (int i = 0; i < nSymbols; ++i) {
        cin >> symbolValue;
        symbolList.push_back(symbolValue);
    }
    cin >> sentence;
    vector<vector<int>> matrix(nSymbols, vector<int>(sentence.length(), 0));
    cout << getNumMessages(symbolList, sentence, matrix) << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
