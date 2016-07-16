#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1005
using namespace std;
int bmatch[MAX];
bool chk[MAX];
vector<vector<int>> v(MAX);
int n, m;
bool dfs(int now)
{
	if (chk[now]) return false;
	chk[now] = true;

	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		if (bmatch[next] == -1 || dfs(bmatch[next]))
		{
			bmatch[next] = now;
			return true;
		}
	}
	return false;
}
int bpm()
{
	fill(bmatch, bmatch + MAX, -1);
	int match = 0;
	for (int i = 0; i < n; i++)
	{
		fill(chk, chk + MAX, false);
		if (dfs(i)) match++;
	}
	return match;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int sz, point;
		cin >> sz;
		for (int k = 0; k < sz; k++)
		{
			cin >> point;
			v[i].push_back(point - 1);
		}
	}
	cout << bpm() << endl;
	return 0;
}