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
int n;
struct node
{
    int next_n, cap, rev_idx;
    node()
    {

    }
    node(int n,int c,int r)
    {
        next_n = n;
        cap = c;
        rev_idx = r;
    }
};
vector<node>adj[450];
node path[450];
int max_flow;
bool vis[450];
void edmonds_carp(int s,int t)
{
    while(1)
    {
        ms(vis,false);

        queue< pair<int,int> >Q;
        Q.push(mp(s,-1));
        vis[s] = 1;
        bool done = false;
        while(!Q.empty() && !done)
        {

            paii un = Q.front();
            int u = un.fs;
            int p = un.sc;
            Q.pop();

            for(int i=0; i<adj[u].size(); i++)
            {
                node vn = adj[u][i];
                int v = vn.next_n;
                int cap = vn.cap;
                if(!vis[v] &&
                        v!=p &&
                        cap>0)
                {
                    node pare(u,cap,i);
                    path[v] = pare;
                    vis[v] = 1;
                    Q.push(mp(v,u));
                }

                if(v==t)
                {
                    done = true;
                    break;
                }
            }

        }

        while(!Q.empty())
        {
            Q.pop();
        }

        if(!done)
            break;


        int cn = t;
        int min_path_cost = INF;
        while(cn!=s)
        {
            node par = path[cn];
            min_path_cost = min(min_path_cost,
                                par.cap);
            cn = par.next_n;

        }

        cn = t;

        if(min_path_cost<=0)
            break;

        while(cn!=s)
        {
            node par = path[cn];
            int u = par.next_n;
            int cap = par.cap;
            int idx = par.rev_idx;
            adj[u][idx].cap -= min_path_cost;
            int rev_i = adj[u][idx].rev_idx;
            adj[cn][rev_i].cap += min_path_cost;
            cn = par.next_n;

        }
        max_flow += min_path_cost;


    }


}
int main()
{
    //write();
    int tc,cas=0;
    sfi(tc);
    bool oka = false;
    while(tc--)
    {
        //++cas;
        if(cas==40)
        {
            //oka = true;
        }
        else
        {
            oka = false;
        }

        sfi(n);
        if(oka)
            cout<<n<<endl;
        for(int i=1; i<=n; i++)
        {
            int cp;
            sfi(cp);
            if(oka)
                cout<<cp<<" ";
            int ii = i+100;
            //node split
            int nn = (200+i); //outward node
            node n(nn,cp,adj[ii].size());
            adj[ii].pb(n);
            node n2(ii,0,adj[nn].size());
            adj[nn].pb(n2);
        }

        if(oka)
            cout<<endl;

        int m;
        sfi(m);
        if(oka)
            cout<<m<<endl;

        while(m--)
        {
            int i,j,c;
            // node split
            sfii(i,j);
            if(oka)
                cout<<i<<" "<<j<<" ";
            i+=200;
            j+=100;
            sfi(c);
            if(oka)
                cout<<c<<endl;
            int szi = adj[j].size();
            int szj = adj[i].size();
            node n(j,c,szj);
            adj[i].pb(n);
            node n2(i,0,szi);
            adj[j].pb(n2);

        }

        int b,d;
        sfii(b,d);

        if(oka)
            cout<<b<<" "<<d<<endl;

        int gs = 405;
        int gt = 406;

        while(b--)
        {
            int ss;
            sfi(ss);
            if(oka)
                cout<<ss<<" ";
            ss+=100;
            int szs = adj[ss].size();
            int szg = adj[gs].size();
            node n(ss,INF,szs);
            adj[gs].pb(n);
            node n2(gs,0,szg);
            adj[ss].pb(n2);
        }
        while(d--)
        {
            int tt;
            sfi(tt);
            if(oka)
                cout<<tt<<" "<<endl;
            tt+=200;
            int szt = adj[tt].size();
            int szgt = adj[gt].size();
            node n(gt,INF,szgt);
            adj[tt].pb(n);
            node n2(tt,0,szt);
            adj[gt].pb(n2);
        }
        max_flow = 0;
        edmonds_carp(gs,gt);

        CASE(cas);
        pf("%d\n",max_flow);


        for(int i=0; i<=409; i++)
        {
            adj[i].clear();
        }






    }

    return 0;
}
