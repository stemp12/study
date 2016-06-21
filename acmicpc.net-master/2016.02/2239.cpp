#include<iostream>
#include<string>
using namespace std;
int input[9][9], index = 0;
struct POS{
	int x, y;
}pos[100];
int search(int x, int y, int n)
{
	if (n == 0) return 1;

	bool chk[2][10] = { false, };
	int X[2] = { x - 1, x + 1 }, Y[2] = { y - 1, y + 1 };

	while (X[0] >= 0 || X[1]<9)
	{
		if (X[0] > -1 && input[y][X[0]] == n) return 1;
		if (X[1] < 9 && input[y][X[1]] == n) return 1;

		X[0]--; X[1]++;
	}
	while (Y[0] >= 0 || Y[1]<9)
	{
		if (Y[0] > -1 && input[Y[0]][x] == n) return 1;
		if (Y[1] < 9 && input[Y[1]][x] == n) return 1;

		Y[0]--; Y[1]++;
	}
	return 0;
}
void print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9; k++)
			printf("%d", input[i][k]);
		printf("\n");
	}
}
int rect(int y, int x)
{
	int sx, sy;

	if (0 <= y && y <= 2) sy = 0;
	else if (3 <= y && y <= 5) sy = 3;
	else sy = 6;

	if (0 <= x && x <= 2) sx = 0;
	else if (3 <= x && x <= 5) sx = 3;
	else sx = 6;
	bool chk[10] = { false, };
	for (int i = sy; i < sy + 3; i++)
		for (int k = sx; k < sx + 3; k++)
		{
			if (input[i][k] == 0) return true;

			if (!chk[input[i][k]]) chk[input[i][k]] = true;
			else return false;
		}
	return true;
}
void dfs(int idx)
{
	if (idx == index)
	{
		print();
		exit(0);
	}
	for (int i = 1; i <= 9; i++)
	{
		input[pos[idx].y][pos[idx].x] = i;
		if (!search(pos[idx].x, pos[idx].y, i) && rect(pos[idx].y, pos[idx].x)) dfs(idx + 1);
		input[pos[idx].y][pos[idx].x] = 0;
	}
}
int main()
{
	string str;
	for (int i = 0; i < 9; i++)
	{
		cin >> str;
		for (int k = 0; k < 9; k++)
		{
			input[i][k] = str[k] - '0';
		}
	}
	for (int i = 0; i < 9; i++)
		for (int k = 0; k < 9; k++)
		{
			//scanf("%d", &input[i][k]);
			if (input[i][k] == 0)
			{
				pos[index].x = k;
				pos[index].y = i;
				index++;
			}
		}
	dfs(0);
	return 0;
}