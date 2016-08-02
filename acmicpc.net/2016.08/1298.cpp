#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> v(105);
int bmatch[5005], chk[5005];
int n, m, p, c;
int dfs(int pos)
{
	if (chk[pos]) return false;
	chk[pos] = 1;

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
int bpm()
{
	fill(bmatch, bmatch + 5005, -1);
	int match = 0;
	for (int i = 0; i < n; i++)
	{
		fill(chk, chk + 5005, 0);
		if (dfs(i)) match++;
	}
	return match;
}
int main()
{

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> p >> c;
		v[p - 1].push_back(c - 1);
	}
	cout << bpm() << endl;
	return 0;
}