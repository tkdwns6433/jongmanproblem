//≈‰∏∂≈‰
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int tomato[1010][1010];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main()
{
	int r, c;
	cin >> c >> r;
	queue<pair<int, int>> q;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
			{
				q.push(make_pair(i, j) );
			}
		}
	}

	while (!q.empty())
	{
		auto pos = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (pos.first + dr[i] >= 0 && pos.first + dr[i] < r && pos.second + dc[i] >= 0 && pos.second + dc[i] < c)
			{
				if (tomato[pos.first + dr[i]][pos.second + dc[i]] == 0)
				{
					tomato[pos.first + dr[i]][pos.second + dc[i]] = tomato[pos.first][pos.second] + 1;
					q.push(make_pair(pos.first + dr[i], pos.second + dc[i]));
				}
			}
		}
	}
	
	int ret = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; ++j)
		{
			if (tomato[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			else
			{
				ret = max(ret, tomato[i][j]);
			}
		}
	}
	cout << ret - 1 << endl;
	return 0;
}