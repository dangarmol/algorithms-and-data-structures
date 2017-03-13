//
//  104.cpp
//  104
//
//  Created by Daniel García Molero on 27/02/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;


int comprobar(bool &correcto, bool &fin) {
    int wr1, dr1, wl1, dl1;
    
    cin >> wr1 >> dr1 >> wl1 >> dl1;
    if(wr1 + dr1 + wl1 + dl1 == 0){
        fin = true;
        return -1;
    }
    if (wr1 == 0) wr1 = comprobar(correcto, fin);
    if (wl1 == 0) wl1 = comprobar(correcto, fin);
    if (wr1 * dr1 != wl1 * dl1) correcto = false;
    return wr1 + wl1;
}

bool resuelve() {
    bool correcto = true;
    bool fin = false;
    comprobar(correcto, fin);
    if(fin) return false;
    if(correcto) cout << "SI" << '\n';
    else cout << "NO" << '\n';
    return true;
}

int main() {
    while(resuelve()) {}
    return 0;
}
