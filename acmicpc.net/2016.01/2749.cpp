#include<iostream>
#define MOD 1000000
#define pisano 1500000
using namespace std;
typedef unsigned long long int INT;
int main()
{
	INT n; cin >> n;
	int a = 0, b = 1, c = 1;
	for (int i = 1; i < n%pisano; i++)
	{
		c = a + b;
		a = b%MOD;
		b = c%MOD;
	}
	cout << c%MOD << endl;
	return 0;
}