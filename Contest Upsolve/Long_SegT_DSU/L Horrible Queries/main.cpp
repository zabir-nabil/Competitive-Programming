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
int n,c;
struct node
{
    ll sum,prop;
    node()
    {
        sum = 0;
        prop = 0;
    }
};
node tree[4*100005];
void update(int root,int b,int e,int i,int j,ll v)
{
    if(b>j || e<i)
    {
        return;
    }
    if(b==e)
    {
       tree[root].sum+=v;
       return;
    }

    if(b>=i && e<=j)
    {
        tree[root].prop += v;
        ll addedsum = (e-b+1)*v;
        tree[root].sum += addedsum;
        return;
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc+1;

    update(lc,b,mid,i,j,v);
    update(rc,mid+1,e,i,j,v);

    tree[root].sum = tree[lc].sum
                     + tree[rc].sum
                     + (e-b+1)*tree[root].prop;

}
ll query(int root,int b,int e,int i,int j,ll qp)
{
    if(b>j || e<i)
    {
        return 0;
    }

    if(b>=i && e<=j)
    {
        ll actual_sum = tree[root].sum;
        ll prop_sum = (e-b+1)*qp;
        return actual_sum + prop_sum;
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc+1;

    ll p1 = query(lc,b,mid,i,j,qp+tree[root].prop);
    ll p2 = query(rc,mid+1,e,i,j,qp+tree[root].prop);

    return p1 + p2;
}
void null_tree()
{
    for(int i=1; i<=400000; i++)
    {
        tree[i].sum = 0;
        tree[i].prop = 0;
    }
}
int main()
{
    int tc;
    sfi(tc);
    while(tc--)
    {

        sfii(n,c);
        null_tree();

        while(c--)
        {
            int cmd;
            sfi(cmd);
            if(cmd==0)
            {
                int p,q;
                sfii(p,q);
                ll v;
                sfl(v);
                update(1,1,n,p,q,v);
            }
            else if(cmd==1)
            {
                int p,q;
                sfii(p,q);
                ll ans = query(1,1,n,p,q,0);
                pf("%lld\n",ans);
            }



        }



    }

    return 0;
}
