#include<iostream>
using namespace std;
int main()
{
    int n; cin >> n;
    int arr[105] = { 0, };
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int m; cin >> m;
    while (m--)
    {
        int ppl, num;
        cin >> ppl >> num;
        if (ppl == 1)
        {
            for (int i = num, k = 2; i <= n; i = num*k, k++)
                arr[i] = !arr[i];
        }
        else
        {
            int left = num - 1, right = num + 1;
            while (left != 0 && right != n + 1)
            {
                if (arr[left]==arr[right])
                    left--, right++;
                else break;
            }
            for (int i = left + 1; i <= right - 1; i++)
                arr[i] = !arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i];
        if (i % 20 == 0) cout << endl;
        else cout << ' ';
    }
    return 0;
}