#include <bits/stdc++.h>
 
 
#define loop(i,s,e) for(int i = s;i<=e;i++) //including end point
 
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
 
#define sful(a) scanf("%llu",&a);
 
#define sfulul(a,b) scanf("%llu %llu",&a,&b);
 
#define sful2(a,b) scanf("%llu %llu",&a,&b); // A little different
 
#define sfc(a) scanf("%c",&a);
 
#define sfs(a) scanf("%s",a);
 
#define getl(s) getline(cin,s);
 
#define mp make_pair
 
#define paii pair<int, int>
 
#define padd pair<dd, dd>
 
#define pall pair<ll, ll>
 
#define vi vector<int>
 
#define vll vector<ll>
 
#define mii map<int,int>
 
#define mlli map<ll,int>
 
#define mib map<int,bool>
 
#define fs first
 
#define sc second
 
#define CASE(t) printf("Case %d: ",++t) // t initialized 0
 
#define cCASE(t) cout<<"Case "<<++t<<": ";
 
#define D(v,status) cout<<status<<" "<<v<<endl;
 
#define INF 1000000000   //10e9
 
#define EPS 1e-9
 
#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )
 
#define CONTEST 1
using namespace std;
int n;
ll grid[205][205];
ll dp[205][205];
ll rec(int layer,int cell)
{
    if(layer==2*n)
        return 0;
    if(dp[layer][cell]!=-1)
        return dp[layer][cell];
 
    ll p = grid[layer][cell]
            ,p1 = 0;
    if(layer<n)
    {
        p1 = max(rec(layer+1,cell),
                 rec(layer+1,cell+1));
    }
    if(layer>=n)
    {
 
        p1 = max(rec(layer+1,cell),
                 rec(layer+1,cell-1));
 
    }
 
    return dp[layer][cell] = p+p1;
 
 
}
int main()
{
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        sfi(n);
        for(int i=0; i<=2*n; i++)
        {
            for(int j=0; j<=2*n; j++)
                grid[i][j] = -INF;
        }
 
        for(int i=1; i<=n; i++)
        {
            for(int x=1; x<=i; x++)
                sfl(grid[i][x]);
        }
 
        for(int j=n+1; j<=(2*n-1); j++)
        {
            for(int x=1; x<=((2*n-1)-j+1); x++)
                sfl(grid[j][x]);
        }
        ms(dp,-1);
        ll ans = rec(1,1);
 
        CASE(cas);
        pf("%lld\n",ans);
 
 
    }
 
 
 
    return 0;
}