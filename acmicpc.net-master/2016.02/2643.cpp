#include<iostream>
#include<algorithm>
using namespace std;
struct POS {
	int x, y;
}pos[105];
bool cmpx(POS p1, POS p2)
{
	return p1.x > p2.x;
}
bool cmpy(POS p1, POS p2)
{
	return p1.y > p2.y;
}
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pos[i].x >> pos[i].y;
		if (pos[i].x < pos[i].y) swap(pos[i].x, pos[i].y);
	}
	stable_sort(pos, pos + n, cmpy);
	stable_sort(pos, pos + n, cmpx);

	int dp[105] = { 0, }, ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < i; k++)
		{
			if (pos[i].x <= pos[k].x && pos[i].y <= pos[k].y)
				dp[i] = max(dp[i], dp[k]);
		}
		dp[i]++;
		if (ans < dp[i]) ans = dp[i];
	}
	cout << ans << endl;
	return 0;
}