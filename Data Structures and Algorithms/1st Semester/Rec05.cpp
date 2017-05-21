//
//  Rec05.cpp
//  Rec05
//
//  Created by Daniel García Molero on 12/12/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int combinatorio (const int &a, const int &b, vector<vector<int>> &v) {
    if (a == b || b == 0) {
        return 1;
    } else {
        if (v[a][b] != -1) {
            return v[a][b];
        } else {
            v[a - 1][b - 1] = combinatorio(a - 1, b - 1, v);
            v[a - 1][b] = combinatorio(a - 1, b, v);
            return v[a - 1][b - 1] + v[a - 1][b];
        }
    }
}

bool solve() {
    int a, b;
    cin >> a >> b;
    if (!cin) return false;
    vector<vector<int>> v (a + 1, vector<int> (b + 1, - 1));
    cout << combinatorio(a, b, v) << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}