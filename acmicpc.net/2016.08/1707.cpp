#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	string str;
	map<string, int> m;
	cin >> str;
	int len = str.length(), idx = 0;
	for (int i = 0; i < len; i++)
	{
		string temp = "";
		for (int k = i; k < len; k++) temp += str[k];
		m[temp]++;
	}
	string suffix[5005];
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
		suffix[idx++] = iter->first;

	int cnt, MAX = 0;
	for (int i = 1; i < idx; i++)
	{
		cnt = 0;
		int l1 = suffix[i - 1].length();
		int l2 = suffix[i].length();
		for (int k = 0; k < (l1 < l2 ? l1 : l2); k++)
			if (suffix[i][k] == suffix[i - 1][k]) cnt++;
			else break;
			if (cnt > MAX) MAX = cnt;
	}
	cout << MAX << endl;
	return 0;
}