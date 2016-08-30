#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 1111111111
using namespace std;
int main()
{
	int n, m, f, t, w, res[100005] = { 0, };
	scanf("%d %d", &n, &m);

	vector<vector<pair<int, int>>> v(n + 1);
	for (int i = 0; i <= n; i++) res[i] = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &f, &t, &w);
		v[f].push_back(make_pair(t, w));
		v[t].push_back(make_pair(f, w));
	}
	scanf("%d %d", &f, &t);
	queue<pair<int, int>> q;
	q.push(make_pair(f, MAX));
	res[f] = MAX;

	while (!q.empty())
	{
		int cur = q.front().first;
		w = q.front().second;
		q.pop();
		vector<pair<int, int>> edge = v[cur];
		int sz = edge.size();
		for (int i = 0; i < sz; i++)
		{
			int next = edge[i].first;
			if (w < edge[i].second) edge[i].second = w;

			if (res[next] < edge[i].second)
			{
				res[next] = edge[i].second;
				q.push(make_pair(next, edge[i].second));
			}

		}
	}
	printf("%d", res[t]);
	return 0;
}