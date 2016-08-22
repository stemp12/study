#include<iostream>
#include<queue>
using namespace std;
int n, cnt = 0, arr[130][130], dp[130][130];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int main()
{
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			for (int k = 0; k < n; k++)
			{
				scanf("%d", &arr[i][k]);
				dp[i][k] = 987654321;
			}
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		dp[0][0] = arr[0][0];

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx == n || ny == n) continue;
				if (dp[ny][nx] > dp[y][x] + arr[ny][nx])
				{
					dp[ny][nx] = dp[y][x] + arr[ny][nx];
					q.push(make_pair(nx, ny));
				}
			}
		}
		printf("Problem %d: %d\n", ++cnt, dp[n - 1][n - 1]);
	}
	return 0;
}