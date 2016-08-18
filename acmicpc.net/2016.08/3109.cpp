#include<iostream>
using namespace std;
int r, c;
char board[10005][505];
int dfs(int line, int now)
{
	board[line][now] = 'x';
	if (now == c - 1) return 1;
	if (line - 1 >= 0 && board[line - 1][now + 1] == '.') if (dfs(line - 1, now + 1)) return 1;
	if (board[line][now + 1] == '.') if (dfs(line, now + 1)) return 1;
	if (line + 1 != r && board[line + 1][now + 1] == '.') if (dfs(line + 1, now + 1)) return 1;
	return 0;
}
int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> board[i];
	int res = 0;
	for (int i = 0; i < r; i++) res += dfs(i, 0);
	cout << res << endl;
	return 0;
}