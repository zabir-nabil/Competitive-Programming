#include <bits/stdc++.h>
#include<cstring>
#include<cmath>
using namespace std;
int n;
#define inf 999999
int mncst[105];
int ar[105];
int taken[105];
int dp[105][50005];
int rec(int i,int k)
{
    if(k>2)
        return inf;
    if(i==2*n+1 && k==2)
        return 0;
    if(i==2*n+1)
        return inf;

    if(dp[i][k]!=-1)
        return dp[i][k];

    int p1 = rec(i+1,k+1);
    int p2=inf,p3=inf,p4=inf;

    if(i+1<=2*n)
    {
        p2 = abs(ar[i]-ar[i+1])
        + rec(i+2,k);
    }
    else if(i+2<=2*n)
    {
        p2 = abs(ar[i]-ar[i+2])
        + rec(i+3,k+1);
    }
    else if(i+3<=2*n)
    {
        p2 = abs(ar[i]-ar[i+3])
        + rec(i+4,k+2);
    }

    return dp[i][k] = min({p1,p2,p3,p4});

}
int main()
{

    while(cin>>n)
    {
        memset(dp,-1,sizeof(dp));
        for(int i=1; i<=2*n; i++)
        {
            cin>>ar[i];

        }


        for(int i=1; i<=2*n; i++)
        {
            int mndf = 99999999;
            int an;
            for(int j=1; j<=2*n; j++)
            {
                if(i!=j)
                {
                    if(abs(ar[i]-ar[j])<=mndf && !taken[j])
                    {
                        an = j;
                        mndf = abs(ar[i]-ar[j]);

                    }

                }


            }

            taken[i] = an;
            mncst[i] = ar[an];
        }

        sort(ar+1,ar+2*n+1);



        int ans = rec(1,0);

        cout<<ans<<endl;

    }
    return 0;
}
