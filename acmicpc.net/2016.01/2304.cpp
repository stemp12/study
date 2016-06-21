#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int>p2)
{
	return p1.first < p2.first;
}
int main()
{
	int n; cin >> n;
	pair<int, int> pr[1002];
	for (int i = 0; i < n; i++)
		cin >> pr[i].first >> pr[i].second;
	sort(pr, pr + n, cmp);

	int sum = 0, now = 0, dir = 0, mid = 0;
	while (true)
	{
		if (dir == 0)
		{
			bool chk = false;
			for (int i = now + 1; i < n; i++)
			{
				if (pr[now].second <= pr[i].second)
				{
					sum += (pr[i].first - pr[now].first)*pr[now].second;

					now = i;
					chk = true;
					break;
				}
			}
			if (!chk)
			{
				sum += pr[now].second;
				dir = 1;
				mid = now;
				now = n - 1;
			}
		}
		else
		{

			bool chk = false;
			for (int i = now - 1; i >= mid; i--)
			{
				if (pr[now].second <= pr[i].second)
				{
					sum += -(pr[i].first - pr[now].first)*pr[now].second;
					now = i;
					chk = true;
					break;
				}
			}
			if (!chk)
			{
				cout << sum << endl;
				return 0;
			}
		}
	}
}
