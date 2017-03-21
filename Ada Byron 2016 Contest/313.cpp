//
//  313.cpp
//  313
//
//  Created by Daniel García Molero on 15/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;

void solve(const int &start, const int &diff) {
    if (start + diff >= 0) cout << "SI" << endl;
    else cout << "NO" << endl;
}

int main() {
    size_t nCases;
    int start, diff;
    cin >> nCases;
    for (size_t i = 0; i < nCases; ++i) {
        cin >> start >> diff;
        solve(start, diff);
    }
    return 0;
}
