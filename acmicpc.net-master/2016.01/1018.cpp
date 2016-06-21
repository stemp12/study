#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string input[55];
string wperfect[8], bperfect[8];
void make_perfect()
{
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			wperfect[i] = "WBWBWBWB";
			bperfect[i] = "BWBWBWBW";
		}
		else
		{
			bperfect[i] = "WBWBWBWB";
			wperfect[i] = "BWBWBWBW";
		}
	}
}
int check(int n, int m)
{
	int cnt[2] = { 0, };
	for (int i = n; i < n + 8; i++)
		for (int k = m; k < m + 8; k++)
		{
			if (bperfect[i - n][k - m] != input[i][k])
				cnt[0]++;
			if (wperfect[i - n][k - m] != input[i][k])
				cnt[1]++;
		}
	return cnt[0] < cnt[1] ? cnt[0] : cnt[1];
}
int main()
{
	make_perfect();
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input[i];

	int MIN = 987654321;
	for (int i = 0; i <= n - 8; i++)
		for (int k = 0; k <= m - 8; k++)
			MIN = min(MIN, check(i, k));
	cout << MIN << endl;
	return 0;
}
