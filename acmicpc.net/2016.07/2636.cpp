#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int arr[105][105], temp[105][105], w, h;
queue<pair<int, int>> q;
bool chk()
{
	for (int i = 0; i < h; i++)
		for (int k = 0; k < w; k++)
			if (arr[i][k]) return true;
	return false;
}
void sear()
{
	queue<pair<int, int>> zero;
	zero.push(make_pair(0, 0));

	while (!zero.empty())
	{
		int x = zero.front().first;
		int y = zero.front().second;
		zero.pop();

		if (temp[y][x] == -1) continue;
		temp[y][x] = -1;

		if (y && temp[y - 1][x] == 0) zero.push(make_pair(x, y - 1));
		if (x && temp[y][x - 1] == 0) zero.push(make_pair(x - 1, y));
		if (y != h - 1 && temp[y + 1][x] == 0) zero.push(make_pair(x, y + 1));
		if (x != w - 1 && temp[y][x + 1] == 0) zero.push(make_pair(x + 1, y));

		if (y && temp[y - 1][x] == 1)
		{
			temp[y - 1][x] = -1;
			q.push(make_pair(x, y - 1));
		}
		if (x && temp[y][x - 1] == 1)
		{
			temp[y][x - 1] = -1;
			q.push(make_pair(x - 1, y));
		}
		if (y != h - 1 && temp[y + 1][x] == 1)
		{
			temp[y + 1][x] = -1;
			q.push(make_pair(x, y + 1));
		}
		if (x != w - 1 && temp[y][x + 1] == 1)
		{
			temp[y][x + 1] = -1;
			q.push(make_pair(x + 1, y));
		}
	}
}
void del()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		arr[y][x] = 0;
	}
}
int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int k = 0; k < w; k++)
			cin >> arr[i][k];

	int cnt = 0, before = 0;
	while (chk())
	{
		memcpy(temp, arr, sizeof(arr));

		sear();
		before = q.size();

		del();
		cnt++;
	}
	cout << cnt << endl << before << endl;

	return 0;
}