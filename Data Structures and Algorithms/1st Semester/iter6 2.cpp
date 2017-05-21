#include <iostream>
#include <string>

using namespace std;

bool resuelve(string linea)
{
	bool centinela = true;
	for (int k = linea.size() - 1; k > 0 && centinela; k--)
		centinela = linea[k] > linea[k - 1];

	return centinela;
}

int main()
{
	string linea;
		
	while (linea != "XXX")
	{
		getline(cin, linea);
		
		if (linea != "XXX")
			if (resuelve(linea))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
	}

	return 0;
}