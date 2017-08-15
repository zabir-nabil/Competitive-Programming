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
//Bitwise Sieve
#define mx 10000005
/*
n = p1^a1*p2^a2*p3^a3..
lets say,
x = p1^x1*p2^x2*p3^x3..
y = p1^y1*p2^y2*p3^y3..

Now, a1 = max(x1,y1) [definition of LCM]

So, at least one of x1,y1 must be = a1.

Now, how many ways we can pair up the p1?

Lets work with an example,
n = 3^2*2^1 = 18

Pairings of 3 =>
(x),(y)
3^2,1
3^2,3
3^2,3^2
1,3^2
3,3^2
possible ways = 2*2+1 = 5 = 2*(a1+1) - 1(3^2,3^2 can't be repeated)

Pairings of 2 =>
(x),(y)
2,1
1,2
2,2
possible ways = 2*1+1 = 3 = 2*(a2+1) - 1(2^1,2^1 can't be repeated)

Now, when we combine these two sets

we get,

18,1
9,2
18,2
------
18,3
9,6
18,6
------
18,9
9,18
18,18
------
2,9
1,18
2,18
------
18,3
9,6
18,6
------
We observe that, in the list every tuple appears
twice except (18,18). And we want to find
the number of pairs, so we add 1 (only one (18,18) tuple)
to make all tuples appear twice.
Then, ans = the number of tuples/2

*/

int prm[(mx/32)+5];
vector<int>prmls;
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos) ;}
void BWsieve()
{
	 int i, j;
     prmls.pb(2);
     for( i = 3; i <= 10000000; i += 2 )
     {
		 if( Check(prm[i>>5],i&31)==0)
		 {
		     prmls.pb(i);
		     if(i<=3165)
	 		 for( j = i*i; j <= 10000000; j += (i<<1) )
			 {
				 prm[j>>5]=Set(prm[j>>5],j & 31)   ;
	 		 }
		 }
	 }


}
int main()
{
    int tc,cas=0;
    sfi(tc);
    BWsieve();

    while(tc--)
    {
        ll n;
        sfl(n);
        ll ans = 1;
        ll sq = sqrt(n)+1;
        for(int i=0; i<prmls.size()
                && prmls[i]<=sq; i++)
        {

            ll cnt = 0;
            while(n%prmls[i]==0)
            {
                cnt++;
                n/=prmls[i];
            }
            sq = sqrt(n);
            ans*=(2*cnt+1);
        }
        if(n>1)
        {
            ans*=3;
        }
        ans++;
        ans/=2;
        CASE(cas);
        pf("%lld\n",ans);
    }
    return 0;
}
