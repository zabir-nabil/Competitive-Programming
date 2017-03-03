

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
//Got stupid WA because of not taking long long
struct fr{
ll mon;
ll ff;
};
bool compi(fr f1 , fr f2)
{
    if(f1.mon < f2.mon)
        return true;
    return false;
}
fr dat[100009];
int main()
{
    ll n,d;
    sfll(n,d);

    loop(i,1,n)
    {
       ll m,ff;
       sfll(m,ff);
       fr temp;
       temp.ff = ff;
       temp.mon = m;
       dat[i] = temp;
    }
    sort(dat+1,dat+n+1,compi);



    ll ans = 0;
    ll ffsum = dat[1].ff;
    int l = 1 , r = 1;

    while(r<=n)
    {
        ll mxmon = dat[r].mon;
        ll mnmon = dat[l].mon;
        if(mxmon-mnmon<d)
        {
            ans = max(ans,ffsum);
        }
        if(mxmon-mnmon>=d && l<r)
        {
            ffsum-=dat[l].ff;
            l++;
        }
        else
        {
            r++;
            if(r<=n)
            {
                ffsum+=dat[r].ff;
            }
        }


    }

    pf("%lld\n",ans);

    return 0;
}
