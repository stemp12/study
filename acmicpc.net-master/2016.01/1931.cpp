#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100011
struct DATA{
	int start;
	int end;
	int use;
}data[MAX];
bool cmp(DATA d1, DATA d2)
{
	return d1.end<d2.end;
}
bool cmp_use(DATA d1, DATA d2)
{
	return d1.start < d2.start;
}
int main()
{
	int n, a, b;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> a >> b;
		data[i].start = a;
		data[i].end = b;
		data[i].use = b - a;
	}
	stable_sort(data, data + n, cmp_use);
	stable_sort(data, data + n, cmp);

	int cnt = 0, temp = 0;
	for (int i = 0; i<n; i++)
	{
		if (temp <= data[i].start)
		{
			cnt++;
			temp = data[i].end;

		}
	}
	cout << cnt << endl;
	return 0;
}