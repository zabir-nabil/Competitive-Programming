

/****************************************

Cat Got Bored

*****************************************/

#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<e;i++) //excluding end point

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

#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define INF 1000000000   //10e9

#define EPS 1e-9

#define mx 1000005
using namespace std;

vector<int>primes;
int prm[(mx/32)+5];

int prmDiv[1000005];

int GCD(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int  N;


bool check(int N,int pos){return (bool)(N & (1<<pos));}
int set_(int N,int pos){	return N=N | (1<<pos) ;}

void BWsieve()
{
	 int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );


     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( check(prm[i>>5],i&31)==0)
		 {

	 		 for( j = i*i; j <= N; j += (i<<1) )
			 {
				 prm[j>>5]=set_(prm[j>>5],j & 31)   ;
	 		 }
		 }
	 }


}


bool isPrime(int X)
{
    if(X&1)
    {
        if(!check(prm[X>>5],X&31))return true;
        return false;
    }
    else
        return false;
}

void primeSave()
{
    
    primes.pb(2);

    for(int x = 2;x<=1000005;x++)
    {
        if(isPrime(x))primes.pb(x);
    }


}
int main()
{
    N = 1000005;

    BWsieve();
    primeSave();




    int XX;
    while(scanf("%d",&XX)==1)
    {
        if(XX==0)break;
     int prmDivC = 0;
     for(int ii = 0;ii<primes.size() && primes[ii]<=XX;ii++)
     {
         if(XX%primes[ii]==0)
            prmDivC++;
     }

     pf("%d : %d\n",XX,prmDivC);
    }

    return 0;
}
