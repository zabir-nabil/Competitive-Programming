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
/*
a1  a1^a2   a1^a2^a3   a1^a2^a3^a4
 
Lets say answer is a3^a4
 
My target is to for a range,
 
a1^a2^a3^...a^i -> xor with another
a1^a2^...a^j such that we find,
a(i+1)^..a^j is maximized.
 
So, lets keep the cumulative xor sum
in the trie.
and for minimum case, for each cum xor sum
find another possible cum xor sum in trie
(except it) similar bit pattern.
for maximum, find opposite bit pattern.
 
*/
int xors[50002];
struct node
{
    int isapath;
    node* next[2];
    node()
    {
        isapath = 0;
        for(int b=0; b<2; b++)
        {
            next[b] = NULL;
        }
    }
};
string br(int dcr)
{
    string binr = "";
 
    while(dcr>0)
    {
        binr.pb( (dcr%2) + '0' );
        dcr/=2;
    }
    for(int i=0; i<34; i++)
    {
        if(binr.length()>=32)
            break;
 
        binr.pb('0');
    }
 
    reverse(binr.begin(),binr.end());
 
 
 
    return binr;
 
}
void insert(node* root,string br)
{
    node* curn = root;
 
    for(int i=0; i<br.length(); i++)
    {
        if(curn->next[ br[i]-'0' ]==NULL)
        {
            node* newn = new node();
            curn->next[ br[i]-'0' ] = newn;
        }
        curn = curn->next[ br[i]-'0' ];
        curn->isapath++;
 
 
    }
 
}
void remove(node* root,string br)
{
    //cout<<br<<endl;
    node* curn = root;
 
    for(int i=0; i<br.length(); i++)
    {
        if(curn->next[ br[i]-'0' ]==NULL)
        {
            cout<<"TUI SHESH"<<endl;
            return;
        }
        curn = curn->next[ br[i]-'0' ];
        curn->isapath--;
 
 
    }
 
}
int minimize(node* root, string cumx)
{
    node* curn = root;
 
    string solmn="";
 
    for(int i=0; i<cumx.length(); i++)
    {
        if((curn->next[cumx[i]-'0'])
                && curn->next[cumx[i]-'0']->isapath>0)
        {
            solmn.pb('0');
            curn = curn->next[cumx[i]-'0'];
        }
        else
        {
            solmn.pb('1');
            curn = curn->next[1-(cumx[i]-'0')];
        }
 
    }
    int ans = 0;
    int po = 1;
    for(int i=solmn.length()-1; i>=0; i--)
    {
        ans += (solmn[i]-'0')*po;
        po*=2;
 
    }
 
    //solmn.clear();
 
    return ans;
 
 
 
}
int maximize(node* root, string cumx)
{
    node* curn = root;
 
    string solmx="";
 
    for(int i=0; i<cumx.length(); i++)
    {
        if(curn->next[1-(cumx[i]-'0')]
          && curn->next[1-(cumx[i]-'0')]->isapath>0)
        {
            solmx.pb('1');
            curn = curn->next[1-(cumx[i]-'0')];
        }
        else
        {
            solmx.pb('0');
            curn = curn->next[(cumx[i]-'0')];
        }
 
    }
    int ans = 0;
    int po = 1;
    for(int i=solmx.length()-1; i>=0; i--)
    {
        ans += (solmx[i]-'0')*po;
        po*=2;
 
    }
    //solmx.clear();
 
    return ans;
 
 
 
}
void del(node* root)
{
    node* curn = root;
 
    for(int i=0; i<2; i++)
    {
        if(curn->next[i])
        {
            del(curn->next[i]);
        }
    }
 
 
    delete curn;
 
}
int main()
{
    //read();
    //write();
 
    /*
    //3 8 2 6 5
    int lok[] = {3,8,2,6,5};
    int ana = 0;
    int li,hi;
    for(int i=0; i<5; i++)
    {
        for(int j=i; j<5; j++)
        {
            int xotans = 0;
            for(int x=i; x<=j; x++)
            {
                xotans^=lok[x];
            }
            if(xotans>ana)
            {
                ana = xotans;
                li = i;
                hi = j;
            }
        }
    }
 
    cout<<ana<<" "<<li<<" "<<hi<<endl;
 
    */
    int tc,cas = 0;
    sfi(tc);
 
    while(tc--)
    {
        node* root = new node();
        int n;
        sfi(n);
        int xorsum = 0;
 
        int mxans = 0;
        int mnans = INF;
 
        for(int i=1; i<=n; i++)
        {
            int cnum;
            sfi(cnum);
            xorsum^=cnum;
            xors[i] = xorsum;
            string localbr = br(xors[i]);
 
 
            if(i!=1)
            {
                mxans = max(mxans,maximize(root, localbr));
                mnans = min(mnans,minimize(root, localbr));
 
            }
            mxans = max(mxans, xors[i]);
            mnans = min(mnans, xors[i]);
            insert(root, localbr);
        }
 
 
        CASE(cas);
        pf("%d %d\n",mxans,mnans);
 
        del(root);
 
 
 
    }
 
 
 
    return 0;
}