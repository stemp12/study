#include<iostream>
#include<queue>
#include<map>
using namespace std;
queue < tuple<int, int, int> > q;
map<tuple<int, int, int>, int> m;
void chk(tuple<int, int, int> t)
{
	if (!m[t])
	{
		m[t]++;
		q.push(t);
	}
}
int main()
{
	int A, B, C;
	bool ans[205] = { false, };
	cin >> A >> B >> C;
	q.push(make_tuple(0, 0, C));
	while (!q.empty())
	{
		auto now = q.front();
		m[now]++;
		q.pop();

		int a = get<0>(now);
		int b = get<1>(now);
		int c = get<2>(now);

		if (a == 0) ans[c] = true;

		int po;
		if (c != 0 && b != B) //c->b
		{
			po = B - b;
			auto temp = (po <= c ? make_tuple(a, B, c - po) : make_tuple(a, b + c, 0));
			chk(temp);
		}
		if (c != 0 && a != A)//c->a
		{
			po = A - a;
			auto temp = (po <= c ? make_tuple(A, b, c - po) : make_tuple(a + c, b, 0));
			chk(temp);
		}

		if (b != 0 && a != A)//b->a
		{
			po = A - a;
			auto temp = (po <= b ? make_tuple(A, b - po, c) : make_tuple(a + b, 0, c));
			chk(temp);
		}
		if (b != 0 && c != C)//b->c
		{
			po = C - c;
			auto temp = (po <= b ? make_tuple(a, b - po, C) : make_tuple(a, 0, c + b));
			chk(temp);
		}
		if (a != 0 && b != B)//a->b
		{
			po = B - b;
			auto temp = (po <= a ? make_tuple(a - po, B, c) : make_tuple(0, b + a, c));
			chk(temp);
		}
		if (a != 0 && c != C)//a->c
		{
			po = C - c;
			auto temp = (po <= a ? make_tuple(a - po, b, C) : make_tuple(0, b, c + a));
			chk(temp);
		}
	}

	for (int i = 0; i < 205; i++)
		if (ans[i]) cout << i << ' ';
	return 0;
}