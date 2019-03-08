//네트워크 연결
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct  Edge
{
	int start, end, cost;
	bool operator < (const Edge & other) const {
		return cost < other.cost;
	}
};


int p[10001];
int computer, edge;
int Find(int x)
{
	if (x == p[x])
	{
		return x;
	}
	else
	{
		return p[x] = Find(p[x]);
	}
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

int main()
{
	cin >> computer >> edge;
	for (int i = 1; i <= computer; i++)
	{
		p[i] = i;
	}
	vector<Edge> a(edge);
	for (int i = 0; i < edge; i++)
	{
		cin >> a[i].start >> a[i].end >> a[i].cost;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < edge; i++)
	{
		Edge e = a[i];
		int x = Find(e.start);
		int y = Find(e.end);
		if (x != y)
		{
			Union(e.start, e.end);
			ans += e.cost;
		}
	}
	cout << ans << endl;
	return 0;
}