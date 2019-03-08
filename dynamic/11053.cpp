//가장 긴 증가하는 부분수열
#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int seq[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> seq[i];
		d[i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; ++j)
		{
			if (seq[i] > seq[j])
			{
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret = max(ret, d[i]);
	}
	cout << ret << endl;
	return 0;
}