#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, m;
int d[10003][32]; //i초에 j번 턴 했을 때! 주울수 있는 자두
int a[10003];

int go(int pos, int turn)
{
	if (pos == n + 1 && turn <= m)
	{
		return 0;
	}
	if (turn > m)
	{
		return 0;
	}
	if (d[pos][turn] != -1)
	{
		return d[pos][turn];
	}
	int where = turn % 2 + 1;
	int & ans = d[pos][turn];
	ans = max(go(pos + 1, turn), go(pos + 1, turn + 1)) +
		(where == a[pos] ? 1 : 0);
	return ans;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cout << max(go(1, 0), go(1, 1));
	return 0;
}