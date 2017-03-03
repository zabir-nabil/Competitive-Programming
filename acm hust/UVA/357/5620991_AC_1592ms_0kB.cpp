

/****************************************

Cat Got Bored

*****************************************/

#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<e;i++) //excluding end point

#define pb(a) push_back(a)

#define sqr(x) ((x)*(x))

#define CIN ios_base::sync_with_stdio(0); cin.tie(0);

#define ll long long

#define ull unsigned long long

#define SZ(a) int(a.size())

#define read() freopen("input.txt", "r", stdin)

#define write() freopen("output.txt", "w", stdout)


#define ms(a,b) memset(a, b, sizeof(a))

#define all(v) v.begin(), v.end()

#define PI acos(-1.0)

#define pf printf

#define sfi(a) scanf("%d",&a);

#define sfii(a,b) scanf("%d %d",&a,&b);

#define sfl(a) scanf("%lld",&a);

#define sfll(a,b) scanf("%lld %lld",&a,&b);

#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define INF 1000000000   //10e9

#define EPS 1e-9


using namespace std;
int cubes[6];
ll dp[6][30009];
ll rec(ll mon,int i)
{
    if(mon==0)
        return  1;
    if(mon<0)
        return 0;
        if(i>=5)
            return 0;
    if(dp[i][mon]==-1)
        return dp[i][mon] = 0 + rec(mon,i+3)+rec(mon - cubes[i],i) +rec(mon - cubes[i+1],i+1)+rec(mon - cubes[i+2],i+2) ;
    return dp[i][mon];

}
int main()
{
    int i;
   cubes[0] = 50;
   cubes[1] = 25;
   cubes[2] = 10;cubes[3] = 5;cubes[4] = 1;
    ll amount;
    while(scanf("%lld",&amount)!=EOF)
    {
        ms(dp,-1);
        ll ans = rec(amount,0);
   //   pf("%d\n",ans);

       if(ans==1)
        cout<<"There is only "<<ans<<" way to produce "<<amount<<" cents change."<<endl;
       else

        cout<<"There are "<<ans<<" ways to produce "<<amount<<" cents change."<<endl;




    }


    return 0;
}
