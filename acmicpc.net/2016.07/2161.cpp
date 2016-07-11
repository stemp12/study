#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n, idx = 0;
	queue<int> q, trash;

	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() != 1)
	{
		if (!idx)
		{
			trash.push(q.front());
			q.pop();
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
		idx = !idx;
	}

	while (!trash.empty())
	{
		cout << trash.front() << ' ';
		trash.pop();
	} cout << q.front();
	return 0;
}