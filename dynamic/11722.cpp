//가장 긴 감소하는 부분수열
#include <iostream>
#include <algorithm>

using namespace std;

int a[1050];
//i번째에서 감소하는 부분수열의 길이 d[i] = max(d[j]) + 1 , j < i, a[j] > a[i]
int d[1050];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	d[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[j] > a[i])
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