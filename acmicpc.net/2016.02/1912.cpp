#include<iostream>
using namespace std;
#define MIN -2100000000
int main()
{
	int n, in, sum = 0, MAX = 0, mMAX = MIN;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		sum += in;
		if (in <= 0 && mMAX < in) mMAX = in;
		if (sum < 0) sum = 0;
		if (sum > MAX) MAX = sum;
	}
	if (MAX == 0 && mMAX != MIN) cout << mMAX << endl;
	else cout << MAX << endl;


	return 0;
}