#include<iostream>
using namespace std;
int arr[1005][5] = { 0, };
bool chk[1002][1002];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < 5; k++)
			cin >> arr[i][k];


	for (int i = 0; i < 5; i++)
		for (int k = 0; k < n; k++)
			for (int j = k + 1; j < n; j++)
			{
				if (arr[k][i] == arr[j][i])
					chk[k][j] = chk[j][k] = true;
			}

	int cnt, MAX = 0, ppl = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		cnt = 0;
		for (int k = 0; k < n; k++)
			if (chk[i][k]) cnt++;

		if (cnt >= MAX)
		{
			MAX = cnt;
			ppl = i;
		}
	}
	cout << ppl + 1 << endl;
	return 0;
}