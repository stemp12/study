#include<iostream>
using namespace std;
int n, arr[2200][2200], cnt[3];
int chk(int x, int y, int sz)
{
	int start = arr[y][x];
	for (int i = y; i < y + sz; i++)
		for (int k = x; k < x + sz; k++)
			if (arr[i][k] != start) return 2;
	return start;
}
void cal(int x, int y, int sz)
{
	if (sz == 1)
	{
		for (int i = y; i < y + 3; i++)
			for (int k = x; k < x + 3; k++)
				cnt[arr[i][k] + 1]++;
		return;
	}

	int temp = chk(x, y, sz);
	if (temp != 2) cnt[temp + 1]++;
	else
	{
		int nsz = sz / 3;
		if (nsz == 1) cal(x, y, 1);
		else
		{
			cal(x, y, nsz);
			cal(x + nsz, y, nsz);
			cal(x + (nsz * 2), y, nsz);

			cal(x, y + nsz, nsz);
			cal(x + nsz, y + nsz, nsz);
			cal(x + (nsz * 2), y + nsz, nsz);

			cal(x, y + (nsz * 2), nsz);
			cal(x + nsz, y + (nsz * 2), nsz);
			cal(x + (nsz * 2), y + (nsz * 2), nsz);
		}
	}
	return;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++) cin >> arr[i][k];
	cal(0, 0, n);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << endl;
	return 0;
}