//제곱수의 합 d[n] 자연수 n이 최소의 제곱수로 표현된 개수
// d[n] = min(d[n - i*i] + 1) 
#include <iostream>
#include <algorithm>
using namespace std;

int d[100050];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int min_d = d[i - 1];
		for (int j = 2; j*j <= i; j++)
		{
			min_d = min(min_d, d[i - j * j]);
		}
		d[i] = min_d + 1;
	}
	cout << d[n] << endl;
	return 0;
}