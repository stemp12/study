#include<iostream>
#include<algorithm>
using namespace std;
struct POS {
	int x, y;
}pos[100005];
bool cmpx(POS p1, POS p2)
{
	return p1.x < p2.x;
}
bool cmpy(POS p1, POS p2)
{
	return p1.y < p2.y;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &pos[i].x, &pos[i].y);
	stable_sort(pos, pos + n, cmpy);
	stable_sort(pos, pos + n, cmpx);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", pos[i].x, pos[i].y);
	return 0;
}