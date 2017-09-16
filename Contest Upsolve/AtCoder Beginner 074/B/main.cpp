#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dis[305][305];
int main()
{
    int n;
    while(cin>>n)
    {
        ll mxdis = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%lld",&dis[i][j]);
                mxdis = max(mxdis,dis[i][j]);
            }
        }
        ll ans = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j && dis[i][j]!=0)
                {
                    ans = -1;
                    break;
                }

                if(i!=j && dis[i][j]<=0)
                {
                    ans = -1;
                    break;
                }

                if(dis[i][j]!=dis[j][i])
                {
                    ans =-1;
                    break;
                }

                if(dis[i][j]>0)
                {
                    for(int k=1; k<=n; k++)
                    {
                        if(k!=i && k!=j)
                        {
                            if(dis[i][k] + dis[k][j]<dis[i][j])
                            {
                                ans = -1;
                                break;
                            }
                        }
                    }
                }
            }

            if(ans==-1)
                break;
        }

        mxdis = 0;
        if(ans!=-1)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=i+1; j<=n; j++)
                {
                    int flg = 1;
                    for(int k=1; k<=n; k++)
                    {
                        if(k!=i && k!=j)
                        {
                            if(dis[i][j]
                                    == dis[i][k]+dis[k][j])
                            {
                                flg = 0;
                            }
                        }
                    }
                    if(flg)
                    {
                        mxdis+=dis[i][j];
                    }
                }
            }
        }

        if(ans!=-1)
            ans = mxdis;

        printf("%lld\n",ans);



    }
}
