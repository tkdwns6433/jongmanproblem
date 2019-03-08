//1학년
#include <iostream>

using namespace std;

int n;
int num[150];
long long d[150][21]; //i까지 수를 사용해서 j를 만드는 경우의 수

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	
	d[1][num[1]] = 1;
	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j - num[i] >= 0)
			{
				d[i][j] += d[i - 1][j - num[i]];
			}
			if (j + num[i] <= 20)
			{
				d[i][j] += d[i - 1][j + num[i]];
			}
		}
	}

	cout << d[n - 1][num[n]] << endl;
	return 0;
}