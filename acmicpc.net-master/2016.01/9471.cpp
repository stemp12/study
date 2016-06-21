#include<iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int T, m, m1, m2, period;
	while (n--)
	{
		cin >> T >> m;
		m1 = m2 = 1;
		period = 0;
		do
		{
			int temp = m1;
			m1 = m2;
			m2 = (temp + m2) % m;
			period++;
		} while (!(m1 == 1 && m2 == 1));
		cout << T << ' ' << period << endl;
	}
	return 0;
}