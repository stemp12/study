#include<iostream>
#include<algorithm>
using namespace std;
int arr[500005], n, m, input;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)  scanf("%d", &arr[i]);
	sort(arr, arr + n);
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &input);

		int start = 0;
		int end = n - 1;
		int ans = 0;
		while (start <= end)
		{
			int middle = (start + end) / 2;

			if (arr[middle] == input)
			{
				ans = 1;
				break;
			}

			if (arr[middle] < input) start = middle + 1;
			if (arr[middle] > input) end = middle - 1;

		}

		printf("%d ", ans);
	}
	return 0;
}