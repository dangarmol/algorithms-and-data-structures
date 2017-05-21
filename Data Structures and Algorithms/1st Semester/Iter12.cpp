//
//  Iter12.cpp
//  Iter12
//
//  Created by Daniel García Molero on 16/11/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool resuelve() {
    string sentence;
    string pattern;
    string aux;
    int counter = 0;
    int charMatches = 0;
    getline(cin, sentence);
    getline(cin, pattern);
    if (!cin) return false;
    for (int i = 0; i <= sentence.length() - pattern.length(); ++i) {
        for (int j = i; j < i + pattern.length(); ++j) {
            if (sentence[j] == pattern[j - i]) {
                charMatches++;
            }
        }
        if (charMatches == pattern.length()) {
            counter++;
        }
        charMatches = 0;
    }
    cout << counter << endl;
    return true;
}

int main() {
    while(resuelve()){}
    return 0;
}
