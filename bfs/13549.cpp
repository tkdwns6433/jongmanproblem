//¼û¹Ù²ÀÁú3
#include <iostream>
#include <queue>

using namespace std;

bool visit[100005];
int subin, sis;

int main()
{
	cin >> subin >> sis;
	queue<pair<int, int>> q0;
	queue<pair<int, int>> q1;
	q1.push(make_pair(subin, 0));
	visit[subin] = true;
	while (!q1.empty())
	{
		auto cur = q1.front();
		q1.pop();
		if (cur.first == sis)
		{
			cout << cur.second << endl;
			return 0;
		}
		if (cur.first * 2 <= 100000 && !visit[cur.first * 2])
		{
			visit[cur.first * 2] = true;
			q0.push(make_pair(cur.first * 2, cur.second));
		}
		if (cur.first + 1 <= 100000 && !visit[cur.first + 1])
		{
			visit[cur.first + 1] = true;
			q1.push(make_pair(cur.first + 1, cur.second + 1));
		}
		if (cur.first - 1 >= 0 && !visit[cur.first - 1])
		{
			visit[cur.first - 1] = true;
			q1.push(make_pair(cur.first - 1, cur.second + 1));
		}
		while (!q0.empty())
		{
			auto cur = q0.front();
			q0.pop();
			if (cur.first == sis)
			{
				cout << cur.second << endl;
				return 0;
			}
			if (cur.first * 2 <= 100000 && !visit[cur.first * 2])
			{
				visit[cur.first * 2] = true;
				q0.push(make_pair(cur.first * 2, cur.second));
			}
			if (cur.first + 1 <= 100000 && !visit[cur.first + 1])
			{
				visit[cur.first + 1] = true;
				q1.push(make_pair(cur.first + 1, cur.second + 1));
			}
			if (cur.first - 1 >= 0 && !visit[cur.first - 1])
			{
				visit[cur.first - 1] = true;
				q1.push(make_pair(cur.first - 1, cur.second + 1));
			}
		}
	}
}