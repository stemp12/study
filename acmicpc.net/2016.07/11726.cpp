#include<iostream>
using namespace std;
int main()
{
	int arr[1001] = { 0, 1, 2, }, n;
	cin >> n;
	for (int i = 3; i <= n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	cout << arr[n] << endl;
	return 0;
}