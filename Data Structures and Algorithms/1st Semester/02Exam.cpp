//Daniel Garcia Molero
//Pto0512
//Usuario juez "F38"
//Todo funciona

#include <iostream>
#include <vector>
using namespace std;

int getDifferentValues(const vector<int> &v, const int &start, const int &end, const int &first, const int &last) {
	int half = (end + start) / 2;
	int right, left, diff = 0;
	if (v[start] == v[end]) {
		return 1;
	} else if (end - start == 1 || end == start) {
		return 2;
	} else {
		left = getDifferentValues(v, start, half, first, last);
		right = getDifferentValues(v, half + 1, end, first, last);
		if (v[half] == v[half + 1]) diff--;
		return left + right + diff;
	}
}

bool solve() {
	int n, aux;
	vector<int> numbers;
	cin >> n;
	if (n == 0) return false;
	for (size_t i = 0; i < n; i++) {
		cin >> aux;
		numbers.push_back(aux);
	}
	cout << getDifferentValues(numbers, 0, numbers.size() - 1, numbers[0], numbers[numbers.size() - 1]) << endl;
	return true;
}

int main() {
	while (solve()) {}
	return 0;
}