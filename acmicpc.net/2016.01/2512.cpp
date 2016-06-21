#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	int arr[10005], sum = 0, total;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);
	cin >> total;
	if (sum <= total) cout << arr[n - 1] << endl;
	else
	{
		int ans, original = total;
		for (int i = 1; i < n; i++)
		{
			total -= arr[i - 1];
			if (total / (n - i) < arr[i])
			{
				ans = total / (n - i);
				break;
			}
		}
		if (original / n>ans) cout << original / n << endl;
		else cout << ans << endl;
	}
	return 0;
}
