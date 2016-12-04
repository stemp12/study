#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Data {
	int f, t, w;
}input;
int chk[1005], n, m;
vector<Data> mdata;
bool cmp0(Data d1, Data d2)
{
	return d1.w < d2.w;
}
bool cmp1(Data d1, Data d2)
{
	return d1.w > d2.w;
}
int mfind(int pos)
{
	if (pos == chk[pos]) return chk[pos];
	return chk[pos] = mfind(chk[pos]);
}
int cal(int flag)
{
	if (flag == 0) sort(mdata.begin(), mdata.end(), cmp0);
	else		sort(mdata.begin(), mdata.end(), cmp1);

	for (int i = 0; i < 1005; i++) chk[i] = i;

	int ans = 0;
	for (int i = 0; i <= m; i++)
	{
		int nf = mfind(mdata[i].f);
		int nt = mfind(mdata[i].t);

		if (nf == nt) continue;
		chk[nf] = nt;
		ans += mdata[i].w;
	}
	return ans;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= m; i++)
	{
		scanf("%d %d %d", &input.f, &input.t, &input.w);
		input.w = !input.w;
		mdata.push_back(input);
	}
	int best = cal(0);
	int worst = cal(1);
	printf("%d\n", worst*worst - best*best);
	return 0;
}