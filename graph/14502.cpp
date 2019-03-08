#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int r, c;
int map[10][10];

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < r*c - 2; i++)
	{
		for (int j = i + 1; j < r*c - 1; j++)
		{
			for (int k = j + 1; k < r*c; k++)
			{
				i
			}
		}
	}
}