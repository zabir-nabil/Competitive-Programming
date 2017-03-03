
#include <bits/stdc++.h>
#define INF 120000
using namespace std;
int dp[112][10004];
int cap[112];
int val[112];
int m,n;

int rec(int idx, int mon) {
    if(mon > m && m < 1800)
        return -INF;
    if(mon > m + 200)
        return -INF;
    if(idx == n) {
        if(mon > m && mon <= 2000)
            return -INF;
            else
        return 0;
    }
    //if(idx>n)return -INF;
    if(dp[idx][mon] != -1)
        return dp[idx][mon];

    return dp[idx][mon] = max(rec(idx + 1, mon), val[idx] + rec(idx + 1, mon + cap[idx]));
}
int main()
{
int k = 2;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
    //   k = ;



memset(dp,-1,sizeof(dp));

            for(int a=0;a<n;a++)
            {
                cin>>cap[a]>>val[a];
            }
        int ans = rec(0,0);
        cout<<ans<<endl;

    }


    return 0;
}

