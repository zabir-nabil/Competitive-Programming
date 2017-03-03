

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
//#define d double

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

double solve(double x,dd y,dd c,dd d)
{
//dd d_up,d_lo;
//d_lo = 0.0000000f;
//d_up = max(x,y) ;
dd m,n;
m = sqrt(sqr(x) - sqr(d));
n = sqrt(sqr(y) - sqr(d));
dd x1,x2,x3,x4,y1,y2,y3,y4,d_m1,d_m2,x_p,y_p;
x1 = 0.000000000f;
y1 = 0.000000000f;
x2 = d;
y2 = m;
x3 = d;
y3 = 0.0000000000f;
x4 = 0.0000000000f;
y4 = n;
d_m1 = (y2 - y1)/(x2-x1)*1.0000000f;
d_m2 = (y4 - y3)/(x4-x3)*1.0000000f;
x_p = (-d_m2*x3 + y3 + d_m1*x1 - y1)/(d_m1 - d_m2)*1.000000000f;
y_p = d_m2*x_p - (d_m2*x3 - y3);//cae


    return y_p;
}
int main()
{

    int tc,cas = 0 ;
    dd ans ;
    gi(tc);
    while(tc--)
    {
        dd x,y,c;
        cin>>x>>y>>c;
dd d_up,d_lo;
d_up = min(x,y);
d_lo = 0.0000000000f;
loop(100){

dd d_mid = (d_up+d_lo)/2*1.000000000f ;
      ans = solve(x,y,c,d_mid);
      if(ans>c)
      {
        d_lo =   (d_up+d_lo)/2*1.000000000f ;

      }
      else if(ans<c)
      {
          d_up =  (d_up+d_lo)/2*1.000000000f ;
      }


        }
        pf("Case %d: %.9lf\n",++cas,(d_up));//*1.000000000f);
    }

    return 0;
}
