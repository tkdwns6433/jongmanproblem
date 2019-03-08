#include<vector>
#include<map>
#include<algorithm>
using namespace std;

long long cal(vector<vector<int> > land, int P, int Q, int floor)
{
	long long result = 0;
	for (int i = 0; i < land.size(); i++)
	{
		for (int j = 0; j < land[0].size(); j++)
		{
			if (land[i][j] < floor)
			{
				result += P * (floor - land[i][j]);
			}
			else
			{
				result += Q * (land[i][j] - floor);
			}
		}
	}
	return result;
}

long long solution(vector<vector<int> > land, int P, int Q)
{
	long long answer = 2147483647;
	int l = 0;
	int h = 1000000000;
	int mid = (l + h) / 2;
	while (mid == l)
	{
		int lowMid = (l + mid) / 2;
		int highMid = (h + mid) / 2;
		long long lowMidValue = cal(land, P, Q, lowMid);
		long long highMidValue = cal(land, P, Q, highMidValue);
		long long MidValue = cal(land, P, Q, mid);
		if (lowMidValue > hig)
		{

		}
	}
	
	return answer;
}

int main()
{
	set<int> test;
	test.insert(1);
	test.insert(1);
	return 0;
}