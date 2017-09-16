#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll pre_arr[10000002];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int m;
        scanf("%d",&m);

        for(int i=1;i<=m;i++)
        {
            int x,y;
            ll val;
            scanf("%d %d",&x,&y);
            scanf("%lld",&val);
            pre_arr[x]+=val;
            pre_arr[y+1]-=val;
        }
        ll mxval = 0;
        for(int i=1;i<=n;i++)
        {
            pre_arr[i] += pre_arr[i-1];
            mxval = max(mxval,pre_arr[i]);
        }

        printf("%lld\n",mxval);


    }
    return 0;
}
