#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double x, y, z;
	while (cin >> x >> y)
	{
		z = (y * 100) / x;
		z = (int)z;
		if (z >= 99) cout << -1 << endl;
		else cout << (long long)ceil(((((z + 1)*x) / 100) - y) * (100 / (100 - z - 1))) << endl;
	}
	return 0;
}