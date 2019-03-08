//합분해
#include <iostream>

using namespace std;

int d[300][300]; // K개의 정수로 N이 만들어진 경우의 수

int divi(int n, int k)
{
	if (n == 0)
	{
		return 1;
	}
	if (k == 0)
		return 0;

	if (d[n][k] != 0)
	{
		return d[n][k];
	}

	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans = (ans + divi(n - i, k - 1)) % 1000000000;
	}
	return d[n][k] = ans;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << divi(n, k) << endl;
	return 0;
}