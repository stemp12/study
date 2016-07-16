#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool prime[2002], chk[55];
int arr[55], bmatch[55], n;
vector<vector<int>> num(55);
vector<int> ans;
void make_prime()
{
	for (int i = 2; i < 2002; i++)
		prime[i] = true;
	for (int i = 2; i < 2002; i++)
	{
		for (int k = 2; i*k < 2002; k++)
			prime[i*k] = false;
	}
}
bool dfs(int now)
{
	if (chk[now]) return false;
	chk[now] = true;

	for (int i = 0; i < num[now].size(); i++)
	{
		int next = num[now][i];
		if (bmatch[next] == -1 || dfs(bmatch[next]))
		{
			bmatch[next] = now;
			return true;
		}
	}
	return false;
}
int bpm(int pr)
{
	fill(bmatch, bmatch + 55, -1);
	bmatch[pr] = 0;
	bmatch[0] = pr;

	int match = 0;
	for (int i = 0; i < n; i++)
	{
		fill(chk, chk + 55, false);
		chk[pr] = chk[0] = true;

		if (dfs(i)) match++;
	}

	return match;
}
int main()
{
	make_prime(); cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (i == k) continue;
			if (prime[arr[i] + arr[k]])
				num[i].push_back(k);
		}
	}


	for (int i = 0; i < num[0].size(); i++)
		if (bpm(num[0][i]) == n - 2)
			ans.push_back(arr[num[0][i]]);

	if (ans.empty()) cout << -1 << endl;
	else
	{
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << endl;
	}

	return 0;
}