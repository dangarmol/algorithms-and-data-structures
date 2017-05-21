#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int complementarios(const int &num)
{
    if (num < 10) {
        return (9 - num % 10);
    }
    return (10 * complementarios(num / 10)) + (9 - num % 10);
}

int main()
{
	int num;
    cin >> num;
	while (num != -1)
	{
		cout << complementarios(num) << endl;
        cin >> num;
	}
	return 0;
}