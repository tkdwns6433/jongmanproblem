//��ģ��
#include <iostream>

using namespace std;

long long d[101][2]; //n��° �ڸ��� ���� 0�� �� ��ģ���� ����

int main()
{
	int n;
	cin >> n;
	d[1][1] = 1;
	d[1][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	long long ans = d[n][0] + d[n][1];
	cout << ans << endl;
	return 0;
}