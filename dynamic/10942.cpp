//Æç¸°µå·Ò??
#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[2001];
int d[2001][2001];
int question;

int felindrom(int start, int end)
{
	if (start == end)
	{
		return 1;
	}
	if (start + 1 == end) 
	{
		if (a[start] == a[end])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if (d[start][end] != -1) 
	{
		return d[start][end];
	}

	if (a[start] != a[end])
	{
		return d[start][end] = 0;
	}
	else
	{
		return d[start][end] = felindrom(start + 1, end - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cin >> question;
	for (int i = 0; i < question; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << felindrom(s, e) << '\n';
	}
	return 0;
}