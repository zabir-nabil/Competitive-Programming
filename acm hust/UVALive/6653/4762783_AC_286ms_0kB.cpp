

/****************************************
Cat Got Bored

*****************************************/

#include <bits/stdc++.h>

#define i64 unsigned long long
#define mod 10000000000007LL

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

#define sf scanf

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

int solve()
{


    return 1;
}



int kk;
struct ant
 {

   int vol;
   double df;

   ant(int vol,double df)
   {
     this->vol = vol;
     this->df = df;
   }
 };

 bool compare(ant i,ant j)
 {

   if(i.df!=j.df)
     return i.df > j.df ; //previous element's age > next element's age in the final vector

   return i.vol > j.vol ; //previous element's rel_position < next element's position in the final vector
 }




i64 nCr(int n, int r)
{
//    init();
  //  dp[0][0] = 1;
 //   dp[0][1] =0;
  for(int a=1;a<=n;a++)
    for(int b=0;b<=a;b++)
  {
i64 ans;
    //  dp[a%2][b] = (dp[(a-1)%2][b-1]%mod + dp[(a-1)%2][b]%mod)%mod;

      if(a==n && b ==r)
      {
       //   ans = dp[a%2][b];
          return ans;
      }
  }
}
i64 fact(int n)
{
    i64 f = (i64)1;
    for(int a=2;a<=n;a++)
    {
        f = (f%mod * a)%mod;  //f = f%mod * a%m
    }

    return f;
}
i64 dp[10004][10004];
void init_nPr()
{
    for(int n=1;n<=1001;n++){
        dp[n][1] = n;
        dp[n][0] = 1;
    }
    for(int n=1;n<=10001;n++)
    {
        for(int r=2;r<=n;r++)
        {
            dp[n][r] = ((dp[n][r-1]%mod)*((n-r+1)%mod));
        }
    }

}
i64 nPr(int n,int r)
{
i64 ans = (i64)1;
    for(int a=1;a<=r;a++)
    {
        ans = (ans%mod * (n--)%mod)%mod;
    }
    return ans;
}

i64 solve_p(int l,int m,int n)
{


    int k = l*l;
    i64 ans = (i64)0;
    for(int a=m;a<=n;a++)
    {


        ans = (ans%mod + nPr(k,a)%mod)%mod;
      //  ans%=mod;
    }
    return ans;
}
i64 solve_final(int l,int m,int n)
{
    int k =l*l;
    i64 sum =(i64)0;
    i64 npr = (i64)1;
    for(int a=k;a>=1;a--)
    {
        npr = ((npr % mod )*(a))%mod;
        if((k-a+1)<=n && (k-a+1)>=m)

        sum = ((sum%mod) +(npr%mod))%mod;
    }

    return sum;
}
int main()
{

int tc,cas = 0 ;
i64 ans ;
gi(tc);

while(tc--)
{

    int L,M,N;
    sf("%d%d%d",&L,&M,&N);
ans = solve_final(L,M,N);
pf("Case %d: %llu\n",++cas,ans);
}

    return 0;
}
