//
//  Rec07.cpp
//  Rec07
//
//  Created by Daniel García Molero on 12/12/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;

int equilibrium (bool &correct, bool &end) {
    int pi, di, pd, dd;
    cin >> pi >> di >> pd >> dd;
    if (pi == 0 && di == 0 && pd == 0 && dd == 0) {
        end = true;
        return -1;
    }
    if (pi == 0) pi = equilibrium(correct, end);
    if (pd == 0) pd = equilibrium(correct, end);
    if (pi * di != pd * dd) correct = false;
    return pi + pd;
}

bool check () {
    bool correct = true;
    bool end = false;
    equilibrium(correct, end);
    if(correct && !end) cout << "SI" << endl;
    else if (!correct && !end) cout << "NO" << endl;
    return end;
}

int main() {
    while (!check()) {}
    return 0;
}