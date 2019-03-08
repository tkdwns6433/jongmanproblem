//cube editor ½ÇÆÐÇÔ
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> preprocessing(string p)
{
	int len = p.size();
	vector<int> pi(len);
	int j = 0;
	pi[0] = 0;
	for (int i = 1; i < len; i++)
	{
		while (j > 0 && p[j] != p[i])
		{
			j = pi[j - 1];
		}
		if (p[j] == p[i])
		{
			pi[i] = j + 1;
			++j;
		}
		else
		{
			pi[i] = 0;
		}
	}
	return pi;
}

int main()
{
	string input;
	getline(cin, input);
	int ans = 0;
	int len = input.size();
	for (int i = 1; i <= len; i++)
	{
		auto result = preprocessing(input.substr(0, i));
		for (int j = 0; j < result.size(); j++)
		{
			ans = max(ans, result[j]);
		}
	}
	
	cout << ans << endl;
	return 0;
}