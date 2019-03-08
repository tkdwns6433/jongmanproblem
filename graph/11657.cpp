//타임머신
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dist[505];

struct Edge
{
	int start, end, cost;
};

vector<Edge> edges;

int main()
{
	for (int i = 0; i < 505; i++)
	{
		dist[i] = 987654321;
	}
	
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		Edge ed;
		cin >> ed.start >> ed.end >> ed.cost;
		edges.push_back(ed);
	}
	dist[1] = 0;
	bool negative_inf = false;
	for (int i = 1; i <= v; i++)
	{
		for (int j = 0; j < e; j++)
		{
			int start = edges[j].start;
			int end = edges[j].end;
			int cost = edges[j].cost;
			if (dist[start] != 987654321 && dist[end] > dist[start] + cost)
			{
				dist[end] = dist[start] + cost;
				if (i == v)
				{
					negative_inf = true;
				}
			}
		}
	}

	if (negative_inf)
	{
		cout << -1 << endl;
	}
	else
	{
		for (int i = 2; i <= v; i++)
		{
			if (dist[i] == 987654321) dist[i] = -1;
			cout << dist[i] << endl;
		}
	}
	
	return 0;
}