#include <iostream>

#include "PriorityQueue.h"
using namespace std;

long long getMinCost(PriorityQueue<long long> &pq) {
	long long cost = 0, a, b;
	while (pq.size() > 1) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		cost += a;
		cost += b;
		pq.push(a + b);
	}
	return cost;
}

bool solve() {
	int nCases, num;
	PriorityQueue<long long> numbers;
	cin >> nCases;
	if (nCases == 0) return false;
	for (size_t i = 0; i < nCases; i++) {
		cin >> num;
		numbers.push(num);
	}
	cout << getMinCost(numbers) << endl;
	return true;
}

int main() {
	while (solve()) {}
	return 0;
}