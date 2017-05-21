//
//  VA05.cpp
//  VA05
//
//  Created by Daniel García Molero on 13/01/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Song {
    int length = 0;
    int score = 0;
};

struct Tape {
    int first;
    int second;
};

bool isSolution(int k, int n) {
    return k == n - 1;
}

bool isPromising(int score, int maxScore, int possibleMaxScore) {
    return possibleMaxScore + score > maxScore;
}

void dealWithSolution(int score, int &maxScore) {
    if (score > maxScore)
        maxScore = score;
}

void calcularPuntuacion(vector<Song> v, Tape tape, int k, int n, int score, int &maxScore, int possibleMaxScore, vector<int> minLength) {
    
    score += v[k].score;
    possibleMaxScore -= v[k].score;
    tape.first -= v[k].length;
    
    if (tape.first >= 0 && isPromising(score, maxScore, possibleMaxScore)) {
        if (isSolution(k, n) || (tape.first - minLength[k] < 0 && tape.second - minLength[k] < 0)) {
            dealWithSolution(score, maxScore);
        } else {
            calcularPuntuacion(v, tape, k + 1, n, score, maxScore, possibleMaxScore, minLength);
        }
    }
    
    tape.first += v[k].length;
    tape.second -= v[k].length;
    
    if (tape.second >= 0 && isPromising(score, maxScore, possibleMaxScore)) {
        if (isSolution(k, n) || (tape.first - minLength[k] < 0 && tape.second - minLength[k] < 0)) {
            dealWithSolution(score, maxScore);
        } else {
            calcularPuntuacion(v, tape, k + 1, n, score, maxScore, possibleMaxScore, minLength);
        }
    }
    
    score -= v[k].score;
    tape.second += v[k].length;
    
    if (isSolution(k, n) || (tape.first - minLength[k] < 0 && tape.second - minLength[k] < 0)) {
        dealWithSolution(score, maxScore);
    } else {
        calcularPuntuacion(v, tape, k + 1, n, score, maxScore, possibleMaxScore, minLength);
    }
    
    possibleMaxScore += v[k].score;
}

bool solve() {
    vector<Song> v;
    
    Tape tape;
    int n, maxScore = 0, possibleMaxScore = 0;
    vector<int> minLength (50);
    
    cin >> n;
    
    if (n == 0)
        return false;
    
    cin >> tape.first;
    tape.second = tape.first;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].length >> v[i].score;
        possibleMaxScore += v[i].score;
    }
    
    if (n == 1) {
        if (tape.first >= v[0].length)
            maxScore = v[0].score;
    } else {
        minLength[n - 2] = v[n - 1].length;
        
        for (int i = n - 3; i >= 0; i--) {
            if (v[i + 1].length < minLength[i + 1])
                minLength[i] = v[i + 1].length;
            else
                minLength[i] = minLength[i + 1];
        }
        
        calcularPuntuacion(v, tape, 0, n, 0, maxScore, possibleMaxScore, minLength);
    }
    
    cout << maxScore << endl;
    
    return true;
}

int main() {
    
    while (solve()) {}
    
    return 0;
}
