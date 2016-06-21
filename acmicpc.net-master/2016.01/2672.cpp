#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Rect{
	double x1, x2, y1, y2;
};
bool chk(double x1, double x2, double y1, double y2, Rect rect)
{
	//return rect.x1<x2 && rect.x2>x1 && rect.y1<y2 && rect.y2>y1;
	return rect.x1 <= x1 && rect.x2 >= x2 && rect.y1 <= y1 && rect.y2 >= y2;
}
int main()
{
	vector<double> x, y;
	Rect rect[33];
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;
		rect[i].x2 += rect[i].x1;	rect[i].y2 += rect[i].y1;

		x.push_back(rect[i].x1);	x.push_back(rect[i].x2);
		y.push_back(rect[i].y1);	y.push_back(rect[i].y2);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	double sum = 0;
	for (int i = 1; i < x.size(); i++)
		for (int k = 1; k < y.size(); k++)
			for (int j = 0; j < n; j++)
				if (chk(x[i - 1], x[i], y[k - 1], y[k], rect[j]))
				{
					sum += (x[i] - x[i - 1])*(y[k] - y[k - 1]);
					break;
				}

	if (int(sum) == sum) printf("%d", int(sum));
	else printf("%.2lf", sum);

	return 0;
}