#include<iostream>
#define MOD 1000000000
using namespace std;
int main()
{
	unsigned int arr[103][13] = { 0, }, n;
	for (int i = 0; i < 10; i++) arr[1][i] = 1;

	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		arr[i][0] = arr[i - 1][1];
		for (int k = 1; k < 10; k++)
			arr[i][k] = (arr[i - 1][k - 1] + arr[i - 1][k + 1]) % MOD;
	}

	unsigned int ans = 0;
	for (int i = 1; i < 10; i++) ans = (ans + arr[n][i]) % MOD;
	cout << ans << endl;
	return 0;
}