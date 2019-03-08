//±¤°í
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> preprocessing(string p)
{
	vector<int> pi(p.size());
	int j = 0;
	pi[j] = 0;
	int len = p.size();
	for (int i = 1; i < len; i++)
	{
		while (j > 0 && p[i] != p[j])
		{
			j = pi[j - 1];
		}
		if (p[i] == p[j])
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
	int n;
	cin >> n;
	cin.get();
	string input;
	getline(cin, input);
	auto ans = preprocessing(input);
	cout << n - ans[n - 1] << endl;
	return 0;
}