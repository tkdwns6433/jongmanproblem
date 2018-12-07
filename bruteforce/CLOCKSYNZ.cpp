#include <iostream>

using namespace std;

int clock[15];

bool checkClock()
{
	for (int i = 0; i < 15; i++)
	{
		return clock[i] != 12;
	}
	return true;
}

void step_clock() {
	for (int i = 0; i < 15; i++)
	{
		clock[i] = (clock[i] + 3) % 12;
	}
}

void back_clock() {
	for (int i = 0; i < 15; i++)
	{
		if (clock[i] > 0)
		{
			clock[i] -= 3;
		}
		else {
			clock[i] = 9;
		}
	}
}

int switch_clock()
{
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < length; j++)
		{

		}
	}
}

int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		for (int i = 0; i < 15; i++)
		{
			cin >> clock[i];
		}
		cout << switch_clock() << endl;
	}
	return 0;
}