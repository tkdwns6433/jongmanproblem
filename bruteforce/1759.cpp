#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string & password);
//index에서 처리를 하는 함수
void go(int index,string & word, string password, int endIndex)
{
	if (password.length() == endIndex)
	{
		if(check(password))
		cout << password << endl;
		return;
	}
	if (word.size() <= index)
	{
		return;
	}
	go(index + 1, word, password + word[index], endIndex);
	go(index + 1, word, password, endIndex);
	return;
}

bool check(string  & password) {
	int mo = 0, ja = 0;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
		{
			mo++;
		}
		else
		{
			ja++;
		}
	}
	if (mo >= 1 && ja >= 2)
	{
		return true;
	}
	else
		return false;
}


int main()
{
	int c, n;
	cin >> c >> n;
	string word;
	for (int i = 0; i < n; i++)
	{
		char input;
		cin >> input;
		word.push_back(input);
	}
	sort(word.begin(), word.end());
	string empty;
	go(0, word, empty, c);
	return 0;
}