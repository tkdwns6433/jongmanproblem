//가장 긴 바이토닉 부분수열
#include <iostream>
#include <algorithm>

using namespace std;

int a[1050];
int l[1050];
int r[1050];
//왼쪽을 기준으로 하는 i번째로 끝나는 부분수열, 오른쪽을 기준으로도 구하고 두개를 더해준 후 - 1해주면 해당 지점을 기준으로 한 바이토닉
//수열의 길이가 나온다

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	l[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		l[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i])
			{
				l[i] = max(l[i], l[j] + 1);
			}
		}
	}
	r[n] = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		r[i] = 1;
		for (int j = n; j > i; j--)
		{
			if (a[j] < a[i])
			{
				r[i] = max(r[i], r[j] + 1);
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret = max(ret, l[i] + r[i] - 1);
	}
	cout << ret << endl;
	return 0;
}

