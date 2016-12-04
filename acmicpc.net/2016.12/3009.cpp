#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int, int> first, second;
	map<int, int>::iterator iter;
	for (int i = 0; i < 3; i++)
	{
		int a, b;
		cin >> a >> b;
		first[a]++;
		second[b]++;
	}
	for (iter = first.begin(); iter != first.end(); iter++)
		if (iter->second % 2 == 1) cout << iter->first << ' ';
	for (iter = second.begin(); iter != second.end(); iter++)
		if (iter->second % 2 == 1) cout << iter->first << endl;

	return 0;
}