#include<iostream>
#include<string.h>
using namespace std;
int h, w;
char board[22][22];
int dfs()
{
	int x, y;
	for (int i = 1; i <= h; i++)
		for (int k = 1; k <= w; k++)
			if (board[i][k] == '.')
			{
				x = k; y = i;
				goto skip;
			}
	return 1;
skip:
	int res = 0;
	board[y][x] = '#';
	if (board[y+1][x] == '.' && board[y + 1][x-1] == '.')
	{
		board[y+1][x] = board[y + 1][x-1] = '#';
		res += dfs();
		board[y+1][x] = board[y + 1][x-1] = '.';
	}
	if (board[y+1][x] == '.' && board[y + 1][x+1] == '.')
	{
		board[y+1][x] = board[y + 1][x+1] = '#';
		res += dfs();
		board[y+1][x] = board[y + 1][x+1] = '.';
	}
	if (board[y][x + 1] == '.' && board[y + 1][x+1] == '.')
	{
		board[y][x + 1] = board[y + 1][x+1] = '#';
		res += dfs();
		board[y][x + 1] = board[y + 1][x+1] = '.';
	}
	if (board[y][x + 1] == '.' && board[y + 1][x] == '.')
	{
		board[y][x + 1] = board[y + 1][x] = '#';
		res += dfs();
		board[y][x + 1] = board[y + 1][x] = '.';
	}
	board[y][x] = '.';
	return res;
}
int main()
{
	int T; cin >> T;
	while (T--)
	{
		memset(board, '#', sizeof(board));
		cin >> h >> w;
		for (int i = 1; i <= h; i++)
			for (int k = 1; k <= w; k++) cin >> board[i][k];
		cout << dfs() << endl;
	}
	return 0;
}