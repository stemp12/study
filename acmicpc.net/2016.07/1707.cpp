#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int T, V, E, to, from;
int check[20002];
vector<vector<int>> v;
bool dfs(int pos, int flag)
{
	check[pos] = flag;

	for (int i = 0; i < v[pos].size(); i++)
	{
		int next = v[pos][i];
		if (check[next] == flag) return false;
		if (check[next] == -1 && !dfs(next, !flag)) return false;
	}
	return true;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &V, &E);
		fill(check, check + 20002, -1);
		v = vector<vector<int>>(20002);

		for (int i = 0; i < E; i++)
		{
			scanf("%d %d", &to, &from);
			v[to].push_back(from);
			v[from].push_back(to);
		}

		int graph = 1;
		for (int i = 1; i <= V; i++)
			if (check[i] == -1 && !dfs(i, true))
			{
				graph = 0;
				break;
			}
		graph ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}