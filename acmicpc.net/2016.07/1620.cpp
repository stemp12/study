#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<stdio.h>
#include<cstring>
using namespace std;
struct Monster {
	char name[105];
	int num;
}monster[100005], name[100005];
bool cmp(Monster m1, Monster m2)
{
	return strcmp(m1.name, m2.name) == -1 ? true : false;
}
int bsearch(int left, int right, char now[])
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (strcmp(name[mid].name, now) == -1) left = mid + 1;
		else if (strcmp(name[mid].name, now) == 1) right = mid - 1;
		else break;
	}
	return name[mid].num;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", monster[i].name);
		monster[i].num = name[i].num = i + 1;
		strcpy(name[i].name, monster[i].name);
	}
	sort(name, name + n, cmp);

	while (m--)
	{
		char input[105] = { 0, };
		scanf("%s", input);

		if (input[0] >= '0' && input[0] <= '9') printf("%s\n", monster[atoi(input) - 1].name);
		else printf("%d\n", bsearch(0, n - 1, input));
	}

	return 0;
}