/*
	1. 전역변수 배열을 여러번 초기화해야될 상황이 생길 때 주소를 사용하므로 main 문에서 zero-initialize 를 선언한 후 사용하자
*/

#include <iostream>

using namespace std;

int picnic(bool areFriends[10][10], bool taken[10], int num_stu)
{
	int free_stu = -1;
	for (int i = 0; i < num_stu; ++i)
	{
		if (taken[i] == false) {
			free_stu = i;
			break;
		}
	}
	if (free_stu == -1)
		return 1;
	int ret = 0;
	for (int cur_stu = free_stu + 1; cur_stu < num_stu; ++cur_stu)
	{
		if (areFriends[cur_stu][free_stu] == true && taken[cur_stu] == false)
		{
			taken[cur_stu] = taken[free_stu] = true;
			ret += picnic(areFriends, taken, num_stu);
			taken[cur_stu] = taken[free_stu] = false;
		}
	}
	return ret;
}


int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		bool areFriends[10][10] = {};
		bool taken[10] = {};
		int student_num, stu_pair;
		cin >> student_num >> stu_pair;
		for (int i = 0; i < stu_pair; ++i)
		{
			int first_stu, second_stu;
			cin >> first_stu >> second_stu;
			areFriends[first_stu][second_stu] = true;
			areFriends[second_stu][first_stu] = true;
		}
		cout << picnic(areFriends, taken, student_num) << endl;
	}
	return 0;
}