//
//  138.cpp
//  138
//
//  Created by Daniel García Molero on 28/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;

void solve() {
    long long number;
    long long counter = 0;
    cin >> number;
    while (number >= 5) {
        number /= 5;
        counter += number;
    }
    cout << counter << endl;
}

int main() {
    size_t nCases;
    cin >> nCases;
    while(nCases > 0) {
        solve();
        --nCases;
    }
    return 0;
}
