#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long int INT;
int MOD(int n)
{
	int cnt = 0;
	for (INT i = 1; i < n; i *= 2) cnt++;
	return cnt - 1;
}
int main()
{
	INT a, b, c, idx, ans = 1, cal;
	cin >> a >> b >> c;
	a = a%c;

	while (b>1)
	{
		idx = MOD(b);
		cal = a;
		for (int i = 0; i < idx; i++)
			cal = ((cal%c)*(cal%c)) % c;

		INT temp = pow(2, idx);
		b -= temp;
		ans = ((ans%c)*(cal%c)) % c;
	}
	if (b == 1) cout << ((ans%c)*(a%c)) % c << endl;
	else cout << ans%c << endl;
	return 0;
}