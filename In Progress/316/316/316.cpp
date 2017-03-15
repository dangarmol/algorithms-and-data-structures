//
//  316.cpp
//  316
//
//  Created by Daniel García Molero on 15/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void getBestDays(const vector<int> &days, const size_t &min, const size_t &max) {
    
}

void solve() {
    size_t nDays, minIndex = 0, maxIndex = 0;
    int aux = 0, minValue = 0, maxValue = 0;
    cin >> nDays;
    vector<int> days(nDays);
    for (size_t i = 0; i < nDays; ++i) {
        cin >> days[i];
        if (i != nDays - 1) days[i] += days[i - 1];
        if (days[i] < minValue) {
            minValue = days[i];
            minIndex = i;
        } else if (days[i] > maxValue) {
            maxValue = days[i];
            maxIndex = i;
        }
    }
    getBestDays(days, minIndex, maxIndex);
}

int main() {
    size_t nCases;
    cin >> nCases;
    for (size_t i = 0; i < nCases; ++i) {
        solve();
    }
    return 0;
}
