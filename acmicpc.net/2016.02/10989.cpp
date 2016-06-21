#include<stdio.h>
#include<map>
using namespace std;
map<int, int> m;
int main()
{
	int n, input;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		m[input]++;
	}
	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		int c = iter->second;
		for (int i = 0; i < c; i++)
			printf("%d\n", iter->first);
	}
	return 0;
}