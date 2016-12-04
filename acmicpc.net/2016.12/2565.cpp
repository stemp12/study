#include<iostream>
#include<algorithm>
using namespace std;
struct Data {
	int a, b;
}mdata[105];
bool cmp(Data d1, Data d2)
{
	return d1.a < d2.a;
}
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mdata[i].a >> mdata[i].b;
	sort(mdata, mdata + n, cmp);

	int arr[105] = { mdata[0].b, }, idx = 1;
	for (int i = 1, k; i < n; i++)
	{
		for (k = idx - 1; k >= 0; k--)
			if (arr[k] < mdata[i].b) break;

		if (k == idx - 1) arr[idx++] = mdata[i].b;
		else arr[k + 1] = mdata[i].b;
	}
	cout << n - idx << endl;
	return 0;
}