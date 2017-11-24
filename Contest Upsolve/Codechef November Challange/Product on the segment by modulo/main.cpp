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
ll n,p,q;
ll ar[1000005];
ll br[400005];
ll tree[5*1000005];
ll cummal[1000005];
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

ll modinv(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);

    // m is added to handle negative x
    ll res = (x%m + m) % m;
    return res;

}
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = ar[b-1];
        return;
    }

    int ln = (node*2);
    int rn = ln+1;

    build(ln,b,(b+e)/2);

    build(rn,(b+e)/2 + 1,e);

    tree[node] = ((tree[ln])*(tree[rn]))%p;


}

ll query(int r, int i,int j,int b,int e)
{
    if(b>j || e<i)
    {
        return 1;
    }
    if(i>=b && j<=e)
    {
        return tree[r];
    }
    int ln = r*2;
    int rn = ln+1;
    ll q1 = query(ln,i,(i+j)/2,b,e);
    ll q2 = query(rn,(i+j)/2 + 1,j,b,e);

    ll q12 = ((q1%p)*(q2%p))%p;

    return q12;

}
ll query2(ll i,ll j)
{
    ll ans = 1;

    for(ll k =i; k<=j; k++)
    {
        ans = ((ans%p)*ar[k])%p;
    }

    return ans;
}
void build2()
{
    cummal[0] = ar[0];
    for(int i=1;i<n;i++)
    {
        cummal[i] =
        ((cummal[i-1])*(ar[i]))%p;
    }
}
ll query3(int li,int ri)
{
    ll fast = cummal[ri];

    if(li!=0)

    fast = fast*modinv(cummal[li-1],p);

    return fast;

}
int main()
{
    int tc;
    sfi(tc);

    while(tc--)
    {
        sfll(n,p);
        sfl(q);

        for(ll i=0; i<n; i++)
        {
            sfl(ar[i]);
        }

        build(1,1,n);

        ll bln = (q/64) + 2;

        for(ll i=0; i<bln; i++)
        {
            sfl(br[i]);
        }

        ll x = 0;
        ll Li,Ri;
        for(ll cq=0; cq<q; cq++)
        {
            if(cq%64==0)
            {
                Li = (br[ cq/64 ] + x)%n;
                Ri = (br[ (cq/64) + 1] + x)%n;


            }
            else
            {
                Li = (Li+x)%n;
                Ri = (Ri+x)%n;
            }

            if(Li>Ri)
            {
                int tmp = Li;
                Li = Ri;
                Ri = Li;
            }

            x = (query(1,1,n,Li+1,Ri+1) + 1)%p;

        }

        pf("%lld\n",x);





    }

    return 0;
}
