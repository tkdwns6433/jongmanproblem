//파일합치기
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n;
int file[505];
int d[505][505]; //d[i][j] i부터 j까지 연속된 파일을 만드는데 든 최소 비용

int go(int start, int end)
{
	if (start == end)
	{
		return 0;
	}
	if (d[start][end] != -1)
	{
		return d[start][end];
	}
	int sum = 0;
	for (int i = start; i <= end; i++)
	{
		sum += file[i];
	}
	int ret = 987654321;
	for (int i = start; i < end; i++)
	{
		ret = min(ret, go(start, i) + go(i + 1, end) + sum);
	}
	
	return d[start][end] = ret;
}

int main()
{
	cin >> t;
	while (t--)
	{
		memset(d, -1, sizeof(d));
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> file[i];
		}
		cout << go(1, n) << '\n';
	}
	return 0;
}