#include<iostream>
using namespace std;
int main()
{
	int arr[100002] = { 1, 3, }, n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		arr[i] = ((arr[i - 1] * 2) % 9901 + arr[i - 2]) % 9901;
	cout << arr[n] << endl;
	return 0;
}