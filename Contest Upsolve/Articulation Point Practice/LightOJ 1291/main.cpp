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
vector<int>adj[10005];
bool vis[10005];
int low[10005];
int disc[10005];
int num_art[10005];
int special_art;
int leaf_node;
int gtime;
int leaf[10005];
int dfs(int u,int p)
{
    if(vis[u])
        return leaf[u];


    vis[u] = 1;

    disc[u] = ++gtime;
    low[u] = disc[u];
    int cnt = 0;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == p)
            continue;
        if(vis[v]) //back edge
        {
            low[u] = min(low[u],disc[v]);
        }
        else
        {

            cnt += dfs(v,u);
            low[u] = min(low[u],low[v]);

            if(disc[u]<low[v])
            {
                if()
                {

                }
            }

        }
    }

    if(adj[u].size()==1)
    {
        leaf_node++;
        return leaf[u] = 1;
    }
    else
    {
        return leaf[u] = min(cnt,1);
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
            int u,v;
            sfii(u,v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        ms(vis,0);
        ms(num_art,0);
        ms(leaf,0);

        special_art = 0;
        leaf_node = 0;
        gtime = 0;

        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i,-1);
            }
        }

        CASE(cas);
        pf("%d\n",special_art);


        for(int i=0; i<=n; i++)
        {
            adj[i].clear();
        }




    }

    return 0;
}
