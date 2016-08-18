#include<iostream>
#include<string>
#include<iomanip>
#include<stack>
using namespace std;
void postfix(char *);
bool separation(stack<double> &, char, bool);
void cal(stack<double> &, char);
int main()
{
	while (true)
	{
		cout << "Input to Infix	: ";
		char input[1005] = { 0, };
		cin >> input;
		cout << input << endl;
		if (!strcmp(input, "exit")) break;
		cout << "Change to Postfix : ";
		postfix(input);
		cout << endl;
	}
	return 0;
}
bool separation(stack<double> &num, char ch, bool last)
{
	static char temp[1005] = { 0, };
	static int cnt = 0;
	static bool real = false;

	if (ch >= '0' && ch <= '9')
	{
		temp[cnt++] = ch;
		real = true;
		if (last)
		{
			int res = atoi(temp);
			cout << res << ' ';
			num.push(res);
			real = false;
			cnt = 0;
			memset(temp, 0, sizeof(temp));
		}
		return false;
	}
	else
	{
		cnt = 0;
		int res = atoi(temp);
		if (real)
		{
			cout << res << ' ';
			num.push(res);
			real = false;
		}
		memset(temp, 0, sizeof(temp));
	}
	return false;
}
void cal(stack<double> &num, char symbol)
{
	double temp = 0;
	temp += num.top();
	num.pop();
	switch (symbol)
	{
		case '+': temp = num.top() + temp; break;
		case '-': temp = num.top() - temp; break;
		case '*': temp = num.top() * temp; break;
		case '/': temp = num.top() / temp; break;
	}
	num.pop();
	num.push(temp);
}
void postfix(char *input)
{
	stack<char> post;
	stack<double> num;
	bool nth, last = false;
	for (int i = 0; i < strlen(input); i++)
	{
		if (strlen(input) - 1 == i) last = true;
		if (input[i] == ' ') continue;
		else if (separation(num, input[i], last)) continue;

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
				cal(num, post.top());
				cout << post.top() << ' ';
				post.pop();
			}
		}
		else if (input[i] == '+' || input[i] == '-')
		{
			if (!nth)
			{
				while (post.top() != '(')
				{
					cal(num, post.top());
					cout << post.top() << ' ';
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
					cal(num, post.top());
					cout << post.top() << ' ';
					post.pop();
				}
			}
			post.push(input[i]);
		}
	}
	while (!post.empty())
	{
		cal(num, post.top());
		cout << post.top() << ' ';
		post.pop();
	}
	cout << endl;

	cout << "----------------------------------" << endl;
	cout.precision(2);
	cout << "Result : " << fixed << num.top() << endl;
}