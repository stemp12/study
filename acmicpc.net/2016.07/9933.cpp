#include<iostream>
#include<string>
#include<map>
using namespace std;
string rev(string str)
{
	int len = str.length();
	string temp = "";
	for (int i = len - 1; i >= 0; i--)
		temp += str[i];
	return temp;
}
int main()
{
	int n; cin >> n;
	string input;
	map<string, int> m;
	while (cin >> input)
	{
		m[input]++;
		m[rev(input)]++;

		if (m[input] == 2 || m[rev(input)] == 2) break;
	}
	cout << input.length()<<' '<<input[input.length() / 2];
	return 0;
}