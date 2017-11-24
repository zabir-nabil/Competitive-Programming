#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a0[1005];
ll a1[1005];
ll a2[1005];
ll a3[1005];
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;

        for(int i=1; i<=n; i++)
        {
            cin>>a0[i]>>a1[i]>>a2[i]>>a3[i];
        }

        int q;
        cin>>q;
        while(q--)
        {
            int t;
            cin>>t;
            ll ans = 10000000000*10000000000;
            for(int i=1; i<=n; i++)
            {
                ans = min(ans,a0[i]
                          + a1[i]*t
                          + a2[i]*(t*t)
                          + a3[i]*(t*t*t));
            }
            printf("%lld\n",ans);

        }


    }
    return 0;
}
