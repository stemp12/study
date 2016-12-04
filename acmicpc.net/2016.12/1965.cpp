#include<iostream>
using namespace std;
int main()
{
	int n, input, idx = 0, arr[1005] = { 0, };
	cin >> n;
	for (int i = 0, k; i < n; i++)
	{
		cin >> input;
		for (k = idx - 1; k >= 0; k--)
			if (arr[k] < input) break;

		if (k == idx - 1) arr[idx++] = input;
		else arr[k + 1] = input;
	}
	cout << idx << endl;
	return 0;
}