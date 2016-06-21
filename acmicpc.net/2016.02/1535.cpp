#include<iostream>
using namespace std;
int n, arr[2][22], MAX;
void dfs(int happy, int hp, int idx)
{
	if (hp <= 0 || idx > n) return;
	if (MAX < happy) MAX = happy;

	dfs(arr[1][idx] + happy, hp - arr[0][idx], idx + 1);
	dfs(happy, hp, idx + 1);
}
int main()
{
	cin >> n;
	for (int i = 0; i < 2; i++)
		for (int k = 0; k < n; k++)
			cin >> arr[i][k];
	dfs(0, 100, 0);
	cout << MAX << endl;
	return 0;
}