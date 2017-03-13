//
//  106.cpp
//  106
//
//  Created by Daniel García Molero on 27/02/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

const int EAN8 = 8;
const int EAN13 = 13;
const int VALID = 0;
const int NOT_VALID = -1;

short int getEANType(const long long &n) {
    return to_string(n).length();
}

short int checkValid(const short int &crc, const long long &n, const short int &depth) {
    if()
    return 0;
}

void checkEAN(const long long &n) {
    int type = checkValid(n % 10, n / 10, 1);
    if(type == VALID) {
        type = getEANType(n);
        if (type == EAN8) {
            
        } else {
            
        }
    }
}

bool solve() {
    long long code;
    cin >> code;
    if (code == 0) return false;
    checkEAN(code);
    return true;
}

int main() {
    while(solve()) {}
    return 0;
}
