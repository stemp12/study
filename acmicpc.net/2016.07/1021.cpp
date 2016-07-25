#include<iostream>
#include<deque>
using namespace std;
int main()
{
	int n, m, arr[55] = { 0, }, ans = 0;
	deque<int> dq, left, right;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) dq.push_back(i);
	for (int i = 0; i<m; i++)
	{
		cin >> arr[i];
		if (arr[i] == dq.front())
		{
			dq.pop_front();
			continue;
		}

		left.clear(); right.clear();
		left = right = dq;
		dq.clear();
		int cnt[2] = { 0, };
		while (left.front() != arr[i])
		{
			left.push_back(left.front());
			left.pop_front();
			cnt[0]++;
		} left.pop_front();

		while (right.front() != arr[i])
		{
			right.push_front(right.back());
			right.pop_back();
			cnt[1]++;
		} right.pop_front();

		if (cnt[0]<cnt[1]) { ans += cnt[0]; dq = left; }
		else { ans += cnt[1]; dq = right; }
	}
	cout << ans << endl;

	return 0;
}