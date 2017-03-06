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
int W,H;
char grid[25][25];
int vis[25][25];
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int isout(int x,int y)
{
    if(x>=1 && x<=W && y>=1 && y<=H)
        return 0;
    return 1;
}
int dfs(int x,int y)
{
    if(isout(x,y))
        return 0;
    if(vis[x][y])
        return 0;
    if(grid[x][y]=='#')
        return 0;
 
    int partans = 1;
    vis[x][y]  =  1;
 
    loop(i,0,3)
    {
        partans+=dfs(x+fx[i],y+fy[i]);
    }
 
    return partans;
 
 
 
}
int main()
{
 
    //write();
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        sfii(W,H);
        int stX,stY;
        loop(y,1,H)
        {
            loop(x,1,W)
            {
                cin>>grid[x][y];
                if(grid[x][y]=='@')
                {
                    stX = x;
                    stY = y;
                }
            }
        }
        ms(vis,0);
 
        int ans = dfs(stX,stY);
 
        CASE(cas);
        pf("%d\n",ans);
 
 
    }
 
 
 
 
 
    return 0;
}
 