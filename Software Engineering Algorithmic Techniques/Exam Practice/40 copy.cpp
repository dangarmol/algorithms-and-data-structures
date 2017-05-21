//
//  40.cpp
//  40
//
//  Created by Daniel GarcÌa Molero on 28/01/2017.
//  Copyright © 2017 Daniel GarcÌa Molero. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

struct Song {
    int length;
    int score;
};

bool operator> (Song const& a, Song const& b) {
    return (a.score / a.length) > (b.score / b.length);
}

struct Branch {
    vector<int> solution;
    int depth;
    float currentFirstLength;
    float currentSecondLength;
    float currentFirstScore;
    float currentSecondScore;
    float estimatedScore;
};

bool operator> (Branch const& a, Branch const& b) {
    return a.estimatedScore > b.estimatedScore;
}

float greedyEstimate(vector<Song> const& songs, float remaining, int lastTaken, float length, float profit) {
    float lengthLeft = remaining - length;
    float estimate = profit;
    int index = lastTaken + 1;
    while (index < songs.size() && songs[index].length <= lengthLeft) {
        lengthLeft -= songs[index].length;
        estimate += songs[index].score;
        ++index;
    }
    if (index < songs.size()) {
        estimate += (lengthLeft / songs[index].length) * songs[index].score; }
    return estimate;
}

void getBestScore(const vector<Song> &songs, float remainingFirst, float remainingSecond, vector<int> &bestSolution, float &bestScore) {
    Branch last;
    last.solution = vector<int>(songs.size());
    last.depth = -1;
    last.currentFirstLength = last.currentFirstScore = last.currentSecondLength = last.currentSecondScore = 0;
    last.estimatedScore = greedyEstimate(songs, remainingFirst + remainingSecond, last.depth, last.currentFirstLength + last.currentSecondLength, last.currentFirstScore + last.currentSecondScore);
    PriorityQueue<Branch, std::greater<Branch>> pq;
    pq.push(last);
    bestScore = -1;
    while (!pq.empty() && pq.top().estimatedScore > bestScore) {
        last = pq.top();
        pq.pop();
        Branch next(last);
        ++next.depth;
        //primera cara
        if (last.currentFirstLength + songs[next.depth].length <= remainingFirst) {
            next.solution[next.depth] = 1;
            next.currentFirstLength = last.currentFirstLength + songs[next.depth].length;
            next.currentFirstScore = last.currentFirstScore + songs[next.depth].score;
            next.estimatedScore = last.estimatedScore;
            if (next.depth == songs.size() - 1) {
                bestSolution = next.solution;
                bestScore = next.currentFirstScore;
            } else {
                pq.push(next);
            }
        }
        //segunda cara
        if (last.currentSecondLength + songs[next.depth].length <= remainingSecond) {
            next.solution[next.depth] = 2;
            next.currentSecondLength = last.currentSecondLength + songs[next.depth].length;
            next.currentSecondScore = last.currentSecondScore + songs[next.depth].score;
            next.estimatedScore = last.estimatedScore;
            if (next.depth == songs.size() - 1) {
                bestSolution = next.solution;
                bestScore = next.currentSecondScore;
            } else {
                pq.push(next);
            }
        }
        //ninguna cara
        next.estimatedScore = greedyEstimate(songs, remainingFirst + remainingSecond, next.depth, last.currentFirstLength + last.currentSecondLength, last.currentFirstScore + last.currentSecondScore);
        if (next.estimatedScore > bestScore) {
            next.currentFirstLength = last.currentFirstLength;
            next.currentFirstScore = last.currentFirstScore;
            next.currentSecondLength = last.currentSecondLength;
            next.currentSecondScore = last.currentSecondScore;
            next.solution[next.depth] = 0;
            if (next.depth == songs.size() - 1) {
                bestSolution = next.solution;
                bestScore = next.currentFirstScore + next.currentSecondScore;
            } else {
                pq.push(next);
            }
        }
    }
}

bool solve() {
    vector<Song> songs;
    Song auxSong;
    int nSongs;
    float sideLength, bestScore;
    vector<int> bestSolution;
    cin >> nSongs;
    if (nSongs == 0) return false;
    cin >> sideLength;
    
    for (int i = 0; i < nSongs; i++) {
        cin >> auxSong.length >> auxSong.score;
        songs.push_back(auxSong);
    }
    sort(songs.begin(), songs.end(), greater<Song>());
    getBestScore(songs, sideLength, sideLength, bestSolution, bestScore);
    cout << bestScore << endl;
    return true;
}

int main() {
    
    while (solve()) {}
    
    return 0;
}
