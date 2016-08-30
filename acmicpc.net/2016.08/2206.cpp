#include<iostream>
#include<queue>
#define MAX 987654321
using namespace std;
struct POS {
	int x, y;
	int wall;
};
int dx[4] = { 0, 0,  -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int h, w, dp[1001][1001][2];
char arr[1001][1001];
int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int k = 0; k < w; k++)
		{
			cin >> arr[i][k];
			dp[i][k][0] = MAX;
			dp[i][k][1] = MAX;
		}

	queue<POS> q;
	q.push(POS{ 0, 0, 0 });
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;
	while (!q.empty())
	{
		int SZ = q.size();
		while (SZ--)
		{
			int x = q.front().x;
			int y = q.front().y;
			int wall = q.front().wall;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx == w || ny == h) continue;

				if (dp[ny][nx][wall] > dp[y][x][wall] + 1)
				{
					if (arr[ny][nx] == '1' && wall == 0)
					{
						dp[ny][nx][1] = dp[y][x][0] + 1;
						q.push(POS{ nx, ny, 1 });
					}
					else if (arr[ny][nx] == '0')
					{
						q.push(POS{ nx, ny, wall });
						dp[ny][nx][wall] = dp[y][x][wall] + 1;
					}
				}
			}

		}
	}
	int ans = dp[h - 1][w - 1][0];
	if (ans > dp[h - 1][w - 1][1]) ans = dp[h - 1][w - 1][1];
	if (ans == MAX) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}