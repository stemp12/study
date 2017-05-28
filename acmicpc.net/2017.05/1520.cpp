#include<iostream>
using namespace std;
int w, h;
int arr[505][505] = { 0, }, memo[505][505] = { 0, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int dfs(int x, int y) {
	if (memo[y][x] != -1) return memo[y][x];
	int cnt = 0;

	if (y == h - 1 && x == w - 1) return 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
			if (arr[y][x] > arr[ny][nx]) {
				cnt += dfs(nx, ny);
			}
		}
	}
	return memo[y][x] = cnt;
}
int main() {

	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			scanf("%d", &arr[i][k]);
			memo[i][k] = -1;
		}
	}
	printf("%d\n", dfs(0, 0));
	return 0;
}