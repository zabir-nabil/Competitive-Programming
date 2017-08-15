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
vector<int>prm;
bool isp[1005];
ll prmpow[1005];
ll num[1005];
void sv()
{
    ms(isp,true);
    for(int i=2; i<=1000; i++)
    {
        if(isp[i])
        {
            prm.pb(i);
            for(int j=i*i; j<=1000; j+=i)
            {
                isp[j] = false;
            }
        }
    }

}
ll powi(ll b, ll p)
{
    if(p==0)
        return 1;
    if(p%2)
    {
        ll a1 = powi(b,p/2);
        return a1*b*a1;
    }
    else
    {
        ll a2 = powi(b,p/2);
        return a2*a2;
    }
}
//pattern
int main()
{
    //write();
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        ll a_b;
        sfl(a_b);

        ll res = a_b/90;

        ll a_b2 = a_b + (a_b/10) + res;

        ll a1 = -1,a2 = -1,a3=-1;

        a1 = a_b2;
        a2 = a1+1;
        a3 = a_b2-1;

        int sol = 0;
        vector<ll>ss;
        if(a1-(a1/10)==a_b)
        {
            ss.pb(a1);
        }
        if(a2-(a2/10)==a_b)
        {
            ss.pb(a2);
        }
        if(a3-(a3/10)==a_b)
        {
            ss.pb(a3);
        }
        sort(ss.begin(),ss.end());

        CASE(cas);
        if(SZ(ss)==1)
        {
            pf("%lld\n",ss[0]);
        }
        else
        {
            pf("%lld %lld\n",ss[0],ss[1]);
        }
        ss.clear();

    }
    return 0;
}
