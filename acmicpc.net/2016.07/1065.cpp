#includeiostream
using namespace std;
int main()
{
	int n, cnt = 0;
	cin  n;
	for (int i = 1; i = n; i++)
	{
		if (i  100) cnt++;
		else
		{
			int a = i  100;
			int b = (i  10) % 10;
			int c = i % 10;
			if (b - a == c - b) cnt++;
		}
	}
	cout  cnt  endl;
	return 0;
}