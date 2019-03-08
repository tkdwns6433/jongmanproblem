/*
	응용적으로 랜덤으로 3개의 원소를 선택한 후 가장 중간을 이용할 수 있음
	시간복잡도는 평균적으로 nlogn 시간복잡도를 가진다.
	파티션하는 알고리즘을 생각하는게 tricky한 부분 개념적을 O(n)의 복잡도를 가지고 있으며
	어떻게하든 상관은없지만.. 알고리즘책에서 사용한 부분을 이용
*/

#include <iostream>

using namespace std;

void quicksort(int A[], int p, int r);
int partition(int A[], int p, int r);

void quicksort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}
//ex ) 해야하는 일 맨 마지막 원소를 기준으로 반 갈하는 것 전해줘야 하는 값 반갈의 값이 어디에 위치하는 지!
int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			++i;
			int tempEle = A[i];
			A[i] = A[j];
			A[j] = tempEle;
		}
	}
	int tempEle = A[r];
	A[r] = A[i + 1];
	A[i + 1] = tempEle;
	return i + 1;
}

int main()
{
	int test_quick[8];
	test_quick[0] = 2;
	test_quick[1] = 8;
	test_quick[2] = 7;
	test_quick[3] = 1;
	test_quick[4] = 3;
	test_quick[5] = 5;
	test_quick[6] = 6;
	test_quick[7] = 4;
	quicksort(test_quick, 0, 7);
	for (int i = 0; i < 8; i++)
	{
		cout << test_quick[i] << endl;
	}
	return 0;
}