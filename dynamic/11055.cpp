//가장 큰 증가하는 부분순열
#include <iostream>
#include <algorithm>
using namespace std;

int a[1050];
//i번 째로 끝나는 부분수열의 합 d[i] = max(d[j]) + a[i]
int d[1050];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n; i++)
	{
		cin >> a[i];
	}
	d[1] = a[1];

	for (int i = 2; i <= n; i++)
	{
		d[i] = a[i];
		for (int j = 1; j < i; ++j)
		{
			if (a[j] < a[i])
			{
				d[i] = max(d[i], d[j] + a[i]);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i <= n; i++)
	{
		ret = max(ret, d[i]);
	}
	cout << ret << endl;
	return 0;
}