#include <bits/stdc++.h>

using namespace std;
int n;

int cost[25][3];
int dp[25][3];
int rec(int i,int col)
{
    if(i==n )return 0;
    int tmp = 9999999;
    if(dp[i][col]==-1){
   for(int cc = 0;cc<3;cc++)
   {
       if(cc!=col)
       tmp = min(tmp, rec(i+1,cc) + cost[i][cc]);
   }
   dp[i][col] = tmp;

    }

    return dp[i][col];
}
int main()
{
    int t;
    cin>>t;
    int cas = 0;
    while(t--)
    {
        cin>>n;
        for(int a=0;a<n;a++)
        {
           for(int x = 0;x<3;x++)
           {
               cin>>cost[a][x];
           }
        }

        memset(dp,-1,sizeof(dp));

        int ans = min ( rec(0,0) , min(rec(0,1) , rec(0,2)) );
        cout<<"Case "<<++cas<<": "<<ans<<endl;

    }
    return 0;
}
