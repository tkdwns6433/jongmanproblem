//구슬탈출2
#include <iostream>
#include <algorithm>
#include <vector>
//비트마스크 1 1 1 1 1 1 1 1 1 1 // 1 ~ 4 왼쪽 오른쪽 위쪽 아래쪽 기울이기
//두배로 확장 11 11 11 11 11 11 11 11 11 
//0왼쪽 1오른쪽 2위쪽 3아래쪽
using namespace std;

int r, c;
char board[15][15];

int check(vector<int> & dir)
{
	for (int i = 0; i < length; i++)
	{

	}
}

vector<int> gen(int bit)
{
	vector<int> a(10);
	for (int i = 0; i < 10; i++)
	{
		a[i] = (bit & 3);
		bit >>= 2;
	}
	return a;
}

bool valid(vector<int> & dir)
{
	for (int i = 1; i < dir.size(); i++)
	{
		if (dir[i] == 0 && dir[i - 1] == 1) return false;
		if (dir[i] == 1 && dir[i - 1] == 0) return false;
		if (dir[i] == 2 && dir[i - 1] == 3) return false;
		if (dir[i] == 3 && dir[i - 1] == 2) return false;
		if (dir[i] == dir[i - 1]) return false;
	}
	return true;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin.get();
		for (int j = 0; j < c; j++)
		{
			board[r][c] = cin.get();
		}
	}
	int ans = -1;
	for (int i = 0; i < (1 << 20); i++)
	{
		auto dir = gen(i);
		if (!valid(dir))
		{
			continue;
		}
		int result = check(dir);
		if (result != -1)
		{
			ans = min(ans, result);
		}
	}
	cout << ans << endl;
	return 0;
}