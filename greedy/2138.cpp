//�����ͽ���ġ
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string light, light2;
string answer;
int n;
int ans = 0;
void changebulb(string & light ,int pos)
{
	if (light[pos] == '0')
		light[pos] = '1';
	else
		light[pos] = '0';
}

int main()
{
	cin >> n;
	cin >> light >> answer;
	light2 = light;

	int ret = 0;
	//0���� ü�������� �ʾ��� ��
	for (int i = 1; i < n; i++)
	{
		if (light[i - 1] != answer[i - 1])
		{
			changebulb(light ,i);
			changebulb(light, i - 1);
			if (i != n - 1)
			{
				changebulb(light, i + 1);
			}
			++ans;
		}
	}
	if (light == answer)
	{
		ret = ans;
	}
	else
		ret = -1;
	
	//0���� ü���� ���� ��
	ans = 1;
	changebulb(light2, 0);
	changebulb(light2, 1);
	for (int i = 1; i < n; i++)
	{
		if (light2[i - 1] != answer[i - 1])
		{
			changebulb(light2, i);
			changebulb(light2, i - 1);
			if (i != n - 1)
			{
				changebulb(light2, i + 1);
			}
			++ans;
		}
	}
	if (ret == -1)
	{
		if (light2 == answer)
		{
			cout << ans << endl;
		}
		else
			cout << -1 << endl;
	}
	else if (light2 == answer)
	{
		cout << min(ret, ans) << endl;
	}
	else
		cout << ret << endl;
	return 0;
}