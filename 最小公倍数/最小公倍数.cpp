#include <iostream>
using namespace std;
int main() {
	int a, b;
	while (cin >> a >> b) 
	{
		int m, n, temp;
		if (a < b) 
		{
			temp = a;
			a = b;
			b = temp;
		}
		m = a;
		n = b;
		while (b != 0) 
		{
			temp = a % b;
			a = b;
			b = temp;
		}
		cout << m * n / a << endl;
	}
	return 0;
}

