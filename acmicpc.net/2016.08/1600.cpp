#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int arr[205][205], chk[205][205][33], j, h, w;
int dx[12] = { 0, 0, 1, -1, -2, -2, 2, 2, -1, -1, 1, 1 };
int dy[12] = { 1, -1, 0, 0, 1, -1, 1, -1, -2, 2, -2, 2 };
struct Data {
	int x, y;
	int jump;
};
int main()
{
	memset(chk, 0, sizeof(chk));
	cin >> j >> w >> h;
	for (int i = 0; i < h; i++)
		for (int k = 0; k < w; k++) cin >> arr[i][k];

	queue<Data> q;
	q.push(Data{ 0, 0, 0 });
	int cnt = 0;
	while (!q.empty())
	{
		int SZ = q.size();
		while (SZ--)
		{
			int x = q.front().x;
			int y = q.front().y;
			int idx = q.front().jump;
			q.pop();
			if (chk[y][x][idx]) continue;
			else chk[y][x][idx] = 1;

			if (x == w - 1 && y == h - 1)
			{
				cout << cnt << endl;
				return 0;
			}

			for (int i = 0; i < 12; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= w || ny >= h || arr[ny][nx]) continue;
				if (i < 4)
				{
					if (chk[ny][nx][idx] == 0)
						q.push(Data{ nx, ny, idx });
				}
				else
				{
					if (j>idx)
						if (chk[ny][nx][idx + 1] == 0)
							q.push(Data{ nx, ny, idx + 1 });
				}
			}
		}
		cnt++;
	}
	cout << -1 << endl;
	return 0;
}