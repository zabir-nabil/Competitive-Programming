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
vi adjl[200009];
int vamp;
int lycan;
 
int vis[200009];
int col[200009];
vi vertex;
void bipartite(int start)
{
    // vamp 1 lycan 0
 
    vamp = 0;
    lycan = 0;
    queue<int>Q;
    Q.push(start);
    col[start] = 1;   vamp = 1;
    vis[start]  = 1;
 
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u] = 1;
 
        loop(x,0,SZ(adjl[u])-1)
        {
            int cv = adjl[u][x];
            if(vis[cv]==0)
            {
                Q.push(cv);
                col[cv] = 1 - col[u];
                vis[cv]=1;
                if(col[cv]==0)
                    lycan++;
                else
                    vamp++;
            }
        }
 
 
    }
 
}
int main()
{
 
    //write();
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        int n;
        sfi(n);
        int nodeone = 1;
        int vermx = 0;
        loop(i,1,n)
        {
            int u,v;
            sfii(u,v);
 
            vertex.pb(u);
            vertex.pb(v);
 
 
            adjl[u].pb(v);
            adjl[v].pb(u);
            vermx = max(vermx,u);
            vermx = max(vermx,v);
        }
        int ans = 0;
        ms(vis,0);
        loop(x,0,SZ(vertex)-1)
        {
           int cv = vertex[x];
           if(vis[cv]==0)
           {
               bipartite(cv);
               ans+=max(vamp,lycan);
           }
        }
 
 
        CASE(cas);
        pf("%d\n",ans);
        loop(i,0,vermx+1)
        {
            adjl[i].clear();
        }
        vertex.clear();
 
 
 
 
    }
 
 
 
 
 
    return 0;
}
 