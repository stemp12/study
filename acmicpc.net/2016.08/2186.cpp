#include<iostream>
#include<string.h>
using namespace std;
char board[105][105], str[105];
int n, m, j, ans, len, dp[105][105][88];
int dfs(int x, int y, int pos)
{
	if (dp[y][x][pos] != -1) return dp[y][x][pos];
	if (pos == len) return 1;

	int cnt = 0;
	for (int i = 1; i <= j; i++)
	{
		if (x + i < m && board[y][x + i] == str[pos]) cnt += dfs(x + i, y, pos + 1);
		if (y + i < n && board[y + i][x] == str[pos]) cnt += dfs(x, y + i, pos + 1);
		if (x - i >= 0 && board[y][x - i] == str[pos]) cnt += dfs(x - i, y, pos + 1);
		if (y - i >= 0 && board[y - i][x] == str[pos]) cnt += dfs(x, y - i, pos + 1);
	}
	return dp[y][x][pos] = cnt;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> j;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < m; k++) cin >> board[i][k];

	cin >> str;
	len = strlen(str);
	for (int i = 0; i < n; i++)
		for (int k = 0; k < m; k++)
			if (board[i][k] == str[0]) ans += dfs(k, i, 1);
	cout << ans << endl;
	return 0;
}