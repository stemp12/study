#include<iostream>
#include<queue>
#define MAX 987654321
using namespace std;
struct Data {
	int y, x;
	int dir;
};
int arr[105][105], dp[105][105][4], h, w;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int chk(int a, int b)
{
	if (a == b) return 0;
	else if ((a == 0 && b == 1) || (a == 1 && b == 0)) return 2;
	else if ((a == 2 && b == 3) || (a == 3 && b == 2)) return 2;
	else return 1;
}
int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int k = 0; k < w; k++)
		{
			cin >> arr[i][k];
			dp[i][k][0] = dp[i][k][1] = dp[i][k][2] = dp[i][k][3] = MAX;
		}

	Data start, end;
	cin >> start.y >> start.x >> start.dir;
	cin >> end.y >> end.x >> end.dir;
	start.y--, start.x--, end.y--, end.x--, start.dir--, end.dir--;

	queue<Data> q;
	q.push(start);
	dp[start.y][start.x][start.dir] = 0;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();
		if (x == end.x && y == end.y)
		{
			cout << dp[y][x][dir] + chk(dir, end.dir) << endl;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int temp = chk(dir, i);
			int nx = x, ny = y;
			for (int k = 1; k <= 3; k++)
			{
				nx += dx[i]; ny += dy[i];
				if (ny < 0 || nx < 0 || ny == h || nx == w || arr[ny][nx] == 1) break;
				if (dp[ny][nx][i] > dp[y][x][dir] + temp + 1)
				{
					q.push(Data{ ny, nx, i });
					dp[ny][nx][i] = dp[y][x][dir] + temp + 1;
				}
			}
		}
	}
	return 0;
}