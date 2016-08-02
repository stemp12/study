#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<pair<int, int>>> v(10003);
int ans;
int dfs(int now)
{
	int val[2] = { 0, };
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i].first;
		int temp = dfs(next) + v[now][i].second;

		if (temp > val[0]) { val[1] = val[0]; val[0] = temp; }
		else if (temp > val[1]) { val[1] = temp; }
	}
	ans = max(ans, val[0] + val[1]);
	return val[0];
}
int main()
{
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int f, t, c;
		cin >> f >> t >> c;
		v[f].push_back(make_pair(t, c));
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}