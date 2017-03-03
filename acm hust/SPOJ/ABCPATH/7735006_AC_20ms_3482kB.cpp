
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
char grid[55][55];
bool vis[55][55];
int dx[]= {0,0,1,-1,1,-1,1,-1};
int dy[]= {1,-1,0,0,1,1,-1,-1};
int dis[55][55];
int h,w;
int valid(int x,int y)
{
    if(x<1 || x>h || y<1 || y>w)
        return 0;
    return 1;
}
int bfs(int sr,int sc)
{
    int mx = 0;
    ms(vis,false);

    paii s = mp(sr,sc);
    queue< paii >q;
    q.push(s);
    vis[s.fs][s.sc]=1;
    dis[s.fs][s.sc]=0;
    while(!q.empty())
    {
        paii u = q.front();
        q.pop();
        for(int i=0; i<8; i++)
        {
            if(valid(u.fs+dx[i],u.sc+dy[i]))
            {
                if(grid[u.fs+dx[i]][u.sc+dy[i]]
                        - grid[u.fs][u.sc]==1)
                {
                    paii v = mp(u.fs+dx[i],
                                u.sc+dy[i]);
                    if(vis[v.fs][v.sc]==0)
                    {
                        vis[v.fs][v.sc]=1;
                        dis[v.fs][v.sc]=
                            dis[u.fs][u.sc]+1;
                        q.push(v);
                        mx = max(mx,dis[v.fs][v.sc]);

                    }
                }
            }
        }
    }
    return mx;

}
int main()
{
    int cas = 0;

    while(scanf("%d %d",&h,&w)==2)
    {

        if(h==0 && w==0)
            break;

        ms(dis,0);

        loop(i,1,h)
        {
            loop(j,1,w)
            {
                cin>>grid[i][j];
            }
        }
        int ans = 0;
        int cnt = 0;
        loop(i,1,h)
        {
            loop(j,1,w)
            {
                if(grid[i][j]=='A')
                {
                    cnt++;
                    int bal = bfs(i,j);
                    ans=max(ans, bal);
                }
            }
        }

        if(cnt!=0)
        {
            ans++;
        }
        CASE(cas);
        pf("%d\n",ans);

    }




    return 0;
}
