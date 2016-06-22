#include<iostream>
#include<algorithm>
using namespace std;
int arr[5005];
int chk[400005];
int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << endl;

		int n, ans=0; 
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			for (int k = 0; k < i; k++)
			{
				if (chk[200000 + arr[i] - arr[k]])
				{
					ans++;
					break;
				}
			}
			for (int k = 0; k <= i; k++)
				chk[200000 + arr[i] + arr[k]] = 1;
		}
		cout << ans << endl;
		fill(chk, chk + 400005, 0);
	}
	return 0;
}