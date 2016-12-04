#include<iostream>
#include<string.h>
using namespace std;
bool chk(int num, int &input)
{
	char temp[10] = { 0, };
	sprintf(temp, "%d", num);
	int len = strlen(temp), sum = num;
	for (int i = 0; i < len; i++)  sum += (temp[i] - '0');

	if (sum == input) return true;
	else return false;
}
int main()
{
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
		if (chk(i, input))
		{
			cout << i << endl;
			return 0;
		}
	cout << 0 << endl;
	return 0;
}