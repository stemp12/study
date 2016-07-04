#include<iostream>
#include<algorithm>
using namespace std;
double arr[5], ans;
char sym[3];
//case 1 (a, b), c, d
//case 2 a, (b, c), d
//case 3 a, b, (c, d)
//case 4 (a, b), (c, d)
//case 5 (a, b, c), d
//case 6 a, (b, c, d)
//case 7 a, b, c, d
void make_sym(int idx);
void chk(double temp[]);
double _cal2(double a, double b, char symbol);
double _cal3(double a, double b, double c, char symbol1, char symbol2);
double _cal4();

int main()
{
	while (cin >> arr[0] && arr[0] != -1)
	{
		for (int i = 1; i < 5; i++)	cin >> arr[i];
		for (int i = 0; i < 5; i++) cout << arr[i] << ' ';

		sort(arr, arr + 4);
		do {
			make_sym(0);
			if (ans == 1) break;
		} while (next_permutation(arr, arr + 4));
	
		for (int i = 0; i < 5; i++)
			cout << arr[i] << ' ';
		if (ans) cout << "OK!" << endl;
		else cout << "NO!" << endl;
		
		ans = 0;
	}
	return 0;
}
void make_sym( int idx)
{
	if (ans == 1) return;

	if (idx == 3)
	{
		double temp[7] = {0, };

		temp[0] = _cal3(_cal2(arr[0], arr[1], sym[0]), arr[2], arr[3], sym[1], sym[2]);
		temp[1] = _cal3(arr[0], _cal2(arr[1], arr[2], sym[1]), arr[3], sym[0], sym[2]);
		temp[2] = _cal3(arr[0], arr[1], _cal2(arr[2], arr[3], sym[2]), sym[0], sym[1]);
		temp[3] = _cal2(_cal2(arr[0], arr[1], sym[0]), _cal2(arr[2], arr[3], sym[2]), sym[1]);
		temp[4] = _cal2(_cal3(arr[0], arr[1], arr[2], sym[0], sym[1]), arr[3], sym[2]);
		temp[5] = _cal2(arr[0], _cal3(arr[1], arr[2], arr[3], sym[1], sym[2]), sym[0]);
		temp[6] = _cal4();

//		cout << sym[0] << ' ' << sym[1] << ' ' << sym[2] << endl;
		chk(temp);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == 0) sym[idx] = '+';
		else if (i == 1) sym[idx] = '*';
		else if (i == 2) sym[idx] = '-';
		else sym[idx] = '/';

		make_sym(idx + 1);
	}
}
void chk(double temp[])
{
	for (int i = 0; i < 7; i++)
	{
//		cout << temp[i] << ' ';
		if (temp[i] == arr[4])
		{
			ans = 1;
			return;
		}
	}
//	cout << endl;
}
double _cal2(double a, double b, char symbol)
{
	double temp = 0;
	if (symbol == '+') temp = a + b;
	else if (symbol == '-') temp = a - b;
	else if (symbol == '*') temp = a * b;
	else if(symbol=='/' && b!=0) temp = a / b;
	
	return temp;
}
double _cal3(double a, double b, double c, char symbol1, char symbol2)
{
	double temp;
	if ((symbol2 == '*' || symbol2 == '/') && (symbol1 == '+' || symbol1 == '-'))
	{
		temp = _cal2(b, c, symbol2);
		temp = _cal2(a, temp, symbol1);
	}
	else
	{
		temp = _cal2(a, b, symbol1);
		temp = _cal2(temp, c, symbol2);
	}
	return temp;
}
double _cal4()
{
	double temp = 0;

	if (sym[1] == '*' || sym[1] == '/')
		temp = _cal3(arr[0], _cal2(arr[1], arr[2], sym[1]), arr[3], sym[0], sym[2]);
	else if (sym[2] == '*' || sym[2] == '/')
		temp = _cal3(arr[0], arr[1], _cal2(arr[2], arr[3], sym[2]), sym[0], sym[1]);
	else 
		temp = _cal3(_cal2(arr[0], arr[1], sym[0]), arr[2], arr[3], sym[1], sym[2]);
	
	return temp;
}