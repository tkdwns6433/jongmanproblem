//최소비용구하기
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int v, e;
vector<pair<int, int>> endAndCost[1005];
int dist[1001];
bool check[1001];

const int inf = 987654321;

int main()
{
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		endAndCost[start].push_back(make_pair(end, cost));
	}
	int start, end;
	cin >> start >> end;
	for (int i = 0; i < 1001; i++)
	{
		dist[i] = inf;
	}
	dist[start] = 0;
	
	for (int i = 1; i <= v - 1; i++)
	{
		//가장 작은 dist를 찾기
		int curVertex, tempDist = inf + 1;
		for (int j = 1; j <= v; j++)
		{
			if (check[j] == false && dist[j] < tempDist) 
			{
				curVertex = j;
				tempDist = dist[j];
			}
		}
		check[curVertex] = true;
		for (int j = 0; j < endAndCost[curVertex].size(); j++)
		{
			int end = endAndCost[curVertex][j].first, cost = endAndCost[curVertex][j].second;
			if (dist[end] > dist[curVertex] + cost)
			{
				dist[end] = dist[curVertex] + cost;
			}
		}
	}
	cout << dist[end] << endl;
	return 0;
}