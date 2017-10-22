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


//Bit Manipulation
bool Check_ON(int mask,int pos) //Check if pos th bit (from right) of mask is ON
{
    if( (mask & (1<<pos) ) == 0  )return false;
    return true;
}
int SET(int mask,int pos) //Save the returned mask into some var //Turn on pos th bit in mask
{
    return (mask | (1<<pos));
}
int RESET(int mask,int pos)  //Save the returned mask into some var //Turn off pos th bit in mask
{
    return (mask & ~(1<<pos));
}
int FLIP(int mask,int pos) //Save the returned mask into some var //Toggle/Flip pos th bit in mask
{
    return (mask ^ (1<<pos));
}
int LSB(int mask) // The actual LSB mask
{
    return (mask & (-mask));
}
int LSB_pos(int mask) // 0 based position
{
    int mask_2 = (mask & (-mask));
    for(int pos = 0; pos<=15; pos++)
    {
        if(Check_ON(mask_2,pos))
            return pos;
    }
    return -1;//
}
int ON_Bits(int mask)
{
    return __builtin_popcount(mask);
}
inline int clz(int N)   // O(1) way to calculate log2(X) (int s only)
{
    return N ? 32 - __builtin_clz(N) : -INF;
}
vector<int>cyclecost[100005];
vector<int>ccost;
pair<int,int>np[100005];
int mndis(int cyc,int u,int v)
{
    if(u>v)
        swap(u,v);
    int last = cyclecost[cyc].size() - 1;
    return min(cyclecost[cyc][v]
               -cyclecost[cyc][u],
               cyclecost[cyc][last]-
               cyclecost[cyc][v]
               + cyclecost[cyc][u]
              );


}
int main()
{
    int tc;
    sfi(tc);

    while(tc--)
    {
        int n,q;
        sfii(n,q);

        for(int i=1; i<=n; i++)
        {
            int sz;
            sfi(sz);
            cyclecost[i].pb(0);
            cyclecost[i].pb(0);
            for(int j=2; j<=sz+1; j++)
            {
                int tmp;
                sfi(tmp);
                cyclecost[i].pb(tmp+cyclecost[i][j-1]);
            }
        }

        int u,v,w;
        ccost.pb(0);
        ccost.pb(0);
        for(int i=2; i<=n+1; i++)
        {
            sfii(u,v);
            sfi(w);
            //incoming = first
            //outgoing = second
            np[i-1].second = u;
            np[i].first = v;

            if(i==n+1)
            {
                np[i-1].second = u;
                np[1].first = v;
            }

            ccost.pb(w);
        }

        //cout<<"LALA"<<endl;

        for(int i=1; i<=n+1; i++)
        {
            if(i!=n+1)
            {
                ccost[i] += mndis(i,np[i].first,np[i].second);
            }
            ccost[i] += ccost[i-1];
        }

        //cout<<"LALA2"<<endl;


        while(q--)
        {
            int v1,c1,v2,c2;

            sfii(v1,c1);
            sfii(v2,c2);

            if(c1>c2)
            {
                swap(c1,c2);
                swap(v1,v2);
            }

            int p1 = mndis(c1,v1,np[c1].second)
                     + (ccost[c2] - ccost[c1] - mndis(c2,np[c2].fs,np[c2].sc))
                     + mndis(c2,v2,np[c2].first);

            int p2 = mndis(c1,v1,np[c1].first)
                     + (ccost[c1] - mndis(c1,np[c1].fs,np[c1].sc))
                     + mndis(c2,v2,np[c2].second)
                     + (ccost[n+1] - ccost[c2]);


            int ans = min(p1,p2);

            pf("%d\n",ans);



        }


        ccost.clear();

        for(int i=0; i<=n+1; i++)
            cyclecost[i].clear();
    }

    return 0;
}
