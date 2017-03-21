//
//  252.cpp
//  252
//
//  Created by Daniel García Molero on 14/03/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check(const string &line) {
    size_t right = line.length() - 1, left = 0;
    while(right >= left) {
        while(line[right] == ' ') right--;
        while(line[left] == ' ') left++;
        if(right < left) return true;
        if(line[right] != line[left]) return false;
        right--;
        left++;
    }
    return true;
}

bool solve() {
    string line;
    getline(cin, line);
    if (line == "XXX") return false;
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    if (line.length() == 1 || check(line)) cout << "SI" << endl;
    else cout << "NO" << endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}
