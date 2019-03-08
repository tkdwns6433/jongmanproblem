//다리만들기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> a(101);
int check[102][102];
int dis[102][102];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
int is_num = 1;
int main()
{
	int n;
	//입력을 받아서 동적배열 a에 값들을 채워넣음
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int input;
			cin >> input;
			a[i].push_back(input);
		}
	}

	queue<pair<int, int>> q;
	//섬을 그룹으로 나눈다.
	//bfs 시작, 시작점을 알 수 없으니 모든 곳에서 해봐야함.
	//두가지를 생각해봐야함 섬의 영역과 거리 check은 영역 dis는 거리
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] == 1 && check[i][j] == 0)
			{
				q.push(make_pair(i, j));
				check[i][j] = is_num;
				++is_num;
			}
			while (!q.empty())
			{
				int r = q.front().first;
				int c = q.front().second;
				q.pop();
				for (int k = 0; k < 4; ++k)
				{
					int nr = dr[k] + r;
					int nc = dc[k] + c;
					if (nr >= 0 && nr < n && nc >= 0 && nc < n)
						if (check[nr][nc] == 0 && a[nr][nc] == 1)
						{
							check[nr][nc] = check[r][c];
							q.push(make_pair(nr, nc));
						}
				}
			}

		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
		}

	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int nr = dr[k] + r;
			int nc = dc[k] + c;
			if (nr >= 0 && nr < n && nc >= 0 && nc < n)
				if (check[nr][nc] == 0 && a[nr][nc] == 0)
				{
					dis[nr][nc] = dis[r][c] + 1;
					check[nr][nc] = check[r][c];
					q.push(make_pair(nr, nc));
				}
		}
	}
	int max_val = 10000;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				int nr = dr[k] + i;
				int nc = dc[k] + j;
				if (nr >= 0 && nr < n && nc >= 0 && nc < n)
				{
					if (check[i][j] != check[nr][nc])
						max_val = min(max_val, dis[i][j] + dis[nr][nc]);
				}
			}
		}
	cout << max_val << endl;
	return 0;
}