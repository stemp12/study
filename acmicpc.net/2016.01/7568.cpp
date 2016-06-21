#include<iostream>
#include<algorithm>
using namespace std;
struct DATA{
	int weight;
	int tall;
	int rank;
}data[60];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i].weight >> data[i].tall;

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (k != i)
				if (data[i].weight < data[k].weight && data[i].tall < data[k].tall)
					data[i].rank++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << data[i].rank + 1 << ' ';
	return 0;
}