#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int INT;
INT arr[10003], n, k;
INT bsearch(INT left, INT right)
{
	INT mid;
	while (left <= right)
	{
		mid = (left + right) / 2;

		INT state = 0;
		for (int i = 0; i < k; i++)
			state += arr[i] / mid;

		if (state >= n) left = mid + 1;
		else right = mid - 1;
	}
	return right;
}
int main()
{
	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	sort(arr, arr + k);

	cout << bsearch(1, arr[k - 1]) << endl;
	return 0;
}