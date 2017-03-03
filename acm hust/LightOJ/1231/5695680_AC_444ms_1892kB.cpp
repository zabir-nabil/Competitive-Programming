

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
int C[59]; //carefully look at memory requirements
int dp[1002][52];
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
        sfi(C[x]);


        ms(dp,-1);

        ll ans = rec(k,n);
        CASE(cas);
        pf("%lld\n",ans);
   }


    return 0;
}
