#include<iostream>
#include<stack>
typedef long long INT;
using namespace std;
void cal(stack<int> &s, INT *arr, INT &ans, int i, int n)
{
	INT area;
	while (!s.empty())
	{
		if (i != -1 && arr[i] > arr[s.top()]) break;

		int top = s.top(), left;
		s.pop();

		if (s.empty()) left = -1;
		else left = s.top();

		if (i != -1) area = arr[top] * (i - left - 1);
		else area = arr[top] * (n - left - 1);

		if (area > ans) ans = area;
	}
}
int main()
{
	int n;
	while (cin >> n && n)
	{
		INT arr[100005] = { 0, }, ans = 0;
		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (!s.empty() && arr[i] < arr[s.top()]) cal(s, arr, ans, i, n);
			s.push(i);
		}
		cal(s, arr, ans, -1, n);
		cout << ans << endl;
	}
	return 0;
}