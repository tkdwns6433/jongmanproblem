#include <stdio.h>

int sum[100005];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int temp;
		scanf("%d", &temp);
		sum[i] = sum[i - 1] + temp;
	}
	
	for (int i = 0; i < m; i++)
	{
		int start, end;
		scanf("%d%d", start, end);
		int result = sum[end] - sum[start - 1];
		printf("%d\n", result);
	}
	return 0;
}