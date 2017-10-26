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

#define CASE(t) printf("Case %d:\n",++t) // t initialized 0

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
vector< pair<int,int> >adj[502];
int dis[502];
void dijkstra(int s,int d)
{
    priority_queue< pair<int,int> >Q;

    Q.push(mp(s,0));
    dis[s] = 0;

    while(!Q.empty())
    {
        pair<int,int>cn = Q.top();
        int u = cn.fs;
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            pair<int,int>vn = adj[u][i];
            int v = vn.fs;
            int newcost = max(vn.sc,dis[u]);
            //This is a path function
            //and it follows op(a,b) = op(b,a)
            if(newcost<dis[v])
            {
                dis[v] = newcost;
                Q.push(mp(v,dis[v]));
            }
        }


    }




}
int main()
{
    int tc,cas = 0;
    sfi(tc);

    while(tc--)
    {
        int n,m;
        sfii(n,m);

        for(int i=1; i<=m; i++)
        {
            int a,b,w;
            sfii(a,b);
            sfi(w);
            adj[a].pb(mp(b,w));
            adj[b].pb(mp(a,w));
        }
        int t;
        sfi(t);




        CASE(cas);

        for(int i=0; i<=n; i++)
        {
            dis[i] = INF;
        }
        int sd = 0;

        dijkstra(t,sd);



        for(int nod=0; nod<n; nod++)
        {
            if(nod==t)
            {
                pf("0\n");
            }
            else
            {

                if(dis[nod]!=INF)
                    pf("%d\n",dis[nod]);
                else
                    pf("Impossible\n");
            }

        }



        for(int i=0; i<=n; i++)
        {
            adj[i].clear();
        }



    }

    return 0;
}
