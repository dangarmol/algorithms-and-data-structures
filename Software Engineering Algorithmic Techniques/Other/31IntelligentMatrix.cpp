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
    bool contains, zero;
    //Row = Used symbols
    //Col = Sentence characters
    for (int row = 0; row < symbolList.size(); ++row) {
        for (int col = 0; col < sentence.length(); ++col) {
            contains = true, zero = true;
            if (symbolList[row].length() > 1 && col + 1 >= symbolList[row].length()) {
                for (int offset = symbolList[row].length() - 1; offset >= 0; --offset) {
                    if (sentence[col - offset] != symbolList[row][symbolList[row].length() - (offset + 1)]) {
                        contains = false;
                        break;
                    }
                    if (row != 0 && zero && matrix[row - 1][col - offset] != 0) {
                        zero = false;
                    }
                }
            } else if (symbolList[row].length() == 1) {
                if (sentence[col] != symbolList[row][0]) {
                    contains = false;
                }
                if (row != 0 && matrix[row - 1][col] != 0) {
                    zero = false;
                }
            }
            if (contains && zero) {
                for (int count = 0; count < symbolList[row].length(); ++count) {
                    matrix[row][col + count]++;
                }
            } else if (contains && !zero) {
                int lastCol = 0;
                if (col != 0) {
                    lastCol = col - 1;
                }
                matrix[row][col] = matrix[row - 1][col] + matrix[row][lastCol] - matrix[row][1 + col - symbolList[row].length()];
                //matrix[row][col] = matrix[row - 1][col] + matrix[row][1 + col - symbolList[row].length()];
            } else if (row != 0) {
                matrix[row][col] = matrix[row - 1][col];
            }
            /*if (row == symbolList.size() - 1) {
                if (matrix[row][col] == 0 && sentence[col] != '0') {
                    return 0;
                } else if (maxWays < matrix[row][col]) {
                    maxWays = matrix[row][col];
                }
            }*/
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
    sort(symbolList.begin(), symbolList.end());
    cout << getNumMessages(symbolList, sentence, matrix) << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
