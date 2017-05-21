//
//  Rec08.cpp
//  Rec08
//
//  Created by Daniel García Molero on 12/12/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void solveCase (const int &n, const int &x, const int &y, const int &count, vector <int> &v) {
    if (v[n] != -1) {
        return;
    }
    v[count] = v[count - 1] + v[count - 2];
    solveCase(n, x, y, count + 1, v);
}

bool solve() {
    int n, x, y;
    cin >> n;
    if(n == -1) return false;
    cin >> x >> y;
    vector <int> v (1000, -1);
    v[0] = x;
    v[1] = y;
    solveCase(n, x, y, 2, v);
    cout << v[n] << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}