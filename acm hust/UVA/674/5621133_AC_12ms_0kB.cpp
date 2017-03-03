

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
int cubes[6];

ll dp[7500];
 int N;
void DpBU()
{
    dp[0]=1;
    loop(i,0,5)
    {
        loop(j,cubes[i],N)
        {
            dp[j]+=dp[j-cubes[i]];
        }
    }
}

int main()
{
    int i; N = 7500;
   cubes[0] = 50;
   cubes[1] = 25;
   cubes[2] = 10;cubes[3] = 5;cubes[4] = 1;
    int amount;
    ms(dp,0);
        DpBU();
    while(scanf("%d",&amount)!=EOF)
    {

      pf("%lld\n",dp[amount]);
/*
       if(ans==1)
        cout<<"There is only "<<ans<<" way to produce "<<amount<<" cents change."<<endl;
       else

        cout<<"There are "<<ans<<" ways to produce "<<amount<<" cents change."<<endl;


*/

    }


    return 0;
}
