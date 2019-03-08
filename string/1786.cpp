//Ã£±â
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> preprocessing(string p)
{
	int len = p.size();
	vector<int> pi(1000005);
	int j = 0;
	pi.push_back(j);
	for (int i = 1; i < len; i++)
	{
		while (j > 0 && p[j] != p[i])
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
	string input;
	string find;
	getline(cin, input);
	getline(cin, find);
	auto pi = preprocessing(find);
	
	vector<int> ans;
	int len = input.size();
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		while (j > 0 && input[i] != find[j])
		{
			j = pi[j - 1];
		}
		if (input[i] == find[j])
		{
			if (j == find.size() - 1)
			{
				ans.push_back(i - find.size() + 1);
				j = pi[j];
			}
			else
			{
				++j;
			}
		}
	}
	cout << ans.size() << endl; 
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]  + 1 << ' ';
	}
	cout << endl;
	return 0;
}