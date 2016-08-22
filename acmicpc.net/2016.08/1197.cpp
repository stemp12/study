#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct Data {
	int from, to, val;
}temp;
int e, v, chk[10005], res;
vector<Data> edge;
bool cmp(Data d1, Data d2)
{
	return d1.val < d2.val;
}
int mfind(int num)
{
	if (num == chk[num]) return num;
	return chk[num] = mfind(chk[num]);
}
int main()
{
	scanf("%d %d", &e, &v);
	for (int i = 1; i <= e; i++) chk[i] = i;
	for (int i = 0; i < v; i++)
	{
		scanf("%d %d %d", &temp.from, &temp.to, &temp.val);
		edge.push_back(temp);
	}
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0; i < v; i++)
	{
		int nv = mfind(edge[i].from);
		int nw = mfind(edge[i].to);
		if (nv == nw) continue;
		chk[nv] = nw;
		res += edge[i].val;
	}
	printf("%d\n", res);
	return 0;
}