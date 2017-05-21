#include<iostream>
#define FINISH_CNT 6
#define MAX_SIZE 15
using namespace std;

int n, arr[MAX_SIZE] = { 0, };
int ans[FINISH_CNT];

void dfs(int idx, int start) {
	if (idx == FINISH_CNT) {
		for (int i = 0; i < FINISH_CNT; i++)
			printf("%d ", ans[i]);
		printf("\n");
		
		return;
	}
	for (int i = start; i < n; i++) {
		ans[idx] = arr[i];
		dfs(idx+1, i + 1);
	}
}

int main()
{
	while (cin >> n && n) {
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		dfs(0, 0);
		cout << endl;
	}
	return 0;
}