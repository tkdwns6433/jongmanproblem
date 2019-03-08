#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0;
int total = 0;
int num = 1;
vector<vector<int>> a(26);
vector<int> ans;
int check[27][27];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void dfs(int r, int c)
{
	check[r][c] = num;
	++total;
	for (int k = 0; k < 4; ++k)
	{
		int nr = dr[k] + r;
		int nc = dc[k] + c;
		if (nr >= 0 && nc >= 0 && nr < n && nc < n)
			if (check[nr][nc] == 0 && a[nr][nc] == 1)
			{
				dfs(nr, nc);
			}
	}
}

int main()
{
	cin >> n;
	cin.get();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int input = cin.get() - '0';
			a[i].push_back(input);
		}
		cin.get();
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] == 1 && check[i][j] == 0)
			{
				total = 0;
				dfs(i, j);
				num++;
				ans.push_back(total);
			}
		}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
	return 0;
}