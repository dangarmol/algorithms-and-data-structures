//
//  07.cpp
//  07
//
//  Created by Daniel García Molero on 27/01/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include "IndexPQ.h"
using namespace std;

class User {
private:
	int id;
	int time;
	int timeAdder;
public:
	User() {
		User(0, 0, 0);
	}
	User(int id, int time, int timeAdder) {
		this->id = id;
		this->time = time;
		this->timeAdder = timeAdder;
	}
	int getId() const {
		return this->id;
	}
	int getTime() const {
		return this->time;
	}
	int getTimeAdder() const {
		return this->timeAdder;
	}
	bool operator< (const User &b) const {
		if (this->timeAdder < b.getTimeAdder()) {
			return true;
		}
		else if (timeAdder == b.getTimeAdder()) {
			return this->id < b.getId();
		}
		return false;
	}
};

void printCases(IndexPQ<User> &pq, const int &k) {
	int auxTime;
	for (size_t i = 0; i < k; i++) {
		cout << pq.top().prioridad.getId() << endl;
		auxTime = pq.top().prioridad.getTime();
		pq.update(pq.top().elem, User(pq.top().prioridad.getId(), auxTime, pq.top().prioridad.getTimeAdder() + auxTime));
	}
	cout << "----" << endl;
}

bool solve() {
	int nUsers, auxId, auxTime, k;
	cin >> nUsers;
	if (nUsers == 0) return false;
	IndexPQ<User> pq(nUsers);
	for (size_t i = 0; i < nUsers; ++i) {
		cin >> auxId >> auxTime;
		pq.push(i, User(auxId, auxTime, auxTime));
	}
	cin >> k;
	printCases(pq, k);
	return true;
}

int main() {
	while (solve());
	return 0;
}
