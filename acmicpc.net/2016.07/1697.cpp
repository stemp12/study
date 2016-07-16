#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
bool chk[222222] = { false, };
int main()
{
	int subin, sibling, idx = 0, cnt = 0, now;
	queue<int> q[2];
	cin >> subin >> sibling;
	if (subin == sibling) goto end;

	q[idx].push(subin);
	while (!q[idx].empty())
	{
		cnt++;
		while (!q[idx].empty())
		{
			now = q[idx].front();
			q[idx].pop();

			if (now + 1 == sibling || now - 1 == sibling || now * 2 == sibling)
				goto end;

			if (now<sibling && !chk[now * 2])
			{
				q[!idx].push(now * 2);
				chk[now * 2] = true;
			}
			if (now<sibling && !chk[now + 1])
			{
				q[!idx].push(now + 1);
				chk[now + 1] = true;
			}
			if (now - 1 >= 0 && !chk[now - 1])
			{
				q[!idx].push(now - 1);
				chk[now - 1] = true;
			}
		}
		idx = !idx;
	}
end:
	cout << cnt << endl;
	return 0;
}