//이동하기
#include <iostream>
#include <algorithm>

using namespace std;

int r, c;
int maze[1050][1050];
int d[1050][1050];

int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> maze[i][j];
		}
	}

	
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			d[i][j] = max(max(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + maze[i][j];
		}
	}
	cout << d[r][c] << endl;
	return 0;
}