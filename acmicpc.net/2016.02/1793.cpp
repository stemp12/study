#include<iostream>
#include<string>
using namespace std;
string rev(string str)
{
	string r = "";
	int len1 = str.length();
	for (int i = len1 - 1; i >= 0; i--)
		r += str[i];
	return r;
}
string add(string str1, string str2)
{
	string ans = "";
	int len1 = str1.length() - 1;
	int len2 = str2.length() - 1;

	int temp, carry = 0;
	while (true)
	{
		if (len1 >= 0 && len2 >= 0)  temp = (str1[len1--] - '0') + (str2[len2--] - '0') + carry;
		else if (len1 < 0 && len2 >= 0) temp = (str2[len2--] - '0') + carry;
		else if (len2 < 0 && len1 >= 0) temp = (str1[len1--] - '0') + carry;
		else break;

		if (temp > 9)
		{
			carry = 1;
			temp -= 10;
		}
		else carry = 0;

		ans += (temp + '0');
	}
	if (carry) ans += (carry + '0');
	return rev(ans);
}
int main()
{
	string ans[255] = { "1", "1", "3" };
	for (int i = 3; i <= 251; i++)
		ans[i] = add(ans[i - 1], add(ans[i - 2], ans[i - 2]));
	int n;
	while (cin >> n)
		cout << ans[n] << endl;
	return 0;
}