

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
ll power(ll base,ll pw,ll mod)
{
    if (pw == 0)
        return 1;
    ll p12 = power(base, pw/2, mod) % mod;
    p12 = (p12 * p12) % mod;
    if(pw%2==0)
        return p12;
    else
        return ((base%mod)*(p12))%mod;
}

ll modInverse(ll a, ll m)
{

    return power(a, m-2, m);

}

#define mod 1000000007
int n;

struct node{
int r,c,dir;
node(int x,int y,int z)
{
    r=x;c=y;dir=z;
}
//dir 1 U
//dir 2 D
//dir 3 L
//dir 4 R
};
int valid(node nx)
{
    if(nx.r>n || nx.r<1 ||
       nx.c>n || nx.c<1)
        return 0;

    return 1;
}
char grid[205][205];
int vis[205][205][5];
int dis[205][205][5];
int bfs(int rx,int cx,int dirx)
{
    ms(vis,0);
    node sou(rx,cx,dirx);
    queue<node>q;
    q.push(sou);
    while(!q.empty())
    {
        node u = q.front();
        q.pop();
        vis[u.r][u.c][u.dir]=1;
        int r=u.r,c=u.c,dir=u.dir;


        if(r==n && c==n && dir==2)
        {
            return dis[r][c][dir];
        }

        if(dir==1)
        {
            node st1(r-1,c,dir);
            if(valid(st1) && vis[r-1][c][dir]==0
               && grid[r-1][c]!='#')
            {
                q.push(st1);
                vis[r-1][c][dir]=1;
                dis[r-1][c][dir]=
                dis[r][c][dir]+1;
            }
        }

        if(dir==2)
        {
            node st1(r+1,c,dir);
            if(valid(st1) && vis[r+1][c][dir]==0
               && grid[r+1][c]!='#')
            {
                q.push(st1);
                vis[r+1][c][dir]=1;
                dis[r+1][c][dir]=
                dis[r][c][dir]+1;
            }
        }

        if(dir==3)
        {
            node st1(r,c-1,dir);
            if(valid(st1) && vis[r][c-1][dir]==0
               && grid[r][c-1]!='#')
            {
                q.push(st1);
                vis[r][c-1][dir]=1;
                dis[r][c-1][dir]=
                dis[r][c][dir]+1;
            }
        }

        if(dir==4)
        {
            node st1(r,c+1,dir);
            if(valid(st1) && vis[r][c+1][dir]==0
               && grid[r][c+1]!='#')
            {
                q.push(st1);
                vis[r][c+1][dir]=1;
                dis[r][c+1][dir]=
                dis[r][c][dir]+1;
            }
        }

        //rotaion

        if(dir==1)
        {
            node st1(r,c,3);
            if(valid(st1) && vis[r][c][3]==0
               && grid[r][c]!='#')
            {
                q.push(st1);
                vis[r][c][3]=1;
                dis[r][c][3]=
                dis[r][c][dir]+1;
            }
        }


        if(dir==2)
        {
            node st1(r,c,4);
            if(valid(st1) && vis[r][c][4]==0
               && grid[r][c]!='#')
            {
                q.push(st1);
                vis[r][c][4]=1;
                dis[r][c][4]=
                dis[r][c][dir]+1;
            }
        }

        if(dir==3)
        {
            node st1(r,c,2);
            if(valid(st1) && vis[r][c][2]==0
               && grid[r][c]!='#')
            {
                q.push(st1);
                vis[r][c][2]=1;
                dis[r][c][2]=
                dis[r][c][dir]+1;
            }
        }

        if(dir==4)
        {
            node st1(r,c,1);
            if(valid(st1) && vis[r][c][1]==0
               && grid[r][c]!='#')
            {
                q.push(st1);
                vis[r][c][1]=1;
                dis[r][c][1]=
                dis[r][c][dir]+1;
            }
        }



    }

return -1;

}
int main()
{

    sfi(n);

    loop(x,1,n)
    loop(y,1,n)
    cin>>grid[x][y];

    int ans = bfs(1,1,2);
    if(n==1)
        ans=0;
    pf("%d\n",ans);

    return 0;
}
