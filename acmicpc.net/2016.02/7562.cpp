#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n; cin >> n;
	while (n--)
	{
		int sz, now[2], des[2];
		cin >> sz >> now[0] >> now[1] >> des[0] >> des[1];
		bool chk[305][305] = { 0, };
		int idx = 0, cnt = 0;
		queue<pair<int, int>> q[2];
		q[idx].push(make_pair(now[0], now[1]));
		while (1)
		{
			while (!q[idx].empty())
			{
				int x = q[idx].front().first;
				int y = q[idx].front().second;
				q[idx].pop();

				if (chk[y][x]) continue;
				if (des[0] == x && des[1] == y) goto end;

				chk[y][x] = true;

				if (x > 1 && y)               q[!idx].push(make_pair(x - 2, y - 1));
				if (x && y > 1)               q[!idx].push(make_pair(x - 1, y - 2));
				if (x < sz - 1 && y > 1)      q[!idx].push(make_pair(x + 1, y - 2));
				if (x < sz - 2 && y)          q[!idx].push(make_pair(x + 2, y - 1));
				if (x > 1 && y < sz - 1)      q[!idx].push(make_pair(x - 2, y + 1));
				if (x && y < sz - 2)		  q[!idx].push(make_pair(x - 1, y + 2));
				if (x < sz - 1 && y < sz - 2) q[!idx].push(make_pair(x + 1, y + 2));
				if (x < sz - 2 && y < sz - 1) q[!idx].push(make_pair(x + 2, y + 1));
			}
			idx ? idx = 0 : idx = 1;
			cnt++;
		}
	end:
		cout << cnt << endl;
	}
	return 0;
}