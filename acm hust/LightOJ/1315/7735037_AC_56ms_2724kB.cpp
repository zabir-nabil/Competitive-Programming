#include<bits/stdc++.h>
#define ll unsigned long long
#define pb push_back
#define SZ(v) v.size()
#define pll pair<ll,ll>
#define ff first
#define ss second
#define INF 9999999999
using namespace std;
int n;
int mexar[10000];
int dp[505][505];
int drx[]= {1,-1,-1,-2,-3,-2};
int dry[]= {-2,-3,-2,-1,-1,1};
int rec(int i,int j)
{
    if(i<0 || i>501 || j<0 || j>501)
        return INF;
    if(dp[i][j]!=-1)
        return dp[i][j];
 
 
    int idx = 0;
    for(int ml=0; ml<6; ml++)
    {
 
        mexar[ml]=rec(i+drx[ml],j+dry[ml]);
 
    }
 
    sort(mexar,mexar+6);
    int xr = 0;
    for(int i=0; i<=5; i++)
    {
        if(mexar[i]==xr)
            xr++;
    }
 
    return dp[i][j]=xr;
 
}
void prec()
{
    memset(dp,-1,sizeof dp);
    //dp[0][0]=0;
    //dp[0][1]=0;
    //dp[1][0]=0;
    for(int i=0; i<=501; i++)
    {
        for(int j=0; j<=501; j++)
        {
            rec(i,j);//<<" ";
        }
 
    }
 
}
int main()
{
    prec();
 
    int tc,cas=0;
    scanf("%d",&tc);
 
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        int xns = 0;
        for(int i=1; i<=n; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            xns^=dp[x][y];
        }
 
        if(xns==0)
            printf("Case %d: Bob\n",++cas);
        else
            printf("Case %d: Alice\n",++cas);
 
 
    }
 
 
 
    return 0;
}