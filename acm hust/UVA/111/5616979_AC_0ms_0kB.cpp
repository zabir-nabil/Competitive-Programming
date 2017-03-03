

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

int ChronOrder[25];
int MainOrder[25] ;
int STOrder[25];
int ST[25];
int LCS[25][25];
int main(){
  int n;
  while( scanf("%d", &n) ==1 ){

    for( int i = 1 ; i <= n ; i++ ){
      scanf("%d", &MainOrder[i]) ;
    }


    for( int i = 1 ; i <= n ; i++ ){
      ChronOrder[MainOrder[i]] = i;
    }


    while( scanf("%d", &STOrder[1]) ==1 ){
      for( int i = 2 ; i <= n ; i++ ){
       scanf("%d", &STOrder[i]);
      }


      for( int i = 1 ; i <= n ; i++ ){
        ST[STOrder[i]] = i;
      }


      for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
          if( ChronOrder[i] == ST[j] ){
            LCS[i][j] = LCS[i-1][j-1] + 1;
          }
          else {
            LCS[i][j] = max( LCS[i][j-1], LCS[i-1][j] );
          }
        }
      }

      printf("%d\n", LCS[n][n]);
    }

  }

  return 0;
}

