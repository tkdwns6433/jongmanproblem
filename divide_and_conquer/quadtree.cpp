#include <string>
#include <iostream>

using namespace std;

string reverse(string::iterator & iter)
{
	if (*iter == 'b' || *iter == 'w')
	{
		return string(1, *iter);
	}	
	string leftupper = reverse(++iter);
	string rightupper = reverse(++iter);
	string leftlower = reverse(++iter);
	string rightlower = reverse(++iter);
	
	return string("x") + leftlower + rightlower + leftupper + rightupper;
}
int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		string quad;
		cin >> quad;
		string::iterator iter = quad.begin();
		cout << reverse(iter) << endl;
	}
	return 0;
}