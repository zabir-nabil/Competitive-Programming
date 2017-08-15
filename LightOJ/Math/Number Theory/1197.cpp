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
bool isp[100005];
vector<ll>prm;
void presv()
{
    ms(isp,true);
    for(ll i=2; i<=100000; i++)
    {
        if(isp[i])
        {
            prm.pb(i);
            for(ll j=(i*i); j<=100000; j+=i)
            {
                isp[j] = false;
            }
        }
    }

}
ll sv(ll a, ll b)
{

    ms(isp,true);
    ll sq = sqrt(max(a,b))+1;
    for(int i=0; i<prm.size();i++)
    {

            ll lowb = (a/prm[i])*prm[i];
            for(ll j=lowb; j<=b; j+=prm[i])
            {
                if(j>=a && j!=prm[i])
                {
                    isp[j-a] = false;

                }
            }

    }
    ll primenum = 0;
    for(ll ip=a; ip<=b; ip++)
    {
        //cout<<ip<<" "<<isp[ip-a]<<endl;
        if(isp[ip-a])
        {
            primenum++;
        }
    }
    if(a==1)
        primenum--;
    return primenum;

}
//Straightforward Segmented Sieve
//Be careful about storing the primes first, not marking the
//primes themselves as composite
int main()
{
    int tc,cas=0;
    sfi(tc);
    presv();

    while(tc--)
    {
        ll a,b;
        sfll(a,b);

        ll ans = sv(a,b);

        CASE(cas);
        pf("%lld\n",ans);
    }
    return 0;
}
