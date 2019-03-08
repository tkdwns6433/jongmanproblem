//¿¬¼ÓÇÕ d[n] = max( d[n - 1] + a[n], a[n]) 
#include <iostream>
#include <algorithm>

using namespace std;

int d[100005];
int seq[100005];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> seq[i];
	}
	d[1] = seq[1];
	for (int i = 2; i <= n; i++)
	{
		d[i] = max(seq[i], seq[i] + d[i - 1]);
	}
	int ret = d[1];
	for (int i = 2; i <= n; i++)
	{
		ret = max(ret, d[i]);
	}
	cout << ret << endl;
	return 0;
}