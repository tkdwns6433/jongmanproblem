//퇴사

#include <iostream>
#include <algorithm>

using namespace std;

int time[18];
int pay[18];

int n;

//오늘 상담을 한다고 결정하는 것
int go(int earn, int curday)
{
	if (curday >= n + 1)
	{
		return earn;
	}
	int ret = 0;
	if(curday + time[curday] <= n + 1)
		ret = max(go(earn + pay[curday], curday + time[curday]), ret);
	ret = max(ret, go(earn, curday + 1));
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> time[i] >> pay[i];
	}

	cout << go(0, 1) << endl;
	return 0;
}