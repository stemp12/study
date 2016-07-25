#include<iostream>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1005] = { 0, }, dp[1005] = { 0, }, MAX = 0;
vector<vector<int>> out;
void init()
{
	fill(arr, arr + 1005, 0);
	fill(dp, dp + 1005, 0);
	out = vector<vector<int>>(1005);
}
int dfs(int now)
{
	if (dp[now]) return dp[now];

	int val = arr[now];
	dp[now] = val;
	for (int i = 0; i < out[now].size(); i++)
		dp[now] = max(dp[now], dfs(out[now][i]) + val);
	return dp[now];
}
int main()
{
	int n, m, w, f, t, T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		while (m--)
		{
			scanf("%d %d", &f, &t);
			out[t].push_back(f);
		}
		scanf("%d", &w);
		printf("%d\n", dfs(w));
	}
	return 0;
}