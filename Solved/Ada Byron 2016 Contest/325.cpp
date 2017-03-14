//
//  325.cpp
//  325
//
//  Created by Daniel García Molero on 14/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

const size_t NCHOC = 0, NVAN = 1, USEDCHOC = 2, USEDVAN = 3;

bool isValid(const vector<size_t> &counter) {
    return (counter[USEDCHOC] <= counter[NCHOC]) && (counter[USEDVAN] <= counter[NVAN]);
}

void printSol(const vector<char> &iceCream, bool &first) {
    if (!first) cout << " ";
    else first = false;
    for (int i = 0; i < iceCream.size(); ++i) cout << iceCream[i];
}

bool isSol(const vector<size_t> &counter) {
    return (counter[NCHOC] + counter[NVAN]) == (counter[USEDCHOC] + counter[USEDVAN]);
}

void recSolve(vector<char> iceCream, vector<size_t> counter, const char &next, bool &first) {
    iceCream.push_back(next);
    if(next == 'C') counter[USEDCHOC]++;
    else counter[USEDVAN]++;
    if(isValid(counter)) {
        if(isSol(counter)) printSol(iceCream, first);
        else {
            recSolve(iceCream, counter, 'C', first);
            recSolve(iceCream, counter, 'V', first);
        }
    }
}

void initSolve(vector<char> iceCream, vector<size_t> counter, bool &first) {
    recSolve(iceCream, counter, 'C', first);
    recSolve(iceCream, counter, 'V', first);
}

int main() {
    size_t nCases;
    bool first;
    vector<char> iceCream;
    vector<size_t> counter(4, 0);
    cin >> nCases;
    for (size_t i = 0; i < nCases; ++i) {
        cin >> counter[NCHOC] >> counter[NVAN];
        first = true;
        initSolve(iceCream, counter, first);
        cout << '\n';
    }
    return 0;
}
