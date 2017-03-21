//
//  380.cpp
//  380
//
//  Created by Daniel García Molero on 13/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;

bool solve() {
    int nExpenses, sum = 0, aux;
    cin >> nExpenses;
    if (nExpenses == 0) return false;
    for (int i = 0; i < nExpenses; ++i) {
        cin >> aux;
        sum += aux;
    }
    cout << sum << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
