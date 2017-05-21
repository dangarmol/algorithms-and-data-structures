#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Palabra {
public:
	vector<int> s;
	Palabra() {}
	Palabra(string p) {
		s = vector<int>(p.size() + 1);
		for (int i = 0; i < p.size(); ++i) {
			if (p[i] == 'a') s[i + 1] = 0;
			else if (p[i] == 'b') s[i + 1] = 1;
			else s[i + 1] = 2;
		}
	}
};

int calcular(const vector<vector<int>> &tabla, Palabra &p, int i, int j) {
	if (j - i == 1) return tabla[p.s[i]][p.s[j]];
	else return tabla[calcular(tabla, p, i + 1, j)][calcular(tabla, p, i, j - 1)];
}

bool resuelve(const vector<vector<int>> &tabla) {
	string s;

	cin >> s;
	if (!cin) return false;
	else {
		Palabra p(s);
		int res = calcular(tabla, p, 0, s.size());
		if (res == 0) cout << "SI" << endl;
		else cout << "NO" << endl;
		return true;
	}
}

int main() {
	unordered_map<char, int> conversion;
	vector<vector<int>> tabla(3, vector<int>(3));
	tabla[0][0] = 1;
	tabla[0][1] = 1;
	tabla[0][2] = 0;
	tabla[1][0] = 2;
	tabla[1][1] = 1;
	tabla[1][2] = 0;
	tabla[2][0] = 0;
	tabla[2][1] = 2;
	tabla[2][2] = 2;

	while (resuelve(tabla)) {}
	return 0;
}