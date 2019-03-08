#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dis[12][12];
vector<int> permu;


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> dis[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		permu.push_back(i);
	}

	int ret = 987654321;

	do
	{
		int distanceValue = 0;
		bool canGo = true;
		for (int i = 0; i < n; i++)
		{
			if (i == n - 1)
			{
				if (!dis[permu[n - 1]][permu[0]])
				{
					canGo = false;
					break;
				}
				distanceValue += dis[permu[n - 1]][permu[0]];
			}
			else
			{
				if (!dis[permu[i]][permu[i + 1]])
				{
					canGo = false;
					break;
				}
				distanceValue += dis[permu[i]][permu[i + 1]];
			}
		}
		if (canGo)
		{
			ret = min(ret, distanceValue);
		}
	} while (next_permutation(permu.begin() + 1, permu.end()));

	cout << ret << endl;

	return 0;
}