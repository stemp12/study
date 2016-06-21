#include<iostream>
#include<vector>
using namespace std;
int init(vector<int> &input, vector<int> &tree, int node, int start, int end)
{
	if (start == end) return tree[node] = input[start];
	else return tree[node] = init(input, tree, node * 2, start, (start + end) / 2) + init(input, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
int sear(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	return sear(tree, node * 2, start, (start + end) / 2, left, right) + sear(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main()
{
	vector<int> input(100005), tree(300000);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	init(input, tree, 1, 0, n - 1);
	cin >> m;
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", sear(tree, 1, 0, n - 1, a - 1, b - 1));
	}
	return 0;
}
