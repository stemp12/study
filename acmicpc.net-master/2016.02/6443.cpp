#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
bool cmp(char a, char b)
{
	if (a == b)
		return a < b;
	else return a < b;
}
int main()
{
	int n; scanf("%d", &n);
	while (n--)
	{
		char str[105] = { 0, };
		scanf("%s", str);
		int len = strlen(str);
		sort(str, str + len);
		do
		{
			printf("%s\n", str);
		} while (next_permutation(str, str + len, cmp));
	}
	return 0;
}