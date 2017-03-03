

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

char sss[55];char ccc[55];char xxx[55];

int lenS,lenC,lenX;
int dp[55][55][55];
int max3(int x,int y,int z)
{
    if(x>=y && x>=z)
        return x;


    if(y>=x && y>=z)
        return y;

    if(z>=y && z>=x)
        return z;
}
int max4(int x,int y,int z,int alu)
{
    if(x>=y && x>=z && x>=alu)
        return x;


    if(y>=x && y>=z && y>=alu)
        return y;

    if(z>=y && z>=x && z>=alu)
        return z;

    return alu;
}
int rec(int i,int j,int k)
{

    if(i>=lenS || j>=lenC || k >= lenX) return 0;

    if(dp[i][j][k] == -1){


    if(sss[i] == ccc[j] && sss[i] == xxx[k])
       dp[i][j][k] = max4 (  rec(i+1,j+1,k+1) + 1 , rec(i+1,j,k) ,rec(i,j+1,k) ,rec(i,j,k+1)     ) ;
    else
        dp[i][j][k] = max3( rec(i+1,j,k) ,rec(i,j+1,k) ,rec(i,j,k+1) ) ;


    }

    return dp[i][j][k] ;
}
int main()
{
int t;int cas = 0;
sfi(t);
while(t--)
{
   scanf("%s",sss);  scanf("%s",ccc);  scanf("%s",xxx);

   lenS = strlen(sss);  lenC = strlen(ccc);   lenX = strlen(xxx);

   ms(dp,-1);
    int ans = rec(0,0,0);
    CASE(cas);
    pf("%d\n",ans);

}

    return 0;
}
