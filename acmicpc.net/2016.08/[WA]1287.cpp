#include<iostream>
#include<string.h>
#include<iomanip>
#include<stack>
using namespace std;
void postfix(char *);
bool separation(stack<long long> &, char, bool);
void cal(stack<long long> &, char);
bool possible(char *);
int main()
{
	char input[3000] = { 0, };
	cin >> input;
	if (!possible(input)) cout << "ROCK" << endl;
	else postfix(input);
	return 0;
}
bool separation(stack<long long> &num, char ch, bool last)
{
	static char temp[3000] = { 0, };
	static int cnt = 0;
	static bool real = false;

	if (ch >= '0' && ch <= '9')
	{
		temp[cnt++] = ch;
		real = true;
		if (last)
		{
			int res = atoi(temp);
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
			num.push(res);
			real = false;
		}
		memset(temp, 0, sizeof(temp));
	}
	return false;
}
void cal(stack<long long> &num, char symbol)
{
	long long temp = 0;
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
	stack<long long> num;
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
					post.pop();
				}
			}
			post.push(input[i]);
		}
	}
	while (!post.empty())
	{
		cal(num, post.top());
		post.pop();
	}

	cout << num.top() << endl;
}
bool possible(char *input)
{
	stack<char> g, n;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == '(') g.push('(');
		else if (input[i] == ')')
		{
			if (g.empty()) return false;
			g.pop();
		}

		if (input[i] >= '0' && input[i] <= '9')
		{
			if (n.empty())
			{
				n.push(input[i]);
				while (i<strlen(input) && (input[i] >= '0' && input[i] <= '9')) i++;
				i--;
			}
			else
			{
				if (n.top() >= '0' && n.top() <= '9') return false;
				else
				{
					n.push(input[i]);
					while (i<strlen(input) && (input[i] >= '0' && input[i] <= '9')) i++;
					i--;
				}
			}
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if (n.empty()) return false;
			else
			{
				if (n.top() == '+' || n.top() == '-' || n.top() == '*' || n.top() == '/') return false;
				else n.push(input[i]);
			}
		}
	}
	if (g.empty()) return true;
	else return false;
}