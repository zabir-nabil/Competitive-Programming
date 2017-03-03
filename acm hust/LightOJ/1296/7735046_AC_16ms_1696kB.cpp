#include<bits/stdc++.h>
#define ll unsigned long long
#define pb push_back
#define SZ(v) v.size()
#define pll pair<ll,ll>
#define ff first
#define ss second
using namespace std;
int n;
ll arr[1009];
ll grundy(ll i)
{
    if(i==1)
        return 0;
    if(i%2)
        return grundy(i/2);
    return i/2;
 
}
int main()
{
 
 
    //cout<<grundy(15)<<endl;
    //freopen("out.txt","w",stdout);
    int tc,cas=0;
    scanf("%d",&tc);
    //memset(dp,-1,sizeof dp);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        ll xns = 0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            xns^=grundy(arr[i]);
        }
 
        if(xns==0)
            printf("Case %d: Bob\n",++cas);
        else
            printf("Case %d: Alice\n",++cas);
 
 
    }
 
 
 
    return 0;
}