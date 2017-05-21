//
//  Rec09.cpp
//  Rec09
//
//  Created by Daniel García Molero on 12/12/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int waysToAdd(const int &sum, const vector<int> &numbers, vector<vector<int>> &matrix) {
    for (int i = 1; i <= numbers.size(); ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (numbers[i - 1] == j) {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
            if (matrix[i - 1][j] > 0) {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j]);
                if (j + numbers[i - 1] <= sum) {
                    matrix[i][j + numbers[i - 1]] = matrix[i - 1][j + numbers[i - 1]] + matrix[i - 1][j];
                }
            }
        }
    }
    return matrix[numbers.size()][sum];
}

bool solve() {
    int nElem, sum, index;
    vector<int> numbers;
    cin >> nElem >> sum;
    if(!cin) return false;
    vector<vector<int>> matrix (nElem + 1, vector<int> (sum + 1, 0));
    for (int i = 0; i < nElem; ++i) {
        cin >> index;
        numbers.push_back(index);
    }
    cout << waysToAdd(sum, numbers, matrix) << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
