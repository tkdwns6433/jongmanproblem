//리모컨
#include <iostream>

using namespace std;

bool broken[10];

int possible(int c)
{
	if (c == 0)
	{
		return broken[0] ? 0 : 1;
	}
	int len = 0;
	while (c > 0)
	{
		if (broken[c % 10]) {
			return 0;
		}
		len += 1;
		c = c / 10;
	}
	return len;
}

int main()
{
	int channel;
	cin >> channel;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		broken[input] = true;
	}
	//모든 숫자버튼을 눌러서 +-로 이루어진 경우의 수와, 시작지점에서의 +- 개수
	int ans = channel - 100;
	if (ans < 0)
	{
		ans = -ans;
	}
	for (int i = 0; i <= 100000; i++)
	{
		int c = i;
		int len = possible(c);
		if (len > 0)
		{
			int press = c - n;
			if (press < 0)
			{
				press = -press;
			}
			if (ans > press)
			{
				ans = press + len;
			}
		}
	}
	cout << ans << endl;
	return 0;
}