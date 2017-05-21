//
//  Iter14.cpp
//  Iter14
//
//  Created by Daniel García Molero on 16/11/16.
//  Copyright © 2016 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool resuelve() {
    string word;
    int counter = 1;
    int maxCount = 0;
    getline(cin, word);
    if (word == "XXX") return false;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    for (int i = 1; i <= word.length(); ++i) {
        if (word[i - 1] < word[i]) {
            counter++;
            continue;
        }
        if (maxCount < counter) {
            maxCount = counter;
            counter = 1;
        }
    }
    if (maxCount < counter)
        maxCount = counter;
    cout << word.length() << " " << maxCount << endl;
    return true;
}

int main() {
    while(resuelve()){}
    return 0;
}