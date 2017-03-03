

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
char sss[105];
int dp[105][105];
int rec(int i,int j)
{
    if(i==j)
        return 0;
        if(i>j)
            return 0;
    if(dp[i][j] == -1){


    if(sss[i] == sss[j])
       dp[i][j] = rec(i+1,j-1);
    else
        dp[i][j] = min( rec(i,j-1) +1 , rec(i+1,j) +1  ) ;


    }

    return dp[i][j] ;
}
int main()
{
int t;int cas = 0;
sfi(t);
while(t--)
{
   scanf("%s",sss);
   int len = strlen(sss);
   ms(dp,-1);
    int ans = rec(0,len-1);
    CASE(cas);
    pf("%d\n",ans);

}

    return 0;
}
