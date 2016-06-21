#include<iostream>
#include<algorithm>
#define MAX 987654321
using namespace std;
int main()
{
	int coin[105] = { 0, }, cnt[10005] = { 0, };
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> coin[i];
	for (int i = 1; i < 10005; i++) cnt[i] = MAX;

	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			cnt[j] = min(cnt[j], cnt[j - coin[i]] + 1);

	if (MAX == cnt[k]) cout << -1 << endl;
	else cout << cnt[k] << endl;
	return 0;
}