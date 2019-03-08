//ºØ¾î»§ ÆÇ¸ÅÇÏ±â
#include <iostream>
#include <algorithm>
using namespace std;

int d[1001];
int card[1001];

int sell(int n)
{
	int & ret = d[n];
	if (ret != 0)
	{
		return ret;
	}

	for (int i = 1; i <= n; ++i)
	{
		ret = max(ret, card[i] + sell(n - i));
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> card[i + 1];
	}
	d[1] = card[1];
	cout << sell(n) << endl;
	return 0;
}