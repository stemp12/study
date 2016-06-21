#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> ppl[30003];
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first < p2.first;
}
int cal(int dir, int home, int bus, int school)
{
	int temp = bus;
	int cnt, i;

	if (dir == 1) cnt = school - ppl[0].first;
	else cnt = ppl[home - 1].first - school;

	for (dir ? i = 0 : i = home - 1; ppl[i].first != school;)
	{
		if (temp >= ppl[i].second)
		{
			temp -= ppl[i].second;
			ppl[i].second = 0;
		}
		else if (temp != 0 && temp < ppl[i].second)
		{
			ppl[i].second -= temp;
			temp = 0;
		}

		if (temp == 0 && ppl[i].second != 0)
		{
			temp = bus;
			cnt += abs(school - ppl[i].first) * 2;
		}

		if (ppl[i].second == 0)
		{
			dir ? cnt += abs(ppl[i + 1].first - ppl[i].first) : cnt += abs(ppl[i - 1].first - ppl[i].first);
			dir ? i++ : i--;
		}
	}
	return cnt;
}
int main()
{
	int home, bus, school;
	cin >> home >> bus >> school;
	for (int i = 0; i < home; i++)
		cin >> ppl[i].first >> ppl[i].second;
	ppl[home++].first = school;
	sort(ppl, ppl + home, cmp);

	int cnt = cal(1, home, bus, school);
	cnt += cal(0, home, bus, school);
	cout << cnt << endl;
	return 0;
}