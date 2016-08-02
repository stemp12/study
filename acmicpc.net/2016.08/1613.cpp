#include<iostream>
#include<algorithm>
using namespace std;
int arr[404][404], n, m, a, b, q;
void init()
{
	for (int i = 0; i < 404; i++)
		for (int k = 0; k < 404; k++)
			arr[i][k] = 100000;
}
void floyd()
{
	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= n; k++)
			for (int j = 1; j <= n; j++)
				arr[k][j] = min(arr[k][j], arr[k][i] + arr[i][j]);
}
int main()
{
	init();
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	floyd();
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &a, &b);
		if (arr[a][b] != 100000) printf("-1\n");
		else if (arr[b][a] != 100000) printf("1\n");
		else printf("0\n");
	}
	return 0;
}