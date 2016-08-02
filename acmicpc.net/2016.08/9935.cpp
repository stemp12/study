#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char input[1000003], bomb[40], ans[1000003];
int a_idx, blen;
int main()
{
	scanf("%s", input);
	scanf("%s", bomb);

	blen = strlen(bomb);
	for (int i = 0; input[i]; i++)
	{
		ans[a_idx++] = input[i];
		if (i >= blen - 1 && input[i] == bomb[blen - 1])
		{
			bool chk = false;
			for (int k = blen - 1, j = a_idx - 1; k >= 0; k--, j--)
				if (bomb[k] != ans[j]) { chk = true; break; }

			if (!chk) a_idx -= blen;
		}
	}

	if (a_idx != 0) for (int i = 0; i < a_idx; i++) printf("%c", ans[i]);
	else printf("FRULA");
	return 0;
}