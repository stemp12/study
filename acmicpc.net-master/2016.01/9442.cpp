#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str;
string word[22];
bool cmp(string str1, string str2)
{
	int idx1 = 0, idx2 = 0;
	while (true)
	{
		for (int i = 0; i < 26; i++)
		{
			if (str1[idx1] == str2[idx2])
				break;
			else if (str1[idx1] == str[i])
				return true;
			else if (str2[idx2] == str[i])
				return false;
		}
		idx1++; idx2++;
		if (idx2 == str2.length()) return false;
		else if (idx1 == str1.length()) return true;
	}
}
int main()
{
	int n, T = 0;
	while (cin >> n && n != 0)
	{
		cin >> str;
		for (int i = 0; i < n; i++)
			cin >> word[i];
		sort(word, word + n, cmp);

		cout << "year " << ++T << endl;
		for (int i = 0; i < n; i++)
			cout << word[i] << endl;
	}
	return 0;
}