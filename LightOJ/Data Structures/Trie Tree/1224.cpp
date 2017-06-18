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
struct node
{
    ll endmarker;
    node* edge[4];
    node()
    {
        endmarker = 0;
        for(int i=0; i<4; i++)
        {
            edge[i] = NULL;
        }
    }
 
};
int convo(char cc)
{
 
    if(cc=='A')
        return 0;
    if(cc=='C')
        return 1;
    if(cc=='G')
        return 2;
    else
        return 3;
}
void insrt(char *str,node* root)
{
    node* curn = root;
 
    for(int i=0; i<strlen(str); i++)
    {
 
        if(curn->edge[ convo(str[i]) ]==NULL)
        {
            node* newn;
            newn = new node();
            curn->edge[ convo(str[i]) ]
                = newn;
        }
 
        curn = curn->edge[ convo(str[i]) ];
        //if(i==strlen(str)-1)
            curn->endmarker++;
 
 
 
    }
 
 
 
}
ll dfs(node* rot,ll lev)
{
    ll score = 0;
    node* curn = rot;
 
    score = lev*curn->endmarker;
 
    for(int i=0;i<4;i++)
    {
        if(curn->edge[i]!=NULL)
        {
            score = max(score,
            dfs(curn->edge[i],lev+1));
        }
    }
 
    return score;
 
 
 
 
}
void cleartrie(node *root)
{
    node* curn = root;
 
    for(int i=0;i<4;i++)
    {
        if(curn->edge[i]!=NULL)
        {
            cleartrie(curn->edge[i]);
        }
    }
    delete (curn);
 
}
int main()
{
    //read();
    //write();
    int tc,cas = 0;
    sfi(tc);
 
    while(tc--)
    {
        node* root;
        root = new node();
        int n;
        sfi(n);
 
        char nowip[100];
        gets(nowip);
        ll ans = 0;
        for(int i=1; i<=n; i++)
        {
 
            gets(nowip);
 
            insrt(nowip, root);
 
        }
        ans = dfs(root,0);
        CASE(cas);
 
        pf("%lld\n",ans);
 
        cleartrie(root);
 
 
    }
 
 
 
 
    return 0;
}
 