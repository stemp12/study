#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long int U_INT;
U_INT odd[100001] = { 2, };
int main()
{
	for (int i = 1; i < 100001; i++)
		odd[i] = 4 * i + 2 + odd[i - 1];

	int Test; cin >> Test;
	for (int T = 1; T <= Test; T++)
	{
		cout << "Case #" << T << endl;

		int n, step, x = 1, y = 1;
		U_INT ans = 1, matrix[100005] = { 0, };
		string path;
		cin >> n >> step >> path;

		matrix[0] = 1 + (n - 1) / 2 + odd[((n - 1) - (n - 1) / 2) - 1];
		for (int i = 1, f = ((n - 1) / 2) * 4; i<n; i++)
		{
			if (n % 2 == 0)
			{
				if (i % 2) matrix[i] = matrix[i - 1] + 1;
				else
				{
					matrix[i] = matrix[i - 1] + f;
					f -= 4;
				}
			}
			else
			{
				if (i % 2)
				{
					matrix[i] = matrix[i - 1] + f;
					f -= 4;
				}
				else matrix[i] = matrix[i - 1] + 1;
			}
		}


		for (int i = 0; i < step; i++)
		{
			if (path[i] == 'D') y++;
			else if (path[i] == 'U') y--;
			else if (path[i] == 'R') x++;
			else if (path[i] == 'L') x--;
			else while (1);

			int temp = x + y - 1, nx, ny;
			U_INT val = 0;

			if (x == 1 && y == 1)
				nx = ny = val = 1;
			else if (temp <= n)
			{
				nx = 1;
				ny = temp;

				val = 1 + (temp - 1) / 2 + odd[((temp - 1) - (temp - 1) / 2) - 1];
			}
			else
			{
				nx = x - (n - y);
				ny = n;

				val = matrix[nx - 1];
			}

			if ((x + y - 1) % 2 == 0) ans += val - (x - nx);
			else ans += val + (x - nx);
		}
		cout << ans << endl;
	}
	return 0;
}