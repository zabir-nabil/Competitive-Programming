

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

#define INF 9999999999   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

#define CONTEST 1
using namespace std;
int a[2*100009];

struct b{
int v;
int idx;
};
b bb[2*100009];
int bans[2*100009];
bool comp(b cc,b dd)
{
    if(cc.v<dd.v)
        return true;
    return false;
}
int main()
{
    int n,m;
    sfii(n,m);

    loop(i,1,n)
    sfi(a[i]);

    loop(i,1,m)
    {
        int tmp;
        sfi(tmp);
        b lak;
        lak.v = tmp;
        lak.idx = i;
        bb[i] = lak;
    }
    sort(a+1,a+n+1);
    sort(bb+1,bb+m+1,comp);

    a[n+1] = INF;

    int p1 = 0;
    loop(p2,1,m)
    {
        int val = bb[p2].v;
        int ix = bb[p2].idx;

        while( a[p1+1]<=val && p1<=n)
        {
            p1++;
        }

        bans[ix] = p1;

    }




    loop(i,1,m)
    {
        pf("%d ",bans[i]);
    }



    return 0;
}
