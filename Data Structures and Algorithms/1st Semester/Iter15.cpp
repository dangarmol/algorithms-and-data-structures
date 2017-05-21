//
//  Iter15.cpp
//  Iter15
//
//  Created by Daniel García Molero on 16/11/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;

void resuelveCaso(int v[], const int &n) {
    int iiCount = 0, ipCount = 0;
    for (int i = 1; i < n - 1; ++i) {
        if((v[i - 1] % 2) + (v[i + 1] % 2) == 0)
            ipCount++;
        else if((v[i - 1] % 2) == 1 && (v[i + 1] % 2) == 1)
            iiCount++;
    }
    cout << ipCount << " " << iiCount << endl;
}

bool resuelve() {
    int v[10000];
    int nCasos;
    cin >> nCasos;
    if(nCasos == 0) return false;
    for (int i = 0; i < nCasos; ++i) {
        cin >> v[i];
    }
    resuelveCaso(v, nCasos);
    return true;
}

int main() {
    while(resuelve()){}
    return 0;
}