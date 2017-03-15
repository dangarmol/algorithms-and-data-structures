//
//  314.cpp
//  314
//
//  Created by Daniel García Molero on 15/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void print(const size_t &s, const size_t &v) {
    cout << s << " " << v << endl;
}

void solve() {
    size_t nTemp;
    size_t valleys = 0, summits = 0;
    cin >> nTemp;
    vector<int> temps(nTemp);
    for (size_t i = 0; i < nTemp; ++i) {
        cin >> temps[i];
    }
    if (nTemp >= 3) {
        for (int j = 0; j < nTemp; ++j) {
            if (j + 1 < nTemp && j - 1 >= 0) {
                if (temps[j - 1] > temps[j] && temps[j] < temps[j + 1]) {
                    valleys++;
                } else if (temps[j - 1] < temps[j] && temps[j] > temps[j + 1]) {
                    summits++;
                }
            }
        }
    }
    print(summits, valleys);
}

int main() {
    size_t nCases;
    cin >> nCases;
    for (size_t i = 0; i < nCases; ++i) {
        solve();
    }
    return 0;
}
