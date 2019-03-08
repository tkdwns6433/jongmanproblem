#include <iostream>

using namespace std;

int num[22];
int sum;

int main()
{
	int n;
	cin >> n >> sum;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	int ret = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		int cal = 0;
		for (int j = 0; j < 20; j++)
		{
			if ((i >> j) & 1)
			{
				cal = cal + num[j];
			}
		}
		if (cal == sum)
		{
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}