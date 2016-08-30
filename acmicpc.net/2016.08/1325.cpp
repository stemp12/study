#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#define MAX 10005
using namespace std;
int n, m, f, t, save[MAX], big;
vector<vector<int>> v(MAX);
bool chk[MAX];
int dfs(int pos)
{
	chk[pos] = 1;
	int sz = v[pos].size();
	int temp = 1;
	for (int i = 0; i < sz; i++)
		if (!chk[v[pos][i]])
			temp += dfs(v[pos][i]);
	return temp;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &f, &t);
		v[t].push_back(f);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(chk, 0, sizeof(chk));
		save[i] = dfs(i);
		if (save[i] > big) big = save[i];
	}
	for (int i = 1; i <= n; i++)
		if (big == save[i]) printf("%d ", i);
	return 0;
}