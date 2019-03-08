//타임머신
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dist[505];
bool check[505];
int cnt[505];
struct Edge
{
	int end, cost;
};

vector<Edge> list[501];

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
		int in_start, in_end, in_cost;
		cin >> in_start >> in_end >> in_cost;
		Edge ed;
		ed.end = in_end, ed.cost = in_cost;
		list[in_start].push_back(ed);
	}
	dist[1] = 0;
	bool negative_inf = false;
	queue<int> q;
	q.push(1);
	check[1] = false;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		check[cur] = false;
		for (int i = 0; i < list[cur].size(); i++)
		{
			int end = list[cur][i].end;
			int cost = list[cur][i].cost;
			if (dist[end] > dist[cur] + cost)
			{
				dist[end] = dist[cur] + cost;
				if (check[end] == false)
				{
					q.push(end);
					check[end] = true;
					cnt[end] += 1;
					if (cnt[end] >= v)
					{
						cout << -1 << endl;
						return 0;
					}
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