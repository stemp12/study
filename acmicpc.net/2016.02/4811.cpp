#include<iostream>
using namespace std;
typedef long long int INT;
int main()
{
	INT dp[33][33] = { 1, };
	for (int i = 0; i < 31; i++)
		for (int k = 0; k <= i; k++)
		{
			dp[i][k + 1] += dp[i][k];
			dp[i + 1][k] += dp[i][k];
		}
	int n;
	while (cin >> n && n != 0)
		cout << dp[n][n] << endl;
	return 0;
}