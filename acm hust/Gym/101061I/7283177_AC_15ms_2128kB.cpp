

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
int sncfr[3][28];
char str[100009];
int main()
{

    int tc;
    sfi(tc);
    while(tc--)
    {
        loop(x,0,2)
        loop(y,0,27)
        sncfr[x][y] = 0;


        sfs(str);
        int len = strlen(str);
        loop(x,0,len-1)
        {
            sncfr[1][ (int)(str[x]-'a')+1 ]++;
        }
        sfs(str);
        len = strlen(str);
        loop(x,0,len-1)
        {
            sncfr[2][ (int)(str[x]-'a')+1 ]++;
        }
        int ans = 0;
        loop(cc,1,26)
        {
            ans+=abs(sncfr[1][cc]-sncfr[2][cc]);
        }
        pf("%d\n",ans);


    }



    return 0;
}
