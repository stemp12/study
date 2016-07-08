#include<iostream>
using namespace std;
int main()
{
	int n, f;
	cin >> n >> f;
	n = (n / 100) * 100;
	for (int i = 0; i < 100; i++)
		if ((n + i) % f == 0)
		{
			printf("%02d", i);
			break;
		}
	return 0;
}