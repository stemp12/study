#include<iostream>
#include<string>
using namespace std;
int main()
{
	string n, n16, ans = "";
	cin >> n;
	n16 = n + "0000";

	int len1 = n.length(), len2 = n16.length();
	bool carry = false;
	for (int i = len1 - 1, k = len2 - 1, idx = 0; k >= 0; k--, i--, idx++)
	{
		if (i >= 0) ans += (n[i] - '0') + (n16[k] - '0') + '0';
		else ans += n16[k];

		if (carry) ans[idx]++;

		if (ans[idx] == '2')
		{
			ans[idx] = '0';
			carry = 1;
		}
		else if (ans[idx] == '3')
		{
			ans[idx] = '1';
			carry = 1;
		}
		else
			carry = 0;
	}
	if (carry) ans += '1';
	int sz = ans.length();
	for (int i = sz - 1; i >= 0; i--)
		cout << ans[i];
	return 0;
}