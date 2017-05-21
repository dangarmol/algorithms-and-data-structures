//
//  main.cpp
//  Ejercicio1ExamenFebEDA16
//
//  Created by Daniel García Molero on 19/01/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int parImpar(vector<int> v, const int &n) {
    int result = 0, pairCount = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] % 2 == 0) {
            pairCount++;
        } else {
            result += pairCount;
        }
    }
    return result;
}

int main() {
    vector<int> v;
    int aux, n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }
    
    cout << parImpar(v, n) << endl;
    
    return 0;
}
