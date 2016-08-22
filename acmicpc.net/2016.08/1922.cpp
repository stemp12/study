#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Data {
	int from, to;
	int val;
}mdata[100005];
int n, m, chk[1005];
bool cmp(Data d1, Data d2)
{
	return d1.val < d2.val;
}
int mfind(int now)
{
	if (now == chk[now]) return now;
	return chk[now] = mfind(chk[now]);
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) chk[i] = i;
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &mdata[i].from, &mdata[i].to, &mdata[i].val);

	int ans = 0;
	sort(mdata, mdata + m, cmp);
	for (int i = 0; i < m; i++)
	{
		int e1 = mfind(mdata[i].from);
		int e2 = mfind(mdata[i].to);
		if (e1 == e2) continue;
		chk[e1] = e2;
		ans += mdata[i].val;
	}
	printf("%d\n", ans);
	return 0;
}