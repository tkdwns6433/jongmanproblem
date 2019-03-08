//2 x n ≈∏¿œ∏µ
#include <iostream>

using namespace std;

int d[1001];

int tiling(int i)
{
	if (i == 1)
	{
		return 1;
	}
	if (i == 2)
	{
		return 3;
	}
	if (d[i] != 0)
	{
		return d[i];
	}
	return d[i] = (tiling(i - 1) + tiling(i - 2) + tiling(i - 2))%10007;
}

int main()
{
	int n;
	cin >> n;
	cout << tiling(n);
}