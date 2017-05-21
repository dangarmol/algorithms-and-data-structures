#include <iostream>
#include <string>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

class Patient {
private:
	string name;
	int priority;
	int eventTime;
public:
	Patient() {}

	Patient(string name, int priority, int eventTime) {
		this->name = name;
		this->priority = priority;
		this->eventTime = eventTime;
	}

	string getName() const {
		return this->name;
	}

	int getPriority() const {
		return this->priority;
	}

	int getEventTime() const {
		return this->eventTime;
	}

	bool operator< (const Patient &b) const {
		if (this->priority < b.getPriority()) {
			return true;
		} else if (this->priority == b.getPriority()) {
			return this->eventTime < b.getEventTime();
		}
		return false;
	}
};

bool solve() {
	int events, auxPrio;
	string auxName;
	char eventType;
	PriorityQueue<Patient> pq;
	cin >> events;
	if (events == 0) return false;
	for (size_t i = 0; i < events; ++i) {
		cin >> eventType;
		if (eventType == 'I') {
			cin >> auxName;
			cin >> auxPrio;
			pq.push(Patient(auxName, 0 - auxPrio, i));
		} else {
			cout << pq.top().getName() << endl;
			pq.pop();
		}
	}
	cout << "----" << endl;
	return true;
}

int main() {
	while (solve()) {}
}