#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[10005] = { 0, }, val[10005] = { 0, }, MAX = 0;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	val[1] = arr[1];
	for (int i = 1; i <= n; i++)
	{
		for (int k = i; k <= n; k++)
		{
			val[k] = max(val[k], arr[i] + val[k - i]);

			MAX = max(MAX, val[k]);
		}
	}
	cout << MAX << endl;

	return 0;
}