//Daniel Garcia Molero

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Esta solucion tiene un coste en tiempo y espacio de O(x*y), donde x e y son la
//longitud de las palabras 1 y 2 respectivamente
int getLongestSequence(const string &p1, const string &p2) {
	//p1 = rows, p2 = cols
	vector<vector<int>> matrix = vector<vector<int>>(p1.length() + 1, vector<int>(p2.length() + 1, 0));
	int last;
	for (size_t i = 1; i <= p1.length(); i++) {
		last = -1;
		for (size_t j = 1; j <= p2.length(); j++) {
			if (p1[i - 1] == p2[j - 1]) {
				if ((i == 0 || matrix[i - 1][j] == 0)) {
					matrix[i][j]++;
				} else {
					if (last != -1 && matrix[i - 1][j] != matrix[i - 1][last]) { 
						matrix[i][j] = matrix[i - 1][j] + 1;
					} else {
						matrix[i][j] = max(matrix[i - 1][j] + 1, matrix[i][j - 1]);
					}
				}
				last = j;
			} else {
				matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
	}
	return matrix[p1.length()][p2.length()];
}

bool solve() {
	string palabra1, palabra2;
	cin >> palabra1 >> palabra2;
	if (!cin) return false;
	cout << getLongestSequence(palabra1, palabra2) << endl;
	return true;
}

int main() {
	while (solve()) {}
	return 0;
}