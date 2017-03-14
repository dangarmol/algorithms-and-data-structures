//
//  104.cpp
//  104
//
//  Created by Daniel García Molero on 27/02/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
using namespace std;


int check(bool &correct, bool &end) {
    int wr1, dr1, wl1, dl1;
    
    cin >> wr1 >> dr1 >> wl1 >> dl1;
    if(wr1 + dr1 + wl1 + dl1 == 0){
        end = true;
        return -1;
    }
    if (wr1 == 0) wr1 = check(correct, end);
    if (wl1 == 0) wl1 = check(correct, end);
    if (wr1 * dr1 != wl1 * dl1) correct = false;
    return wr1 + wl1;
}

bool solve() {
    bool correct = true;
    bool end = false;
    check(correct, end);
    if(end) return false;
    if(correct) cout << "SI" << '\n';
    else cout << "NO" << '\n';
    return true;
}

int main() {
    while(solve()) {}
    return 0;
}
