#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000000
int pizza[2][2222];
int piece[2][MAX];
int idx[2];
void input(int index, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		cin >> pizza[index][i];
		pizza[index][sz + i] = pizza[index][i];
		piece[index][idx[index]++] = pizza[index][i];
	}
}
void make_piece(int index, int sz)
{
	int temp;
	for (int i = 2; i < sz; i++)
	{
		temp = 0;
		for (int k = 0; k < i; k++) temp += pizza[index][k];
		piece[index][idx[index]++] = temp;

		for (int k = 1; k < sz; k++)
		{
			temp = temp - pizza[index][k - 1] + pizza[index][k + i - 1];
			piece[index][idx[index]++] = temp;
		}
	}
	piece[index][idx[index]++] = temp + pizza[index][sz - 2];
	sort(piece[index], piece[index] + idx[index]);
}
int binary_search(int num)
{
	if (num<0 || num>piece[1][idx[1] - 1]) return -1;
	int left = 0, right = idx[1] - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (num>piece[1][middle]) left = middle + 1;
		else if (num < piece[1][middle]) right = middle - 1;
		else return middle;
	}
	return -1;
}
int idx_cnt(int i, int num)
{
	if (i == -1) return 0;

	int cnt = 0, temp = i;
	while (piece[1][temp--] == num) cnt++;
	while (piece[1][i++] == num) cnt++;
	return cnt - 1;
}
int main()
{
	int n; cin >> n;
	int a_piece, b_piece;
	cin >> a_piece >> b_piece;

	input(0, a_piece); make_piece(0, a_piece);
	input(1, b_piece); make_piece(1, b_piece);

	int index = binary_search(n);
	int cnt = idx_cnt(index, n);

	for (int i = 0; i < idx[0]; i++)
	{
		if (n - piece[0][i] == 0) cnt++;
		else
		{
			index = binary_search(n - piece[0][i]);
			cnt += idx_cnt(index, n - piece[0][i]);
		}
	}
	cout << cnt << endl;
	return 0;
}