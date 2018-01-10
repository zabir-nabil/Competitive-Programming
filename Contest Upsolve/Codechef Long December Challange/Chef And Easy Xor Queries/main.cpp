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
ll arr[100005];
ll cx[100005];
struct node
{
    multiset<ll>cumxor;
};
node tree[4*100005];
struct node2
{
    bool updated;
    ll val;
    node2()
    {
        updated = false;
        val = 0;
    }
};
node2 tree2[400005];
void build(int root,int b,int e)
{
    if(b==e)
    {
        tree[root].cumxor.insert(cx[b]);
        return;
    }

    int lefc = root*2;
    int righc = lefc+1;

    int mid = (b+e)/2;

    build(lefc,b,mid);
    build(righc,mid+1,e);


        tree[root].cumxor.insert(tree[lefc].cumxor.begin(),tree[lefc].cumxor.end());
        tree[root].cumxor.insert(tree[righc].cumxor.begin(),tree[righc].cumxor.end());

}
ll query_o(int root,int b,int e,int i)
{
    if(b>i || e<i)
        return 0;
    if(b==e && b==i)
    {
        multiset<ll>::iterator it =
        tree[root].cumxor.begin();
        return (ll)(*it);
    }
        int lefc = root*2;
    int righc = lefc+1;

    int mid = (b+e)/2;

    ll q1 = query_o(lefc,b,mid,i);
    ll q2 = query_o(righc,mid+1,e,i);

    return (q1^q2);
}
int query(int root,int b,int e,int i,ll x)
{
    if(b>i)
    {
        return 0;
    }
    if(e<=i)
    {
        auto lo = lower_bound(tree[root].cumxor.begin(),tree[root].cumxor.end(),x);
        auto hi = upper_bound(tree[root].cumxor.begin(),tree[root].cumxor.end(),x);
        int diff = hi - lo;
        if(diff>=0)
            return diff;
        else
            return 0;
    }
    int lefc = root*2;
    int righc = lefc+1;

    int mid = (b+e)/2;
    int p1 = query(lefc,b,mid,i,x);
    int p2 = query(righc,mid+1,e,i,x);

    return p1+p2;

}

void update(int root,int b,int e,int i,ll x)
{
    if(b>i || e<i)
    {
        return;
    }
    if(b==e && b==i)
    {
        if(!tree2[root].updated)
        {
            tree2[root].val = arr[i]^x;
        }
        else
        {
            tree2[root].val^=x;
        }

        return;
    }
    int lefc = root*2;
    int righc = lefc+1;

    int mid = (b+e)/2;

    update(lefc,b,mid,i,x);
    update(righc,mid+1,e,i,x);

    tree2[root].val = tree2[lefc].val^tree2[righc].val;

}
ll query2(int root,int b,int e,int i)
{
    if(b>i)
        return 0;
    if(e<=i)
    {
        return tree2[root].val;
    }
    int lefc = root*2;
    int righc = lefc+1;

    int mid = (b+e)/2;
    ll p1 = query2(lefc,b,mid,i);
    ll p2 = query2(righc,mid+1,e,i);

    return p1^p2;
}


//1-320,321-640,....

int main()
{
    int n,q;
    sfii(n,q);
    ll xv = 0;
    for(int i=1; i<=n; i++)
    {
        sfl(arr[i]);
        xv = xv^arr[i];
        cx[i] = xv;
    }

    build(1,1,n);

    while(q--)
    {
        int cmd;
        sfi(cmd);
        if(cmd==1)
        {
            int i;
            ll x;
            sfi(i);
            sfl(x);
//update tree
            ll prevx = arr[i];
            prevx ^= x;
            arr[i] = x;
            ll pntq = query_o(1,1,n,i);
            update(1,1,n,i,pntq,x);
        }
        else
        {
            int i;
            sfi(i);
            ll k;
            sfl(k);
//query
            ll nx = query2(1,1,n,i);
            k ^= nx;
//new query

            int qans = query(1,1,n,i,k);

            pf("%d\n",qans);


        }
    }



    return 0;
}
