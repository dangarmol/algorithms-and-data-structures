//
//  Iter13.cpp
//  Iter13
//
//  Created by Daniel García Molero on 16/11/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;

void resolverCaso(int v[], const int &n) {
    int peakCounter = 0, valleyCounter = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
            peakCounter++;
        }
        if (v[i - 1] > v[i] && v[i] < v[i + 1]) {
            valleyCounter++;
        }
    }
    cout << peakCounter << " " << valleyCounter << endl;
}

void resolver() {
    int v[10000];
    int nTemp;
    cin >> nTemp;
    for (int i = 0; i < nTemp; ++i) {
        cin >> v[i];
    }
    resolverCaso(v, nTemp);
}

int main() {
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i) {
        resolver();
    }
    return 0;
}
