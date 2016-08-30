#include<iostream>
using namespace std;
int MAX;
int click[10][6]={{0, 1, 2, -1},
                  {3, 7, 9, 11, -1},
                  {4, 10, 14, 15, -1},
                  {0, 4, 5, 6, 7, -1},
                  {6, 7, 8, 10, 12, -1},
                  {0, 2, 14, 15, -1},
                  {3, 14, 15, -1},
                  {4, 5, 7, 14, 15, -1},
                  {1 ,2, 3, 4, 5, -1},
                  {3, 4, 5, 9, 13, -1}};

bool chk(int *arr)
{
    for(int i=0; i<16; i++)
        if(arr[i]!=12) return false;
    return true;
}
void dfs(int *arr, int pos, int cnt)
{
    if(pos==10)
    {
        if(chk(arr) && MAX<cnt) MAX=cnt;
        return ;
    }
    for(int i=0; i<4; i++)
    {
        dfs(arr, pos+1, cnt+i);
        for(int k=0; click[pos][k]!=-1; k++)
        {
            int now=click[pos][k];
            arr[now]+=3;
            if(arr[now]==15) arr[now]=3;
        }
    }
}
int main()
{
    int T; cin>>T;
    while(T--)
    {
        int arr[16];
        for(int i=0; i<16; i++) cin>>arr[i];
        MAX=-1;
        dfs(arr, 0, 0);
        cout<<MAX<<endl;
    }
    return 0;
}