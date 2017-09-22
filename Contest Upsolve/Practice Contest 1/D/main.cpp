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

#define sfs(a) scanf("%s",a)

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

#define INF 100000000000   //10e9

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
int n,m;
unordered_map<string,int>node;
string rev_node[35];
vector<int>adj[35];
vector<double>cost[35];
int vis[35];
int ispos;
void dfs(int root,int cn,double mul)
{
    if(cn==root
            && (mul-1.0000f)>EPS )
    {
        ispos = 1;
        //pf("%.6f\n",mul);
        return;
    }

    if(vis[cn])
        return;

    vis[cn] = 1;

    for(int j=0; j<SZ(adj[cn]); j++)
    {
        int nn = adj[cn][j];
        mul*=1.00000f;
        double cst = cost[cn][j];


        double nmul = (double)mul*(cst*1.000000f);
        dfs(root,nn,nmul);
    }


}
int main()
{
    int cas = 0;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            string ss;
            cin>>ss;
            node[ss] = i;
            rev_node[i] = ss;

        }

        sfi(m);

        for(int i=1; i<=m; i++)
        {
            string a,b;
            double cst;
            cin>>a>>cst>>b;

            int n1 = node[a];
            int n2 = node[b];
            adj[n1].pb(n2);
            //adj[n2].pb(n1);

            cost[n1].pb(cst);
            //cost[n2].pb(n1);

        }
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            ispos = 0;
            ms(vis,0);
            dfs(i,i,1.00000f);

            if(ispos)
            {
                ans = 1;
                //cout<<rev_node[i]<<endl;
                break;
            }

        }

        pf("Case %d: ",++cas);

        if(ans)
            pf("Yes\n");
        else
            pf("No\n");

        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            cost[i].clear();

        }

        node.clear();







    }


    return 0;
}
