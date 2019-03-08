//수이어쓰기 2
#include <iostream>

using namespace std;

int n, k;

long long calPow(int num, int digit)
{
	for (int i = 0; i < digit; i++)
	{
		num *= 10;
	}
	return num;
}

void search(int start, int end)
{
	int mid = (start + end) / 2;
	int midleft = mid;
	long long length = 0;
	int digit = 1;
	while (end > 10)
	{
		end %= 10;
		++digit;
	}
	for (int i = 1, j = 1; i <= digit - 1; i++ , j *= 10)
	{
		length += (9 * j) * i;
	}

	for (int i = 0; i <= midleft - calPow(10, digit - 1); i++)
	{
		++length;
	}
}

int main()
{
	
	cin >> n >> k;
	//n의 길이는??
	search(1, 20);
	return 0;
}