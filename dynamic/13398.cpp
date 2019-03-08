//연속합2
#include <iostream>
#include <algorithm>

using namespace std;

int dl[100050];
int dr[100050];
int n;
int a[100050];
//왼쪽 부분합 오른쪽 부분합을 이용한다.

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	dl[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		dl[i] = max(dl[i - 1] + a[i], a[i]);
	}
	dr[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		dr[i] = max(dr[i + 1] + a[i], a[i]);
	}

	int ret = -987654321;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && i < n - 1)
		{
			ret = max(max(ret, dl[i]), dl[i - 1] + dr[i + 1]);
		}
		if (i == 0)
		{
			ret = max(max(ret, dl[i]), dr[i + 1]);
		}
		if (i == n - 1)
		{
			ret = max(max(ret, dl[i]), dl[i - 1]);
		}
	}
	cout << ret << endl;
	return 0;
}