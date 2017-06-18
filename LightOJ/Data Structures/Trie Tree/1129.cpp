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
    bool endmarker;
    node* edge[11];
    node()
    {
        endmarker = false;
        for(int i=0; i<11; i++)
        {
            edge[i] = NULL;
        }
    }
 
};
 
int insrt(char *str,node* root)
{
    node* curn = root;
 
    for(int i=0; i<strlen(str); i++)
    {
 
        if(curn->edge[ str[i] - '0' ]==NULL)
        {
            node* newn;
            newn = new node();
            curn->edge[ str[i] - '0' ]
                = newn;
        }
        if(curn!=root && curn->endmarker)
        {
            return -1; //data found with same prefix
        }
        curn = curn->edge[ str[i] - '0' ];
 
    }
 
    curn->endmarker = true;
    for(int i=0;i<11;i++)
    {
        if(curn->edge[i]!=NULL)
            return -1;
    }
    return 1;
 
}
void cleartrie(node *root)
{
    node* curn = root;
 
    for(int i=0;i<11;i++)
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
        int ans = 1;
        char nowip[1000];
        gets(nowip);
        for(int i=1; i<=n; i++)
        {
            //gets(nowip);
            gets(nowip);
            //if(cas==34)
            //cout<<nowip<<endl;
            int status = insrt(nowip, root);
            if(status==-1)
                ans = 0;
        }
        CASE(cas);
        if(ans)
            pf("YES\n");
        else
            pf("NO\n");
 
        cleartrie(root);
 
 
    }
 
 
 
 
    return 0;
}
 