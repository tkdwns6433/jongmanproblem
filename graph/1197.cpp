//최소스피닝트리
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int start, end, cost;
	bool operator <(const Edge & other)
	{
		return cost < other.cost;
	}
};

int parent[10001];

int Find(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	else
	{
		return Find(parent[x]);
	}
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}

vector<Edge> edges;

int main()
{
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		Edge e;
		cin >> e.start >> e.end >> e.cost;
		edges.push_back(e);
	}
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}

	sort(edges.begin(), edges.end());
	long long ans = 0;
	for (int i = 0; i < e; i++)
	{
		int v1, v2;
		v1 = edges[i].start;
		v2 = edges[i].end;
		if (Find(v1) != Find(v2))
		{
			Union(v1, v2);
			ans += edges[i].cost;
		}
	}
	cout << ans << endl;
	return 0;
}


