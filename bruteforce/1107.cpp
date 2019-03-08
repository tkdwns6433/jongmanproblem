//������
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
	//��� ���ڹ�ư�� ������ +-�� �̷���� ����� ����, �������������� +- ����
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