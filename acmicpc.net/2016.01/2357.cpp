#include<iostream>
#include<vector>
#include<algorithm>
#define SZMAX 100005
using namespace std;
int init_min(vector<int> &input, vector<int> &tree, int node, int start, int end)
{
	if (start == end) return tree[node] = input[start];
	return tree[node] = min(init_min(input, tree, node * 2, start, (start + end) / 2), init_min(input, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}
int init_max(vector<int> &input, vector<int> &tree, int node, int start, int end)
{
	if (start == end) return tree[node] = input[start];
	return tree[node] = max(init_max(input, tree, node * 2, start, (start + end) / 2), init_max(input, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}
int MIN(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || start > right)
		return 2100000000;
	if (left <= start && end <= right)
		return tree[node];

	return min(MIN(tree, node * 2, start, (start + end) / 2, left, right), MIN(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int MAX(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || start > right)
		return -1;
	if (left <= start && end <= right)
		return tree[node];

	return max(MAX(tree, node * 2, start, (start + end) / 2, left, right), MAX(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> input(SZMAX), MIN_tree(SZMAX * 3), MAX_tree(SZMAX * 3);
	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	init_min(input, MIN_tree, 1, 0, n - 1);
	init_max(input, MAX_tree, 1, 0, n - 1);
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		int mi = MIN(MIN_tree, 1, 0, n - 1, a - 1, b - 1);
		int ma = MAX(MAX_tree, 1, 0, n - 1, a - 1, b - 1);
		printf("%d %d\n", mi, ma);
	}
	return 0;
}