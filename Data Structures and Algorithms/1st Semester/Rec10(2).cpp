//
//  main.cpp
//  Rec10Mac
//
//  Created by Daniel García Molero on 24/12/2016.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

long long int checkGradient(bool &isGrad, const int &row, const vector<vector<long long int>> &matrix, const int &start, const int &end) {
    int half = (start + end) / 2;
    long long int right, left;
    if (end - start == 1 || end - start == 0) {
        right = matrix[row][end];
        left = matrix[row][start];
    } else {
        right = checkGradient(isGrad, row, matrix, half + 1, end);
        left = checkGradient(isGrad, row, matrix, start, half);
    }
    if (left >= right && end - start != 0) {
        isGrad = false;
    }
    return left + right;
}

bool solve() {
    int rows, cols;
    bool isGrad = true;
    cin >> rows >> cols;
    vector<vector<long long int>> matrix (rows, vector<long long int> (cols));
    if (!cin) return false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int k = 0; k < rows; ++k) {
        checkGradient(isGrad, k, matrix, 0, cols - 1);
        if (!isGrad) break;
    }
    if (isGrad) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
