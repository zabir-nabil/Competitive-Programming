

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

#define mod 100000007
using namespace std;
int n,k;
int A[105];
int C[105]; //carefully look at memory requirements
int dp[10002][105];
ll dp2[10005];
ll rec(int am , int i)
{
if(am == 0 && i == 0) return 1;
   if(i<=0) return 0;
   if(dp[am][i] != -1) return dp[am][i];
    ll ans = 0;
    for(int xx = 0; (xx <= C[i]) && (xx*A[i] <= am); xx++ ){
        ans = (ans%mod + rec( am - xx * A[i] , i - 1)%mod ) ;
        ans %= mod;
    }
 return dp[am][i] = ans;
}
ll prerecBU()
{
    ms(dp2,0);
    dp2[0] = 1;
    int maxi = 10002;
    for(int a = 1;a<=n;a++)
    {
        for(int b =1;b<=maxi ;b++)
        {
            if( b>=A[a])
            {
                dp2[b] = (dp2[b]%mod + dp2[ b - A[a] ] %mod );
                dp2[b]%=mod;
            }
        }
    }
}
int main()
{

   int t;int cas = 0;
   sfi(t);
   while(t--)
   {
//ms(A,0);
//ms(C,0);
       sfii(n,k);
       for(int x = 1;x<=n;x++)
        sfi(A[x]);

       for(int x = 1;x<=n;x++)
        C[x] = k;


        ms(dp,-1);

       // ll ans = rec(k,n);
       prerecBU();
        CASE(cas);
        pf("%lld\n",dp2[k]%mod);
   }


    return 0;
}
