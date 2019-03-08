//�۾�
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int ind[10005];
int workTime[10005];
vector<int> list[10005];
int n;
int d[10005]; //���� �۾��� ������ �� �ɸ� �ּ� �ð� ���� ����Ǿ�� �ϱ� ������ ���� �� �� ���� ū ���� ���� �ȴ�.

int main()
{
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int time, preCount, pre;
		cin >> workTime[i] >> preCount;
		for (int j = 0; j < preCount; j++)
		{
			cin >> pre;
			++ind[i];
			list[pre].push_back(i);
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			d[i] = workTime[i];
			q.push(i);
		}
	}
	int ans = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < list[cur].size(); i++)
		{
			--ind[list[cur][i]];
			d[list[cur][i]] = max(d[list[cur][i]], d[cur] + workTime[list[cur][i]]);
			if (ind[list[cur][i]] == 0)
			{
				q.push(list[cur][i]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, d[i]);
	}
	cout << ans << endl;

	return 0;
}