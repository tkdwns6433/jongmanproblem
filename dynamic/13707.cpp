//�պ���2
#include <iostream>

using namespace std;

int d[5050][5050]; // K���� ������ N�� ������� ����� ��

int divi(int n, int k)
{
	if (n == 0)
	{
		return 1;
	}
	if (k == 0)
		return 0;

	if (d[n][k] != 0)
	{
		return d[n][k];
	}
	return d[n][k] = (divi(n - 1, k) + divi(n, k - 1)) % 1000000000;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << divi(n, k) << endl;
	return 0;
}