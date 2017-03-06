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
int n;
string start,finish;
map<string,bool>there;
map<string,bool>vis;
map<string,int>dis;
map<string,bool>forbid;
int is_forbid(string s)
{
    if(forbid[s])
        return 1;
    return 0;
}
void forbidden_process()
{
 
    string s1,s2,s3;
    loop(i,1,n)
    {
        cin>>s1>>s2>>s3;
        string madeit = "ass";
        loop(x,0,s1.length()-1)
        {
            loop(y,0,s2.length()-1)
            {
                loop(z,0,s3.length()-1)
                {
                    madeit[0] = s1[x];
                    madeit[1] = s2[y];
                    madeit[2] = s3[z];
                    if(!forbid[madeit])
                    {
 
                        forbid[madeit] = true;
                    }
                }
            }
 
        }
 
    }
 
}
char bef(char c)
{
    if(c=='a')
        return 'z';
    return c-1;
}
char aft(char c)
{
    if(c=='z')
        return 'a';
    return c+1;
}
string gen(string s,int op1,int op2,int op3)
{
    string sendit = s;
    if(op1==1)
    {
        sendit[0] = bef(s[0]);
    }
    else if(op1==2)
    {
        sendit[0] = aft(s[0]);
    }
 
    if(op2==1)
    {
        sendit[1] = bef(s[1]);
    }
    else if(op2==2)
    {
        sendit[1] = aft(s[1]);
    }
 
    if(op3==1)
    {
        sendit[2] = bef(s[2]);
    }
    else if(op3==2)
    {
        sendit[2] = aft(s[2]);
    }
    return sendit;
}
int bfs()
{
 
    if(is_forbid(start) || is_forbid(finish))
        return -1;
 
    if(start==finish)
        return 0;
 
    queue<string>Q;
    Q.push(start);
    vis[start] = 1;
    dis[start] = 0;
 
    while(!Q.empty())
    {
        string u = Q.front();
        Q.pop();
        vis[u] = 1;
        loop(op1,1,2)
        {
            //1 before 2 after
            string v = gen(u,op1,0,0);
 
 
 
            if(v==finish)
                return dis[u] + 1;
            else if(vis[v]==0 &&
                    is_forbid(v)==0)
            {
                Q.push(v);
                vis[v] = 1;
                dis[v] = dis[u] + 1;
            }
        }
        loop(op2,1,2)
        {
            //1 before 2 after
            string v = gen(u,0,op2,0);
 
 
 
            if(v==finish)
                return dis[u] + 1;
            else if(vis[v]==0 &&
                    is_forbid(v)==0)
            {
                Q.push(v);
                vis[v] = 1;
                dis[v] = dis[u] + 1;
            }
 
        }
 
        loop(op3,1,2)
        {
            //1 before 2 after
            string v = gen(u,0,0,op3);
 
 
 
            if(v==finish)
                return dis[u] + 1;
            else if(vis[v]==0 &&
                    is_forbid(v)==0)
            {
                Q.push(v);
                vis[v] = 1;
                dis[v] = dis[u] + 1;
            }
 
        }
 
 
 
 
 
    }
 
 
 
 
    return -1;
 
}
int main()
{
    //write();
 
    int tc,cas = 0;
 
 
    sfi(tc);
    while(tc--)
    {
        cin>>start>>finish;
 
        sfi(n);
        forbidden_process();
        loop(i,0,SZ(forbid)-1)
        {
            // cout<<"--"<<forbid[i]<<"--"<<endl;
        }
        int ans = bfs();
        CASE(cas);
        pf("%d\n",ans);
        there.clear();
        vis.clear();
        dis.clear();
        forbid.clear();
 
    }
 
 
 
    return 0;
}