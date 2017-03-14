//
//  315.cpp
//  315
//
//  Created by Daniel García Molero on 14/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void initBoard (vector<vector<int>> &board, const size_t &rows, const size_t &cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] != -1) {
                for (int iOffset = -1; iOffset <= 1; ++iOffset) {
                    for (int jOffset = -1; jOffset <= 1; ++jOffset) {
                        if (iOffset != 0 || jOffset != 0) {
                            if (i + iOffset >= 0 && j + jOffset >= 0 && i + iOffset < rows && j + jOffset < cols) {
                                if (board[i + iOffset][j + jOffset] == -1) {
                                    board[i][j]++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool sweep (vector<vector<int>> &board, vector<vector<bool>> &cover, const size_t &rows, const size_t &cols, const int &x, const int &y) {
    if (cover[x][y]) {
        switch (board[x][y]) {
            case -1:
                return false;
            case 0:
                for (int xOffset = -1; xOffset <= 1; ++xOffset) {
                    for (int yOffset = -1; yOffset <= 1; ++yOffset) {
                        if (x + xOffset >= 0 && y + yOffset >= 0 && x + xOffset < rows && y + yOffset < cols) {
                            if (xOffset != 0 || yOffset != 0) {
                                sweep(board, cover, rows, cols, x + xOffset, y + yOffset);
                            } else {
                                cover[x + xOffset][y + yOffset] = false;
                            }
                        }
                    }
                }
                break;
            default:
                cover[x][y] = false;
                break;
        }
    }
    return true;
}

bool solve() {
    size_t rows, cols, turns;
    int x, y;
    string line;
    cin >> rows >> cols;
    if (!cin) return false;
    vector<vector<int>> board(rows, vector<int>(cols, 0));
    vector<vector<bool>> covered(rows, vector<bool>(cols, true));
    cin.ignore();
    for (size_t i = 0; i < rows; ++i) {
        getline(cin, line);
        for (size_t j = 0; j < cols; ++j) {
            if (line[j] == '*') board[i][j] = -1;
        }
    }
    initBoard(board, rows, cols);
    cin >> turns;
    for (size_t m = 0; m < turns; ++m) {
        cin >> x >> y;
        if(!sweep(board, covered, rows, cols, x - 1, y - 1)) {
            cout << "GAME OVER" << endl;
            return true;
        }
    }
    for (size_t k = 0; k < rows; ++k) {
        for (size_t l = 0; l < cols; ++l) {
            if (!covered[k][l]) {
                if (board[k][l] == 0) cout << '-';
                else cout << board[k][l];
            } else {
                cout << 'X';
            }
        }
        cout << endl;
    }
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
