//
//  19.cpp
//  19
//
//  Created by Daniel García Molero on 29/01/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int getNumPatches(const vector<int> &holes, const int &patchLength) {
    int numPatches = 1, lastPatchStart;
    if (holes.size() == 0) return 0;
    else lastPatchStart = holes[0];
    for (int i = 1; i < holes.size(); ++i) {
        if (holes[i] - lastPatchStart > patchLength) {
            lastPatchStart = holes[i];
            ++numPatches;
        }
    }
    return numPatches;
}

bool solve() {
    vector<int> holes;
    int nHoles, patchLength, aux;
    cin >> nHoles >> patchLength;
    if(!cin) return false;
    for (int i = 0; i < nHoles; ++i) {
        cin >> aux;
        holes.push_back(aux);
    }
    cout << getNumPatches(holes, patchLength) << endl;
    return true;
}

int main() {
    while(solve()){}
    return 0;
}
