#include<iostream>
#include<string>
#include<set>
using namespace std;
int gcd(int a, int b)
{
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}
int main()
{
	set<string> state;
	string input, word = "";
	int input_len, game = 0, sz = 0;
	while (getline(cin, input))
	{
		input += '.';
		input_len = input.size();
		for (int i = 0; i < input_len; i++)
		{
			if (isalpha(input[i]))
				word += toupper(input[i]);
			else
			{
				if (word.compare("BULLSHIT") == 0)
				{
					game++;
					sz += state.size();
					state.clear();
				}
				else if (word.size()) state.insert(word);
				word = "";
			}
		}
	}
	int g = gcd(sz, game);
	cout << sz / g << " / " << game / g << endl;
	return 0;
}