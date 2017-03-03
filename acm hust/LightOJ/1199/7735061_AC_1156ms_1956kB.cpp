#include<bits/stdc++.h>
#define ll unsigned long long
#define pb push_back
#define SZ(v) v.size()
#define pll pair<ll,ll>
#define ff first
#define ss second
using namespace std;
int n;
int arr[105];
int dp[10005];
int subgames[10009];
int grundy(int i)
{
    if(i==1 || i==2)
        return 0;//L
    if(dp[i]!=-1)
        return dp[i];
    int idx = 0;
    for(int x=1;x<=((i-1)/2);x++)
    {
        int tg = 0;
        tg^= grundy(x);
        tg^= grundy(i-x);
        idx++;
        subgames[idx] = tg;
    }
    int curg = 0;
    sort(subgames+1,subgames+idx+1);
    for(int ii=1;ii<=idx;ii++)
    {
        if(subgames[ii]==curg)
            curg++;
    }
 
    return dp[i] = curg;
 
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tc,cas=0;
    scanf("%d",&tc);
    memset(dp,-1,sizeof dp);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        int xns = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            xns^=grundy(arr[i]);
        }
 
        if(xns==0)
            printf("Case %d: Bob\n",++cas);
        else
            printf("Case %d: Alice\n",++cas);
 
 
    }
 
 
 
    return 0;
}