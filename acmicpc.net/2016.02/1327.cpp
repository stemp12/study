#include<iostream>
#include<queue>
#include<map>
using namespace std;
int n, cycle;
queue<int> q[2];
int arr[10], input, ans;
map<int, int> use;
int rev(int num, int pos)
{
	char temp[10] = { 0, };
	sprintf(temp, "%d", num);
	int s = pos, e = pos + cycle - 1;
	while (s < e) swap(temp[s++], temp[e--]);
	return atoi(temp);
}
int main()
{
	cin >> n >> cycle;
	for (int i = 0, mul = 1; i < n; i++, mul *= 10)
	{
		cin >> arr[i];
		input += arr[i] * mul;
		ans += (i + 1)*mul;
	}

	int cnt = 0, idx = 0;
	q[idx].push(input);
	use[input]++;

	while (!q[idx].empty())
	{
		while (!q[idx].empty())
		{
			int temp = q[idx].front();
			q[idx].pop();
			if (temp == ans)
			{
				cout << cnt << endl;
				return 0;
			}
			for (int i = 0; i <= n - cycle; i++)
			{
				int num = rev(temp, i);
				if (!use[num])
				{
					use[num]++;
					q[!idx].push(num);
				}
			}
		}
		idx ? idx = 0 : idx = 1;
		cnt++;
	}
	cout << -1 << endl;
	return 0;
}