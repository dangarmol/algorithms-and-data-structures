//
//  prob-27.cpp
//  prob-27
//
//  Created by Daniel García Molero on 12/12/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getBottom(const vector<int> &num, const size_t &start, const size_t &end) {
    if (end - start > 1) {
        if (num[((start + end) / 2) - 1] < num[(start + end) / 2]) {
            return getBottom(num, start, (start + end) / 2);
        } else {
            return getBottom(num, (start + end) / 2, end);
        }
    } else {
        return min(num[start], num[end]);
    }
}

int getBottom(const vector<int> &num) {
    return getBottom(num, 0, num.size() - 1);
}

bool solve() {
    size_t nCases;
    int aux;
    vector <int> num;
    cin >> nCases;
    if (!cin) return false;
    for (int i = 0; i < nCases; ++i) {
        cin >> aux;
        num.push_back(aux);
    }
    cout << getBottom(num) << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
