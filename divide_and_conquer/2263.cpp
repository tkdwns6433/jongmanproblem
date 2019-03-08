//트리의 순회
//1 2 3
//1 3 2
// => 2 1 3
#include <iostream>

using namespace std;

int n;
int in[100050];
int post[100050];

void preOrder(int inStart,int inEnd, int postStart, int postEnd )
{
	if (inStart > inEnd || postStart > postEnd)
	{
		return;
	}
	cout << post[postEnd] << " ";
	int rootPos = inStart;
	while (in[rootPos] != post[postEnd])
	{
		++rootPos;
	}
	preOrder(inStart, rootPos - 1, postStart, postStart + rootPos - inStart - 1);
	preOrder(rootPos + 1, inEnd, postStart + rootPos - inStart, postEnd - 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}
	preOrder(0, n - 1, 0, n - 1);

	return 0;
}