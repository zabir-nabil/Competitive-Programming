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
struct node_inf
{
    int next_node, cap, rev_edge_idx;
    node_inf(int nn,int c, int r)
    {
        this->next_node = nn;
        this->cap = c;
        this->rev_edge_idx = r;
    }
};
vector<node_inf>adj[105];
int max_flow;
bool vis[105];
pair<int,int>path[105];
void bfs(int s,int t)
{


    while(true)
    {
        ms(vis,false);

        queue<pair<int,int> >Q;
        //the current node and its parent
        //I will never go back to parent

        Q.push(mp(s,-1));
        vis[s] = 1;

        int path_idx = 0;



        bool done = false;

        while(!Q.empty() && !done)
        {
            pair<int,int>un = Q.front();
            Q.pop();
            int u = un.fs;
            int p = un.sc;

            for(int i=0; i<adj[u].size(); i++)
            {
                node_inf vn = adj[u][i];

                if(!vis[vn.next_node]
                        && vn.next_node!=p
                        && vn.cap>0)
                {
                    vis[vn.next_node] = 1;
                    Q.push(mp(vn.next_node,u));
                    path[vn.next_node]
                        = mp(u,i);

                    if(vn.next_node==t)
                    {
                        done = true;
                        break;
                    }
                }
            }






        }

        if(!done)
            break;

        int cn = t;

        int min_path_cap = INF;

        while(cn!=s)
        {
            paii pi = path[cn];

            node_inf te = adj[pi.fs][pi.sc];

            min_path_cap = min(min_path_cap,
                               te.cap);

            cn = pi.fs;

        }

        if(min_path_cap<=0)
        {
            break;
        }

        cn = t;

        while(cn!=s)
        {
            paii pi = path[cn];
            node_inf te = adj[pi.fs][pi.sc];

            adj[pi.fs][pi.sc].cap -= min_path_cap;
            adj[te.next_node][te.rev_edge_idx].cap
            += min_path_cap;
            cn = pi.fs;

        }

        max_flow += min_path_cap;



    }


}
int main()
{
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        int n,s,t,e;
        sfii(n,s);
        sfii(t,e);

        for(int i=1; i<=e; i++)
        {
            int a,b,cap;
            sfii(a,b);
            sfi(cap);
            int sza = adj[a].size();
            int szb = adj[b].size();

            node_inf ni(b,cap,szb);
            node_inf ni2(a,cap,sza);

            adj[a].pb(ni);
            adj[b].pb(ni2);

        }

        max_flow = 0;

        bfs(s,t);

        CASE(cas);
        pf("%d\n",max_flow);

        for(int i=0;i<=n;i++)
        {
            adj[i].clear();
        }

    }

    return 0;
}
