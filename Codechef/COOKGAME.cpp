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
 
#define MOD 1000000007
using namespace std;
int level[100009];
ll power(ll base,ll pw,ll mod)
{
    if (pw == 0)
        return 1;
    ll p12 = power(base, pw/2, mod) % mod;
    p12 = (p12 * p12) % mod;
    if(pw%2==0)
        return p12;
    else
        return ((base%mod)*(p12))%mod;
}
int main()
{
    int tc;
    sfi(tc);
    while(tc--)
    {
        int n;
        sfi(n);
        int mop = 0;
        loop(i,1,n)
        {
            sfi(level[i]);
            if(level[i]==-1)
                mop++;
        }
 
 
 
        int ans = 1;
 
        if(level[1]>1)
            ans = 0;
        if(level[1]==-1)
            level[1]=1;
 
        level[n+1]= 1;
        ll cmb = 1;
        int str = 1,en = 1;
        loop(i,2,n+1)
        {
            if(level[i]!=-1
                    && level[i-1]!=-1)
            {
                if(level[i]==level[i-1]
                        && level[i]==1)
                {
 
                }
                else if(level[i]!=1 &&
                        level[i]!= level[i-1]+1)
                {
                    ans = 0;
 
                    break;
                }
            }
 
            if(level[i]==-1 &&
                    level[i-1]!=-1)
            {
                str = i-1;
            }
            else if( (level[i]!=-1
                      && level[i-1]==-1)
                     || (i==n+1 && level[n]==-1))
            {
                en = i;
                int gap = (en-str-1);
                int gmin = (level[en]
                            -level[str]-1);
                if(gap==gmin)
                {
                    //no shit
                }
                else if(gap>=level[en]-1)
                {
                    gap-=level[en]-1;
                    cmb = (cmb%MOD*power(2,gap,MOD))%MOD;
 
                }
                else
                {
                    ans = 0;
                    break;
                }
 
            }
 
 
        }
        if(ans==0)
            pf("0\n");
        else
            pf("%lld\n",cmb%MOD);
 
 
    }
 
 
    return 0;
}
 