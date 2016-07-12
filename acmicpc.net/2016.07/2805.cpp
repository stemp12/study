#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000003];
int n, m;
int my_search(int start, int end, bool flag, int stan)
{
	long long sum = 0;
	for (int i = end; i >= start; i--)
	{
		if(flag) sum += arr[i]-arr[start];
		else sum += arr[i] - stan;

		if (sum > m) return 1;
	}
	if (sum == m) return 0;
	else return -1;
}
int bsearch(int &left, int &right, bool flag, int stan)
{
	int middle, state;
	while (left <= right)
	{
		middle = (left + right) / 2;
		int state;
		if(flag) state= my_search(middle, n, flag, 0);
		else state = my_search(stan, n, flag, middle);

		if (state == 0)
		{
			if (flag) return arr[middle];
			else return middle;
		}
		else if (state == 1) left = middle + 1;
		else right = middle - 1;
	}

	if(flag) return 0;
	else
	{
		state = my_search(stan, n, flag, middle);
		if (state == -1) return middle - 1;
		else return middle;
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n + 1);
	
	int left = 0, right = n;
	int ans = bsearch(left, right, true, 0);

	if (ans) cout << ans << endl;
	else
	{
		if (right < left) swap(left, right);
		int nl = arr[left], nr = arr[right];
		ans = bsearch(nl, nr, false, right);
		printf("%d", ans);
	}
	return 0;
}