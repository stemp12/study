#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	while (n--)
	{
		char input[111] = { 0, };
		cin >> input;
		int len = strlen(input);
		for (int i = len - 1; i > 0; i--)
			if (input[i - 1] < input[i])
			{
				sort(input + i, input + len);
				for (int k = i; k < len; k++)
					if (input[i - 1] < input[k])
					{
						swap(input[i - 1], input[k]);
						sort(input + i, input + len);
						goto skip;
					}
			}
	skip:
		cout << input << endl;
	}
	return 0;
}