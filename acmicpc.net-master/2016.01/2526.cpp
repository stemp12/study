#include<iostream>
using namespace std;
int main()
{
	int n, p, arr[100], idx = 0;
	cin >> n >> p;
	arr[idx++] = n;
	int temp = n;
	while (true)
	{
		temp = (temp*n) % p;
		for (int i = 0; i < idx; i++)
			if (arr[i] == temp)
			{
				cout << idx - i << endl;
				return 0;
			}
		arr[idx++] = temp;
	}
	return 0;
}