#include<iostream>
using namespace std;
int main()
{
	int ans[16] = { 3, 11 }, n;
	cin >> n;
	if (n % 2 == 1) cout << 0 << endl;
	else
	{
		for (int i = 2; i < n / 2; i++)
			ans[i] = ans[i - 1] * 4 - ans[i - 2];
		cout << ans[n / 2 - 1] << endl;
	}
	return 0;
}