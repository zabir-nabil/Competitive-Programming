

/****************************************
Cat Got Bored

*****************************************/

#include <bits/stdc++.h>



#define FOR(i, s, e) for(int i=s; i<e; i++) //excluding end point

#define loop(i, n) for(int i=0; i<n; i++) //n times

#define loop(n)  for(int i=0;i<n;i++) // n times

#define getint(n) scanf("%d", &n)

#define gi(n) scanf("%d",&n) //getint short form

#define pb(a) push_back(a)

#define sqr(x) (x)*(x)

#define CIN ios_base::sync_with_stdio(0); cin.tie(0);

#define ll long long int

#define ull unsigned long long int

#define dd double
#define d double

#define SZ(a) int(a.size())

#define read() freopen("input.txt", "r", stdin)

#define write() freopen("output.txt", "w", stdout)

#define mem(a, v) memset(a, v, sizeof(a))

#define ms(a,b) memset(a, b, sizeof(a))

#define all(v) v.begin(), v.end()

#define pi acos(-1.0)

#define pf printf

#define sfi(a) scanf("%d",&a);

#define sffi(a,b) scanf("%d %d",&a,&b);

#define sfl(a) scanf("%lld",&a);

#define sffl(a,b) scanf("%lld %lld",&a,&b);

#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define fr first

#define sc second

#define getlong(n) scanf("%lld",&n)

#define gl(n) scanf("%lld",&n)

#define CASE(n) printf("Case %d: ",++n)

#define inf 1000000000   //10e9

#define EPS 1e-9

/*
//LOJ test case
int tc,cas = 0 ;
int ans = 0;
gi(tc);
while(tc--)
{
ans = solve();
pf("Case %d: %d\n",++cas,ans);
}
*/

using namespace std;

//Bit operation

int SET(int n,int pos)
{
    return n=n | (1<<pos);
}

int RESET(int n,int pos)
{
    return n=n & ~(1<<pos);
}

int CHECK(int n,int pos)
{
    return (bool) (n & (1<<pos));
}





int bigMod(int n,int power,int MOD)

{

    if(power==0)

        return 1;

    if(power%2==0)

    {

        int ret=bigMod(n,power/2,MOD);

        return ((ret%MOD)*(ret%MOD))%MOD;

    }

    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;

}



int modInverse(int n,int MOD)

{

    return bigMod(n,MOD-2,MOD);

}



int POW(int x, int y)

{

    int res= 1;

    for ( ; y ; )
    {

        if ( (y&1) )
        {

            res*= x;

        }

        x*=x;

        y>>=1;

    }

    return res;

}



int inverse(int x)

{

    dd p=((dd)1.0)/x;

    return (p)+EPS;

}



int gcd(int a, int b)

{

    while(b) b^=a^=b^=a%=b;

    return a;

}



int nP2(int n)

{

    return n*(n-1)/2;

}
double SQR(double x)
{
    return (x*x);
}
int sol_deg2_eqn(double a,double b,double c,double &x1,double &x2)
{
    double det = SQR(b) - 4*a*c;
    if(det<0){
    return 0;
    }


    x1 = (-b + det )/2*a ;
    x1 = (-b - det )/2*a ;
    return 1;
}
/*BIT
/////////
*/
/*
int N = 100005;
int tree[100005];
void update(int idx,int val)
{
    while(idx<=N)
    {
        idx+=val;
        idx+=(idx&-idx);
    }
}
int query(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&-idx);
    }

    return sum;
}

*/
int solve()
{


    return 1;
}
int a,b,c;
ll dp[4005];
ll Mx(ll a,ll b ,ll c)
{
    if(a>=b && a>=c)
        return a;


    if(b>=a && b>=c)
        return b;


    if(c>=b && c>=a)
        return c;


}
ll rec(int n)
{
    if(n==0)
        return 0;
        else if(n<0)
            return -inf;

    if(dp[n]==-1)
    {

        dp[n] = 1 + Mx( rec(n-a),rec(n-b),rec(n-c) );



    }
    return dp[n];

}
int main()
{
int N,A,B,C;
cin>>N>>A>>B>>C;
a= A;
b=B;
c= C;

 for(int a=0;a<N+3;a++)
    dp[a] = -1;
ll ans = rec(N);

cout<<ans<<endl;

    return 0;
}
