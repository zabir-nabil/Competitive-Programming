

/****************************************
              Zerus97
*****************************************/

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
#define MOD 1000000007
ll bigmod(ll bs,ll p,ll mod)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll v = bigmod(bs,p/2,mod)%mod;
        return (v*v)%mod;

    }
    else if(p%2==1)
    {
        ll v = bigmod(bs,p/2,mod)%mod;
        return ((v*v)%mod*(bs%mod))%mod;

    }

}
ll modInverse(ll a, ll m)
{

    return bigmod(a, m-2, m)%MOD;

}
int n;
int arr[105];
int dp[102][10009][3];
bool dp_ms[102][10009][3];
int rec(int i,int kb,int lastdf)
{
    if(i==n+1)
        return -INF;

    if(dp_ms[i][kb][lastdf])
        return dp[i][kb][lastdf];
    int ans = 0;
    int p1,p2;
    if(kb==0)
    {
        p1 = rec(i+1,1,arr[i]);
        p2 = rec(i+1,2,arr[i]);
        p1 = max(p1,arr[i]);
        p2 = max(p2,arr[i]);
        ans = min(p1,p2);
    }
    else if(kb==1)
    {
        p1 = rec(i+1,1,lastdf+arr[i]);
        p1 = max(p1,lastdf+arr[i]);
        if(arr[i]>lastdf)
        {
            p2 = rec(i+1,2,arr[i]-lastdf);
            p2 = max(arr[i]-lastdf,p2);
        }
        else if(arr[i]<lastdf)
        {
            p2 = rec(i+1,1,lastdf-arr[i]);
            p2 = max(p2,lastdf-arr[i]);
        }
        else
        {
            p2 = rec(i+1,0,0);
        }

        ans= min(p1,p2);

    }
    else if(kb==2)
    {
        p1 = rec(i+1,2,lastdf+arr[i]);
        p1 = max(p1,lastdf+arr[i]);
        if(arr[i]>lastdf)
        {
            p2 = rec(i+1,1,arr[i]-lastdf);
            p2 = max(arr[i]-lastdf,p2);
        }
        else if(arr[i]<lastdf)
        {
            p2 = rec(i+1,2,lastdf-arr[i]);
            p2 = max(p2,lastdf-arr[i]);
        }
        else
        {
            p2 = rec(i+1,0,0);
        }

        ans= min(p1,p2);

    }

dp_ms[i][kb][lastdf]=true;
return dp[i][kb][lastdf] = ans;
}

int main()
{

    int tc;
    sfi(tc);
    while(tc--)
    {
        sfi(n);
        loop(i,1,n)
        sfi(arr[i]);
        ms(dp_ms,false);
        int ans = rec(1,0,0);

        pf("%d\n",ans);

    }



    return 0;
}
