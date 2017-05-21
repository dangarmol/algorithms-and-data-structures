//
//  main.cpp
//  839 Not so Mobile
//
//  Created by Daniel García Molero on 12/12/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;

int equilibrium (bool &correct) {
    int pi, di, pd, dd;
    cin >> pi >> di >> pd >> dd;
    if (pi == 0) pi = equilibrium(correct);
    if (pd == 0) pd = equilibrium(correct);
    if (pi * di != pd * dd) correct = false;
    return pi + pd;
}

void check () {
    bool correct = true;
    equilibrium(correct);
    if(correct) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        check();
        if (i < n - 1) {
            cout << '\n';
        }
    }
    return 0;
}