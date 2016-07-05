#include<iostream>
using namespace std;
int POW(int num)
{
	return num*num;
}
int main()
{
	int T; cin >> T;
	while (T--)
	{
		pair<int, int> start, des, planet;
		int n, cnt = 0, r;

		cin >> start.first >> start.second >> des.first >> des.second;
		cin >> n;
		while (n--)
		{
			cin >> planet.first >> planet.second >> r;
			int d1 = POW(start.first - planet.first) + POW(start.second - planet.second);
			int d2 = POW(des.first - planet.first) + POW(des.second - planet.second);

			if (d1 <= POW(r) && d2 <= POW(r)) continue;

			if (d1 <= POW(r)) cnt++;
			if (d2 <= POW(r)) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}