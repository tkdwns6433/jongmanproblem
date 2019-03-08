#include <stdio.h>

using namespace std;

int p[1000500];
int n, m;

int find(int x)
{
	if (x == p[x])
	{
		return x;
	}
	return p[x] = find(p[x]);
}
//y의 parent를 x로 설정
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	p[y] = x;
}

int main()
{
	scanf("%d %d",&n, &m);

	for (int i = 0; i <= n; i++)
	{
		p[i] = i;
	}
	while (m--)
	{
		int arith, x, y;
		scanf("%d %d %d", &arith, &x, &y);
		switch (arith)
		{
		case 0 :
			Union(x, y);
			break;

		case 1 :
			if (find(x) == find(y))
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
			break;

		default:
			break;
		}
	}
	return 0;
}