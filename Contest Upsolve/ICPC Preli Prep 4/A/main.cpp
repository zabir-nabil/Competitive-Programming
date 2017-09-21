#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
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

#define osful2(a,b) scanf("%llu %llu",&a,&b); // A little different

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

/*
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

*/
int n,m;
char grid[45][45];
int sx,sy;
int vis[45][45];
//1 U 2 D 3 L 4 R
int ldfs(int sr,int sc,int lastdir)
{
    if(sr<1 || sr>m || sc<1 || sc>n)
        return 0;
    if(grid[sr][sc]=='#')
        return 0;
    if(grid[sr][sc]=='E')
        return 1;

    if(vis[sr][sc])
        return 0;

    vis[sr][sc] = 1;
    int dis = 0;
    if(lastdir==1)
    {
        dis = 1 + ldfs(sr,sc-1,3);
        dis = 1 + ldfs(sr-1,sc,2);
        dis = 1 + ldfs(sr,sc+1,4);
        dis = 1 + ldfs(sr+1,sc,1);
    }
    else if(lastdir==2)
    {
        dis = 1 + ldfs(sr,sc+1,4);
        dis = 1 + ldfs(sr+1,sc,1);
        dis = 1 + ldfs(sr,sc-1,3);
        dis = 1 + ldfs(sr-1,sc,2);

    }
    else if(lastdir==3)
    {
        dis = 1 + ldfs(sr+1,sc,1);
        dis = 1 + ldfs(sr,sc-1,3);
        dis = 1 + ldfs(sr-1,sc,2);

        dis = 1 + ldfs(sr,sc+1,4);
    }
    else

    {
        dis = 1 + ldfs(sr-1,sc,2);
        dis = 1 + ldfs(sr,sc+1,4);
        dis = 1 + ldfs(sr+1,sc,1);
        dis = 1 + ldfs(sr,sc-1,3);

    }

    return dis;





}

int rdfs(int sr,int sc,int lastdir)
{
    if(sr<1 || sr>m || sc<1 || sc>n)
        return 0;
    if(grid[sr][sc]=='#')
        return 0;
    if(grid[sr][sc]=='E')
        return 1;

    if(vis[sr][sc])
        return 0;

    vis[sr][sc] = 1;
    int dis = 0;
    if(lastdir==1)
    {
        dis = 1 + ldfs(sr,sc+1,4);
        dis = 1 + ldfs(sr-1,sc,2);
        dis = 1 + ldfs(sr,sc-1,3);


        dis = 1 + ldfs(sr+1,sc,1);
    }
    else if(lastdir==2)
    {
        dis = 1 + ldfs(sr,sc-1,3);
        dis = 1 + ldfs(sr+1,sc,1);
        dis = 1 + ldfs(sr,sc+1,4);


        dis = 1 + ldfs(sr-1,sc,2);

    }
    else if(lastdir==3)
    {
        dis = 1 + ldfs(sr-1,sc,2);
        dis = 1 + ldfs(sr,sc-1,3);
        dis = 1 + ldfs(sr+1,sc,1);



        dis = 1 + ldfs(sr,sc+1,4);
    }
    else

    {
        dis = 1 + ldfs(sr+1,sc,1);
        dis = 1 + ldfs(sr,sc+1,4);
        dis = 1 + ldfs(sr-1,sc,2);


        dis = 1 + ldfs(sr,sc-1,3);

    }

    return dis;





}
int dx[] = {-1,  0,  1,  0};
int dy[] = { 0, -1,  0,  1};
int dsi[45][45];
int sbfs(int sr,int sc)
{
    queue<pair<int,int> >q;
    q.push(mp(sr,sc));
    dsi[sr][sc] = 0;

    while(!q.empty())
    {
        paii u = q.front();

        vis[u.fs][u.sc] = 1;

        for(int i=0;i<4;i++)
        {
            paii v = mp(u.fs+dx[i],u.sc+dy[i]);
            int vr = v.fs;
            int vc = v.sc;
            if(vr>=1 && vr<=m && vc>=1 &&
               vc<=n && grid[vr][vc]!='#'
               && vis[vr][vc]==0)
            {
                vis[vr][vc] = 1;
                q.push(v);
                dsi[vr][vc] = dsi[u.fs][u.sc]+1;
                if(grid[vr][vc]=='E')
                    return dsi[vr][vc]+1;
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
        sfii(n,m);
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='S')
                {
                    sx = i;
                    sy = j;
                }

            }
        }
        ms(vis,0);

        int ld = ldfs(sx,sy,1);
        cout<<ld<<" ";
        ms(vis,0);
        int rd = rdfs(sx,sy,1);
        cout<<rd<<" ";
        ms(vis,0);
        int sd = sbfs(sx,sy);

        cout<<sd<<endl;



    }

    return 0;
}
