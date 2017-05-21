#include <iostream>
#include <deque>
#include <stack>
#include <string>

using namespace std;

/*bool comprobar(stack<char> &principios, deque<char> &finales) {
	if (principios.size() != finales.size()) return false;
	while (!principios.empty()) {
		if (principios.top() == '(') {
			if (finales.front() != ')') return false;
		}
		else {
			if (finales.front() != ']') return false;
		}
		principios.pop();
		finales.pop_front();
	}
	return true;
}*/

void resuelve() {
	stack <char> principios;
	//deque <char> finales;
	bool correcto = true;
	string s;

	getline(cin, s);
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '[') principios.push(s[i]);
		else {
			if (principios.empty()) {
				correcto = false;
				break;
			}
			if (s[i] == ')') {
				if (principios.top() != '(') {
					correcto = false;
					break;
				}
			}
			else {
				if (principios.top() != '[') {
					correcto = false;
					break;
				}
			}
			principios.pop();
		}
	}
	if (correcto && principios.empty()) cout << "Yes" << '\n';
	else cout << "No" << '\n';

	//if (comprobar(principios, finales)) cout << "Yes" << '\n';
	//else cout << "No" << '\n';
}

int main() {
	int n;
	string s;

	cin >> n;
	getline(cin, s);
	for (int i = 0; i < n; ++i) {
		resuelve();
	}
}