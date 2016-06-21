#include<iostream>
using namespace std;
int main()
{
	int n, m, pos, dp[33][3] = { 0, };
	cin >> n >> m;
	while (n--)
	{
		cin >> pos;
		for (int i = 0; i <= m; i++)
		{
			dp[i][pos]++;
			if (i && dp[i - 1][1] > dp[i][2]) dp[i][2] = dp[i - 1][1];
			if (i && dp[i - 1][2] > dp[i][1]) dp[i][1] = dp[i - 1][2];
		}
	}
	cout << (dp[m][1] < dp[m][2] ? dp[m][2] : dp[m][1]);
	return 0;
}