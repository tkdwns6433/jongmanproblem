//줄세우기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> graph[32005];
int ind[32005];
queue<int> q;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int first, second;
		cin >> first >> second;
		graph[first].push_back(second);
		ind[second] += 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int y = graph[cur][i];
			ind[y] -= 1;
			if (ind[y] == 0)
			{
				q.push(graph[cur][i]);
			}
		}
	}
	return 0;
}