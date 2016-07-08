#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 500
using namespace std;

vector<vector<int> > v(MAX);
bool chk[MAX];
int bmatch[MAX], n, m;

bool dfs(int pos)
{
	if (chk[pos]) return false;
	chk[pos] = true;

	for (int i = 0; i < v[pos].size(); i++)
	{
		int next = v[pos][i];
		if (bmatch[next] == -1 || dfs(bmatch[next]))
		{
			bmatch[next] = pos;
			return true;
		}
	}
	return false;
}
int bmp()
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
		int sz, like; 
		cin >> sz;
		for (int k = 0; k < sz; k++)
		{
			cin >> like;
			v[i].push_back(like - 1);
		}
	}
	cout << bmp() << endl;
	return 0;
}