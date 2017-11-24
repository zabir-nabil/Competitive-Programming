#include <bits/stdc++.h>

using namespace std;
bool vis[505][505];
int n,m;
bool valid(int r,int c)
{
    if(!vis[r][c])
    {
        if(r>=1 && r<=n
                && c>=1 && c<=n)
            return 1;
    }
    return 0;
}
int cnt;
void dfs(int r,int c)
{
    if(cnt==m)
        return;
    vis[r][c] = 1;
    printf("%d %d\n",r,c);
    cnt++;


    if(valid(r+1,c))
    {
        dfs(r+1,c);
    }
    else if(valid(r,c+1))
    {
        dfs(r,c+1);
    }
    else if(valid(r-1,c))
    {
        dfs(r-1,c);
    }
    else if(valid(r,c-1))
    {
        dfs(r,c-1);
    }


}
int main()
{

    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                int temp;
                cin>>temp;
            }
        }
    }

    memset(vis,false,sizeof(vis));
    cnt = 0;
    dfs(1,1);



    return 0;
}
