
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
int m,n;
char grid[205][205];
int vis[205][205];
int dis[205][205];
int dirr[]= {0,0,0,1,-1};
int dirc[]= {0,1,-1,0,0};
int isvalid(int r,int c)
{
    if(r>m || r<1 || c>n || c<1)
        return 0;
    return 1;
}
int bfs(int r,int c,int mode)
{
    ms(vis,0);
    ms(dis,0);
    queue< paii >q;

    q.push( mp(r,c) );

    dis[r][c]=0;

    while(!q.empty())
    {
        paii u = q.front();
        q.pop();
        vis[u.fs][u.sc]=1;

        for(int x=0; x<=4; x++)
        {
            int cx = u.fs + dirr[x];
            int cy = u.sc + dirc[x];
            if(grid[cx][cy]=='@' && mode==1)
            {
                return dis[u.fs][u.sc];
            }

            if(grid[cx][cy]=='$' && mode==2)
            {
                return dis[u.fs][u.sc];
            }

            if(isvalid(cx,cy) && vis[cx][cy]==0 && grid[cx][cy]!='#')
            {
                q.push( mp(cx,cy) );
                vis[cx][cy]=1;
                dis[cx][cy]=dis[u.fs][u.sc]+1;
            }
        }




    }

    return INF;




}
int main()
{
    sfii(m,n);

    loop(x,1,m)
    {
        getchar();
        loop(y,1,n)
        {
            scanf("%c",&grid[x][y]);
        }
    }



    int prdis = INF;
    int soldis = INF;
    int cntsol = 0;
    int desx,desy;

    loop(r,1,m)
    {
        loop(c,1,n)
        {
            if(grid[r][c]=='%')
            {
                prdis = bfs(r,c,1);
                soldis = bfs(r,c,2);
                break;
                // cout<<r<<" "<<c<<" prc"<<endl;
            }

        }
    }




    //cout<<prdis<<" "<<soldis<<endl;
    if(soldis>prdis)
    {
        pf("Yes\n");
    }
    else
    {
        pf("No\n");
    }








    return 0;
}
