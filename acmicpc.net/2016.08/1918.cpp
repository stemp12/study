#include<iostream>
#include<string>
#include<iomanip>
#include<stack>
using namespace std;
void postfix(string);
int main()
{
	string input;
	cin >> input;
	postfix(input);
	return 0;
}
void postfix(string input)
{
	stack<char> post;
	bool nth, last = false;
	for (int i = 0; i < input.length(); i++)
	{
		if (input.length() - 1 == i) last = true;

		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			cout << input[i];
			continue;
		}

		if (post.empty()) nth = true;
		else nth = false;

		if (input[i] == '(') post.push(input[i]);
		else if (input[i] == ')')
		{
			while (true)
			{
				if (post.top() == '(')
				{
					post.pop();
					break;
				}
				cout << post.top();
				post.pop();
			}
		}
		else if (input[i] == '+' || input[i] == '-')
		{
			if (!nth)
			{
				while (post.top() != '(')
				{
					cout << post.top();
					post.pop();
					if (post.empty()) break;
				}
			}
			post.push(input[i]);
		}
		else if (input[i] == '*' || input[i] == '/')
		{
			if (!nth)
			{
				while (post.top() != '(' && post.top() != '+' && post.top() != '-')
				{
					cout << post.top();
					post.pop();
					if (post.empty()) break;
				}
			}
			post.push(input[i]);
		}
	}
	while (!post.empty())
	{
		cout << post.top();
		post.pop();
	}
	cout << endl;
}