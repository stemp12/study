//	https://www.acmicpc.net/problem/2505
// 1620KB, 4MS

#include<iostream>
using namespace std;
#define MAX 11111
int arr[MAX], c_arr[MAX], n;
int a=1, b=1, c=1, d=1;
int find_pos(int num)
{
	for (int i = 1; i <= n; i++)
		if (c_arr[i] == num) return i;
	return -1;
}
void reset(int start, int end)
{
	if (start > end) swap(start, end);
	while (start < end)
		swap(c_arr[start++], c_arr[end--]);
}
bool sear(int s, int e, int dir)
{
	for (int i = 1; i <= n; i++)
		c_arr[i] = arr[i];

	int cnt = 0;
	for (int i = s; dir == 1 ? i <= e : i >= e; i += dir)
	{
		if (c_arr[i] != i)
		{
			int start = i;
			int end = find_pos(i);
			reset(start, end);
			cnt++;
			if (cnt == 1)
			{
				a = start;
				b = end;
			}
			else if (cnt == 2)
			{
				c = start;
				d = end;
			}
		}
		if (cnt == 3) break;
	}
	if (cnt == 2) return true;
	else return false;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	if (!sear(1, n, 1))
		sear(n, 1, -1);

	if (a > b) swap(a, b);
	if (c > d) swap(c, d);

	cout << a << ' ' << b << endl << c << ' ' << d << endl;
	return 0;
}