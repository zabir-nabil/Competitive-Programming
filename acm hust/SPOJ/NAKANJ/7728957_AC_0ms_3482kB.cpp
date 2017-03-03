

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
int dis[10][10];
bool vis[10][10];
int dy[]= {1,2,2,1,-1,-2,-2,-1};
int dx[]= {2,1,-1,-2,-2,-1,1,2};
int valid(paii v)
{
    if(v.fs>8 || v.fs<1
            || v.sc>8 || v.sc<1)
        return 0;
    return 1;
}
int bfs(int sr,int sc,int er,int ec)
{
    paii ss = mp(sr,sc);
    paii dd = mp(er,ec);
    queue<pair<int,int> >q;
    q.push(ss);
    vis[ss.fs][ss.sc] = true;
    dis[ss.fs][ss.sc]=0;
    while(!q.empty())
    {
        paii u = q.front();
        q.pop();

        if(u.fs==er && u.sc==ec)
        {
            return dis[u.fs][u.sc];
        }

        for(int i=0; i<8; i++)
        {
            paii v = mp(u.fs+dx[i],u.sc+dy[i]);



            if(valid(v) && vis[v.fs][v.sc]==0)
            {

                vis[v.fs][v.sc]=1;
                dis[v.fs][v.sc] = dis[u.fs][u.sc]+1;
                q.push(v);
            }
        }


    }


}
int main()
{
    int tc;
    sfi(tc);
    while(tc--)
    {
        ms(vis,false);
        string st,en;
        cin>>st>>en;
        int sr,sc,er,ec;
        sr = st[1] - '0';
        sc = st[0] - 'a' +1;
        er = en[1] - '0';
        ec = en[0] - 'a' +1;

        int ans = bfs(sr,sc,er,ec);
        pf("%d\n",ans);

    }



    return 0;
}
