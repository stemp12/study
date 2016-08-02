#include<stdio.h>
#define MOD 10007
int main()
{
	int arr[1002][10] = { 0, }, n, i, k;
	scanf("%d", &n);
	for (i = 0; i < 10; i++) arr[1][i] = i + 1;
	for (i = 2; i <= n; i++)
	{
		arr[i][0] = 1;
		for (k = 1; k < 10; k++)
			arr[i][k] = (arr[i - 1][k] + arr[i][k - 1]) % MOD;
	}
	printf("%d", arr[n][9]);
	return 0;
}