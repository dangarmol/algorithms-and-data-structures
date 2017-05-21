#include <iostream>
#include <vector>
using namespace std;

int checkGradient(bool &isGrad, const vector<int> &line, const size_t &start, const size_t &end) {
	size_t half = (start + end) / 2;
	int right, left;
	if (end - start == 1) {
		right = line[end];
		left = line[start];
	} else {
		right = checkGradient(isGrad, line, half + 1, end);
		left = checkGradient(isGrad, line, start, half);
	}
	if (left >= right) {
		isGrad = false;
	}
	return left + right;
}

bool solve() {
	int rows, cols, rowCounter = 0;
	bool isGrad = true;
	cin >> rows >> cols;
	vector<int> line (cols);
	if (!cin) return false;
	while (isGrad && rowCounter < rows)
	{
		for (size_t i = 0; i < cols; i++) {
			cin >> line[i];
		}
		checkGradient(isGrad, line, 0, cols - 1);
		rowCounter++;
	}
	for (size_t j = 0; j < (rows - rowCounter) * cols; j++)
		cin.ignore();
	if (isGrad) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return true;
}

int main() {
	while (solve()) {}
	return 0;
}