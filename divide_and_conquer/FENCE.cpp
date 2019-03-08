#include <iostream>
#include <algorithm>

using namespace std;

int fence_num;
int fence_height[20000];

int max_fence(int start, int end)
{
	if (start == end)
		return fence_height[start];
	int mid = (start + end) / 2;
	int ret = max(max_fence(start, mid), max_fence(mid + 1, end));
	int lo = mid, hi = mid + 1;
	int height = min(fence_height[lo], fence_height[hi]);
	ret = max(ret, height * 2);
	while (start < lo || hi < end)
	{
		if (hi < end && (lo == start || fence_height[lo - 1] < fence_height[hi + 1]))
		{
			++hi;
			height = min(height, fence_height[hi]);
		}
		else
		{
			--lo;
			height = min(height, fence_height[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		cin >> fence_num;
		for (int i = 0; i < fence_num; i++)
		{
			cin >> fence_height[i];
		}
		cout << max_fence(0, fence_num - 1) << endl;
	}
}