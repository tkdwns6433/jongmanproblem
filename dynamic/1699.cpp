//�������� �� d[n] �ڿ��� n�� �ּ��� �������� ǥ���� ����
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