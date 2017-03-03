

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


using namespace std;
#define M 2005
bool marked[M];
vector<int>primes;
bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  return marked[n] == false;
}

void sieve(int n) {
  for (int i = 3; i * i <= n; i += 2) {
    if (marked[i] == false) { // i is a prime
      for (int j = i * i; j <= n; j += i + i) {
        marked[j] = true;
      }
    }
  }
}
void init()
{
    sieve(1155);
    for(int a=2;a<=1150;a++)
        if(isPrime(a))primes.pb(a);
}
int amount;int i_max;
int dp[1150][190][15];
int rec(int mon,int i,int how_many_taken)//,int how_many_taken
{
   // cout<<"("<<mon<<" , "<<i<<")";
    if(how_many_taken==i_max && mon == amount && i<190)
        return 1;
    if(i>189 || mon>amount || how_many_taken > i_max )
        return 0;

        if(dp[mon][i][how_many_taken]==-1)
            return dp[mon][i][how_many_taken] = rec(mon+primes[i],i+1,how_many_taken+1) + rec(mon,i+1,how_many_taken);
        return dp[mon][i][how_many_taken];

}
int main()
{
    int i;
    init();
    int n,k;


    while(cin>>n>>k)
    {
        if(n==0 && k==0)break;
        amount = n;
        i_max = k;
        ms(dp,-1);
        int ans = rec(0,0,0);
        cout<<ans<<endl;
    }


    return 0;
}
