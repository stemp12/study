#include<iostream>
#include<list>
#include<string>
using namespace std;
int main()
{
	int n; cin >> n;
	while (n--)
	{
		list<char> lst;
		list<char>::iterator iter = lst.begin();
		int idx = 0, cnt = 0;
		string str;
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			if ((str[i] == '<'  && iter == lst.begin()) || (str[i] == '>' && iter == lst.end())) continue;

			if (str[i] == '<') iter--;
			else if (str[i] == '>') iter++;
			else if (str[i] == '-')
			{
				if (!lst.empty())
				{
					if (iter != lst.begin()) iter = lst.erase(--iter);
				}
			}
			else lst.insert(iter, str[i]);
		}
		for (iter = lst.begin(); iter != lst.end(); ++iter)
			printf("%c", *iter);
		printf("\n");
	}
	return 0;
}