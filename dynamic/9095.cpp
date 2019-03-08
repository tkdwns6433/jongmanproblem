//1,2,3 ¥ı«œ±‚
#include <iostream>

using namespace std;

int d[11];

int onetwothree(int n) {
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return d[n];
	}
	if (d[n] != -1) 
	{
		return d[n];
	}
	return d[n] = onetwothree(n - 1) + onetwothree(n - 2) + onetwothree(n - 3);
}

int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < 11; i++)
		{
			d[i] = -1;
		}
		d[0] = 1;
		cout << onetwothree(n) << endl;
	}
	return 0;
}