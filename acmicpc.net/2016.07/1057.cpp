#include<iostream>
using namespace std;
int main()
{
	int n, j, h, round = 1;
	cin >> n >> j >> h;

	if (j > h) swap(j, h);
	while (true)
	{
		if (j % 2 == 1 && j + 1 == h) break;

		if (j % 2 == 0) j /= 2;
		else j = (j + 1) / 2;

		if (h % 2 == 0) h /= 2;
		else h = (h + 1) / 2;

		round++;
	}
	cout << round << endl;
	return 0;
}