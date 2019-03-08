#include <iostream>
#include <algorithm>
using namespace std;
long long d[100100][3];
long long point[1000100][2];

int main()
{
	int init_input = 0;
	cin >> init_input;
	//주어진 T케이스 만큼 값을 구한다.
	while (init_input--)
	{
		int line = 0;
		cin >> line;
		//point 배열에 주어진 값 넣기
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 1; k <= line; ++k)
				cin >> point[k][j];
		}
		//d[i][0] 안뜯었을 때의 값 d[i][1] 아래 스티커 뜯었을 때의 값 d[i][2] 위 스티커 뜯었을 때의 값
		d[0][0] = 0;
		d[0][1] = 0;
		d[0][2] = 0;
		for (int j = 1; j <= line; ++j)
		{
			d[j][0] = max(d[j - 1][0], max(d[j - 1][1], d[j - 1][2]));
			d[j][1] = max(d[j - 1][0], d[j - 1][2]) + point[j][0];
			d[j][2] = max(d[j - 1][0], d[j - 1][1]) + point[j][1];
		}
		long long ans = 0;
		for (int l = 1; l <= line; l++) {
			ans = max(max(ans, d[l][0]), max(d[l][1], d[l][2]));
		}
		cout << ans << endl;
	}
	return 0;
}