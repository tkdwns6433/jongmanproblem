/*
	���������� �������� 3���� ���Ҹ� ������ �� ���� �߰��� �̿��� �� ����
	�ð����⵵�� ��������� nlogn �ð����⵵�� ������.
	��Ƽ���ϴ� �˰����� �����ϴ°� tricky�� �κ� �������� O(n)�� ���⵵�� ������ ������
	����ϵ� �����������.. �˰���å���� ����� �κ��� �̿�
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
//ex ) �ؾ��ϴ� �� �� ������ ���Ҹ� �������� �� ���ϴ� �� ������� �ϴ� �� �ݰ��� ���� ��� ��ġ�ϴ� ��!
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