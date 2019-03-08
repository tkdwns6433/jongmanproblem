//쉬운계단수
#include <iostream>

using namespace std;

int d[101][10];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++)
	{
		d[1][i] = 1;
	}
	d[1][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
			{
				d[i][j] = d[i - 1][j + 1] % 1000000000;
			}
			else if (j == 9)
			{
				d[i][j] = d[i - 1][j - 1] % 1000000000;
			}
			else
			{
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans = (ans + d[n][i]) % 1000000000;
	}
	
	cout << ans << endl;
	return 0;
}