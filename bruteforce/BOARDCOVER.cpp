#include <vector>
#include <iostream>

using namespace std;

/*
3
3 7
#.....#
#.....#
##...##
3 7
#.....#
#.....#
##..###
8 10
##########
#........#
#........#
#........#
#........#
#........#
#........#
##########
*/



vector<vector<char> > board(20, vector<char>(20));
int h, w;

int block[4][3][2] = { {{0, 0}, {1, 0}, {0, 1}}, //y x 
						{{0, 0}, {1, 0}, {1, 1}},
						{{0, 0}, {0, 1}, {1, 1}},
						{{0, 0}, {1, 0}, {1, -1}} };

bool set(int y, int x, int t_block)
{
	for (int i = 0; i < 3; i++)
	{
		int ny = y + block[t_block][i][0];
		int nx = x + block[t_block][i][1];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w)
			return false;
		else if (board[ny][nx] == '#')
			return false;
	}
	board[y + block[t_block][0][0]][x + block[t_block][0][1]] = '#';
	board[y + block[t_block][1][0]][x + block[t_block][1][1]] = '#';
	board[y + block[t_block][2][0]][x + block[t_block][2][1]] = '#';
	return true;

}

void unset(int y, int x, int t_block)
{
	board[y + block[t_block][0][0]][x + block[t_block][0][1]] = '.';
	board[y + block[t_block][1][0]][x + block[t_block][1][1]] = '.';
	board[y + block[t_block][2][0]][x + block[t_block][2][1]] = '.';
}

int coverboard()
{
	int x = -1, y = -1;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] == '.')
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)
			break;
	}
	if (y == -1)
		return 1;
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		if (set(y, x, i))
		{
			ret += coverboard();
			unset(y, x, i);
		}
	}
	return ret;
}

int main()
{
	int test_case;
	cin >> test_case;
	while (test_case)
	{
		cin >> h >> w;
		cin.get();
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				board[i][j] = cin.get();
			}
			cin.get();
		}

		cout << coverboard() << endl;

		--test_case;
	}
	return 0;
}

