
/****************************************
              Zerus97
*****************************************/

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


#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

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
//Remove this before submission
#define Nm 20000029
bool mark[20000029+5];
vector<ll>pr;
void sv()
{
    ms(mark,true);
    //I can optimize sieve by avoiding even numbers
    //As I need only odd primes
    for(ll i = 3;i<=Nm;i+=2)
    {
        if(mark[i]==true){
        pr.pb(i);
        for(ll j = i*i;j<=Nm;j+=i)
        {
            mark[j] = false;
        }
        }
    }


}
int OddDivCount(ll N)
{
    int OddDiv = 1;
    loop(x,0,SZ(pr)-1)
    {

        int pw = 0;
        while(N%pr[x]==0)
        {
            N/=pr[x];
            pw++;
        }
        OddDiv*=pw+1;

        ll mxFact = pr[x]*pr[x];
        if(mxFact>N)
            break;
    }
    if(N>1)
        OddDiv*=2;
    return OddDiv;


}
int main()
{
    sv();
    //D(OddDivCount(27),"Odd");
    //write();
    ll N;
    while(scanf("%lld",&N)==1)
    {
        if(N==0)
            break;
        int ans = OddDivCount(4*N-3);

        pf("%lld %d\n",N,ans);




    }







    return 0;
}
