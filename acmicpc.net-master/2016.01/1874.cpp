#include<iostream>
#define MAX 100005
using namespace std;
int input[MAX];
char ans[MAX * 2];
int main()
{
	int n; cin >> n;
	int big = 0, top = 0, idx = 0, num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (input[top]<num)
		{
			for (int i = big; i < num; i++)
			{
				input[top++] = i + 1;
				ans[idx++] = '+';
			}
			big = num;
		}

		if (input[--top] == num)
			ans[idx++] = '-';
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < idx; i++)
		printf("%c\n", ans[i]);
	return 0;
}
