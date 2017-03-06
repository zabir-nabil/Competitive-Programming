
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
bool isp[1000008];
int  prm[1000009];
int sz;
void sv()
{
    ms(isp,true);
    sz = 0;

    for(ll i=2; i<=1000005; i++)
    {
        if(isp[i])
        {
            sz++;
            prm[sz] = i;
            for(ll j=(ll)(i*i); j<=1000005; j+=i)
            {
                isp[j] =false;
            }
        }
    }


}
int main()
{
    sv();
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        ll a,b;
        sfl(a);
        sfl(b);

        ll ans = 1;
        ll sq = (ll)sqrt(a+0.1);
        if(b>sq || b*b==a)
        {
            CASE(cas);
            pf("0\n");
            continue;
        }
        ll ax = a;
        for(int i=1; prm[i]<=sqrt(ax+0.1); i++)
        {
            ll cnt = 0;
            while(ax%prm[i]==0)
            {
                cnt++;
                ax/=prm[i];
            }
            ans*=(cnt+1);
        }

        if(ax!=1)
            ans*=2;

        ans/=2;

        for(ll kl=1;kl<b;kl++)
        {
            if(a%kl==0)
                ans--;
        }




        CASE(cas);

        pf("%lld\n",ans);
    }



    return 0;
}
