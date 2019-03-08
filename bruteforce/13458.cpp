#include <iostream>
#include <vector>
using namespace std;

int testCnt;
int a[10000005];
int major, minor;

int main()
{
	cin >> testCnt;
	for (int i = 0; i < testCnt; ++i)
	{
		cin >> a[i];
	}
	cin >> major >> minor;
	long long ans = 0;
	for (int i = 0; i < testCnt; ++i)
	{
		ans++;
		a[i] -= major;
		int check = a[i] % minor;
		if (a[i] <= 0)
		{
			continue;
		}
		if (check == 0) {
			ans = ans + a[i] / minor;
		}
		else
		{
			ans = ans + a[i] / minor + 1;
		}
	}
	cout << ans << endl;
	return 0;
}