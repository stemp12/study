#include<iostream>
#include<string.h>
using namespace std;
int arr[100003], chk[100003], num[100003];
int main()
{
	int T, n, ans;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			chk[i] = num[i] = 0;
			scanf("%d", &arr[i]);
		}

		int cycle = 1;
		for (int i = 1; i <= n; i++)
		{
			if (chk[i]) continue;
			else chk[i] = cycle;
			//cout << i << endl;

			int cnt = 1, pos = i;
			num[i] = 1;
			while (true)
			{
				pos = arr[pos];
				if (chk[pos]) break;
				cnt++;
				chk[pos] = cycle;
				num[pos] = cnt;
			}

			if (i != pos)
			{
				if (cycle == chk[pos]) ans += (num[pos] - 1);
				else ans += cnt;
			}
			//printf("%d %d %d %d\n", cnt, pos, num[pos], ans);
			cycle++;
		}
		printf("%d\n", ans);
	}
	return 0;
}