#include<iostream>
#include<queue>
using namespace std;
int n, ans = 987654321;
int arr[105][105], brr[105][105];
void copy()
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
			brr[i][k] = arr[i][k];
	}
}
void dfs(int x, int y, int area)
{
	arr[y][x] = area;

	if (y && arr[y - 1][x] == 1) dfs(x, y - 1, area);
	if (y != n - 1 && arr[y + 1][x] == 1)  dfs(x, y + 1, area);
	if (x && arr[y][x - 1] == 1)  dfs(x - 1, y, area);
	if (x != n - 1 && arr[y][x + 1] == 1)  dfs(x + 1, y, area);
}
int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			cin >> arr[i][k];

	queue<pair<int, int>> q;
	for (int i = 0; i<n; i++)
		for (int k = 0; k < n; k++)
		{
			if (arr[i][k] == 1)
			{
				bool chk = false;
				if (i && arr[i - 1][k] == 0) chk = true;
				if (i != n - 1 && arr[i + 1][k] == 0) chk = true;
				if (k && arr[i][k - 1] == 0) chk = true;
				if (k != n - 1 && arr[i][k + 1] == 0) chk = true;

				if (chk) q.push(make_pair(k, i));
			}
		}

	int area = 2;
	for (int i = 0; i<n; i++)
		for (int k = 0; k < n; k++)
			if (arr[i][k] == 1) dfs(k, i, area++);

	while (!q.empty())
	{
		pair<int, int> edge = q.front();
		q.pop();
		area = arr[edge.second][edge.first];
		copy();

		int cnt = 0, idx = 0;
		queue<pair<int, int>> bridge[2];
		bridge[idx].push(edge);

		while (!bridge[idx].empty())
		{
			while (!bridge[idx].empty())
			{
				int x = bridge[idx].front().first;
				int y = bridge[idx].front().second;
				bridge[idx].pop();
				if (brr[y][x] == -1) continue;

				brr[y][x] = -1;
				

				if (y && (brr[y - 1][x] != area && brr[y - 1][x] > 1)) goto end;
				if (y - 1 != n && (brr[y + 1][x] != area && brr[y + 1][x] > 1)) goto end;
				if (x && (brr[y][x - 1] != area && brr[y][x - 1] > 1)) goto end;
				if (x - 1 != n && (brr[y][x + 1] != area && brr[y][x + 1] > 1)) goto end;

				if (y && brr[y - 1][x] == 0 ) bridge[!idx].push(make_pair(x, y - 1));
				if (y - 1 != n && brr[y + 1][x] == 0) bridge[!idx].push(make_pair(x, y + 1));
				if (x && brr[y][x - 1] == 0) bridge[!idx].push(make_pair(x - 1, y));
				if (x - 1 != n && brr[y][x + 1] == 0 ) bridge[!idx].push(make_pair(x + 1, y));
			}
			cnt++;
			idx = !idx;

			if (ans < cnt) break;
		}
	end:
		if (ans > cnt) ans = cnt;
	}
	cout << ans << endl;
	return 0;
}