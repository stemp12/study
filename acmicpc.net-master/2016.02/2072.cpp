#include<iostream>
using namespace std;
char board[22][22];
int sear(int y, int x, int yp, int xp, char word)
{
	if (board[y + yp][x + xp] != word) return 0;
	else return sear(y + yp, x + xp, yp, xp, word) + 1;
}
int main()
{
	int n, x, y, who = 0, finish = 0, len;
	char word;
	cin >> n;

	for (int g = 1; g <= n; g++)
	{
		cin >> y >> x;
		if (finish) continue;

		if (who) word = 'W';
		else word = 'B';

		board[y][x] = word;

		len = sear(y, x, -1, 0, word) + sear(y, x, 1, 0, word) + 1;
		if (len == 5) finish = g;

		len = sear(y, x, 0, -1, word) + sear(y, x, 0, 1, word) + 1;
		if (len == 5) finish = g;

		len = sear(y, x, -1, -1, word) + sear(y, x, 1, 1, word) + 1;
		if (len == 5) finish = g;

		len = sear(y, x, -1, 1, word) + sear(y, x, 1, -1, word) + 1;
		if (len == 5) finish = g;

		who ? who = 0 : who = 1;
	}
	if (finish) cout << finish << endl;
	else cout << -1 << endl;
	return 0;
}