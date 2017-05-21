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

int getNumMessages(const vector<string> &symbolList, const vector<string> &sentenceElements, vector<vector<int>> &matrix) {
    int aux;
    string strAux;
    int maxWays = 0;
    bool contains;
    for (int i = 0; i < symbolList.size(); ++i) {
        for (int j = 0; j < sentenceElements.size(); ++j) {
            contains = true;
            if (symbolList[i].length() > 1) {
                for (int offset = 0; offset < symbolList[i].length(); ++offset) {
                    strAux = symbolList[i][offset];
                    if (sentenceElements[j + offset] != strAux) {
                        contains = false;
                        break;
                    }
                }
            } else {
                strAux = symbolList[i][0];
                aux = atoi(strAux.c_str());
                if (sentenceElements[j] != strAux) {
                    contains = false;
                }
            }
            if (contains) {
                for (int count = 0; count < symbolList[i].length(); ++count) {
                    matrix[i][j + count] = (matrix[i][j + count] + 1) % MOD;
                }
            }
        }
        for (int k = 0; k < sentenceElements.size(); ++k) {
            if (i > 0) {
                matrix[i][k] = (matrix[i][k] + matrix[i - 1][k]) % MOD;
            }
        }
    }
    for (int u = 0; u < symbolList.size(); ++u) {
        for (int v = 0; v < sentenceElements.size(); ++v) {
            cout << matrix[u][v] << " ";
        }
        cout << endl;
    }
    for (int lastRow = 0; lastRow < sentenceElements.size(); ++lastRow) {
        if (matrix[symbolList.size() - 1][lastRow] == 0 && sentenceElements[lastRow] != "0") {
            maxWays = 0;
            break;
        } else if (maxWays < matrix[symbolList.size() - 1][lastRow]) {
            maxWays = matrix[symbolList.size() - 1][lastRow];
        }
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
    vector<string> sentenceElements(sentence.length());
    for (int i = sentence.length() - 1; i >= 0; --i) {
        sentenceElements[i] = sentence[sentence.length() - (1 + i)];
    }
    vector<vector<int>> matrix(nSymbols, vector<int>(sentenceElements.size(), 0));
    cout << getNumMessages(symbolList, sentenceElements, matrix) << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
