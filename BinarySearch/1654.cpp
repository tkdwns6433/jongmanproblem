#include <iostream>
#include <algorithm>

using namespace std;

long long n, length;
long long lan[10050];

int main()
{
	cin >> n >> length;
	long long right = 0, left = 1, max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> lan[i];
		if (max < lan[i])
		{
			max = lan[i];
		}
	}

	right = max;

	long long ans = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += (lan[i] / mid);
		}
		if (sum >= length)
		{
			if (ans < mid)
			{
				ans = mid;
			}
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}