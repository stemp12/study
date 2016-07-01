#include<iostream>
using namespace std;
int main() 
{
	int a, b, edge, other=0;
	cin >> a >> b >> edge;

	if(a%2==1 && b%2==1)
	for (int i = 0; i < edge; i++)
	{
		int to, from;
		cin >> to >> from;
		if (to % 2 == 1 && from % 2 == 1) other = 1;
	}
	cout << a / 2 + b / 2 + other << endl;
	return 0;
}