#include<iostream>
#include<set>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n, MAX = 0, num[27];
	set<char> se;
	string input[11];
	fill(num, num + 27, -1);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		int len = input[i].length();
		for (int k = 0; k < len; k++) se.insert(input[i][k]);
	}

	set<char>::iterator iter;
	vector<char> v;
	for (iter = se.begin(); iter != se.end(); iter++)
		v.push_back(*iter);

	sort(v.begin(), v.end());
	do
	{
		for (int i = 0, val = 9; i < v.size(); i++, val--)
			num[int(v[i] - 'A')] = val;

		int temp = 0, len = 0, sum = 0;
		for (int i = 0; i < n; i++, temp = 0)
		{
			len = input[i].length();
			for (int k = 0; k < len; k++, temp *= 10) temp += num[int(input[i][k] - 'A')];
			sum += (temp / 10);
		}
		MAX = max(MAX, sum);
	} while (next_permutation(v.begin(), v.end()));
	cout << MAX << endl;
	return 0;
}