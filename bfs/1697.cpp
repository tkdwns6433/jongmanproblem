//¼û¹Ù²ÀÁú
#include <iostream>
#include <queue>

using namespace std;

bool visit[100005];
int subin, sis;

int main()
{
	cin >> subin >> sis;
	queue<pair<int, int>> q;
	q.push(make_pair(subin, 0));
	visit[subin] = true;
	while (!q.empty())
	{
		auto element = q.front();
		q.pop();
		if (element.first == sis)
		{
			cout << element.second << endl;
			return 0;
		}
		if (element.first + 1 <= 100000 && !visit[element.first + 1])
		{
			visit[element.first + 1] = true;
			q.push(make_pair(element.first + 1, element.second + 1));
		}
		if (element.first - 1 >= 0 && !visit[element.first - 1])
		{
			visit[element.first - 1] = true;
			q.push(make_pair(element.first - 1, element.second + 1));
		}
		if (element.first * 2 <= 100000 && !visit[element.first * 2])
		{
			visit[element.first * 2] = true;
			q.push(make_pair(element.first * 2, element.second + 1));
		}
	}
}