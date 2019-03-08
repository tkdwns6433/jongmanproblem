//µË∫∏¿‚
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int noListen, noLook;
	cin >> noListen >> noLook;
	map<string, int> s;
	for (int i = 0; i < noListen; i++)
	{
		string input;
		cin >> input;
		s.insert(make_pair(input, 0));
	}
	int ans = 0;
	for (int i = 0; i < noLook; i++)
	{
		string input;
		cin >> input;
		auto searched = s.find(input);
		if (searched != s.end())
		{
			searched->second = 1;
			++ans;
		}
	}
	cout << ans << endl;
	for (auto & iter : s)
	{
		if (iter.second == 1)
		{
			cout << iter.first << '\n';
		}
	}
	return 0;
}