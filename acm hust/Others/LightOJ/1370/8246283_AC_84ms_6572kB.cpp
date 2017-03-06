
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

#define hdc 5000000
using namespace std;
bool isp[5000007];
void sv()
{

    memset(isp,true,sizeof isp);

    for(ll i=2; i<=hdc; i++)
    {
        if(isp[i])
        {

            for(ll j=(ll)(i*i); j<=hdc; j+=i)
            {
                isp[j]=false;

            }
        }
    }

}

int main()
{
    sv();
//    loop(i,1,20)
//    cout<<isp[i]<<" ";
//    cout<<endl;
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        int n;
        sfi(n);
        ll ans = 0;
        for(int i=1; i<=n; i++)
        {
            int inp;
            sfi(inp);
//            int pos
//                = fuck(inp);//lower_bound(phi,phi+hdc-5,inp) - phi;

            //prime gap is log(n)

            for(ll j=inp+1;j<=hdc;j++)
            {
                if(isp[j])
                {
                   ans+= j;
                   //cout<<j<<" ";
                   break;
                }
            }

            //cout<<endl;

        }

        CASE(cas);
        pf("%lld Xukha\n",ans);
    }


    return 0;
}
