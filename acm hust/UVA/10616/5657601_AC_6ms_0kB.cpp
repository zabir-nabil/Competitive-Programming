

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
int K;int N;int D;
int num[202];
/*
int dp[10009][202][12];
int rec(int sum,int i,int k)
{
    if(k==K && sum%D ==0 && i<N)
        return 1;
    if(i>=N || k>K || sum%D!=0)
        return 0;

    if(dp[sum][i][k]==-1)
        return dp[sum][i][k] = rec(sum + num[i],i+1,k+1) + rec(sum,i+1,k);
    return dp[sum][i][k];
}
*/

ll dp[202][15][22];
bool isSolvedAlready[202][15][22];
//use mod to reduce space
ll rec(int i , int k , int sum )
{
    if(k == K && sum == 0)
    {
             return 1 ;

    }
    if(k==K && sum!=0) return 0;
    if(i >= N || k>K ) return 0;



     if(isSolvedAlready[i][k][sum])
        return  dp[i][k][sum];
     isSolvedAlready[i][k][sum] = true;
        return dp[i][k][sum] = rec(i+1,k+1,((sum + num[i])%D + D)%D ) + rec(i+1,k,sum);
    return dp[i][k][sum];

}
int main()
{
    int Q;
    int SET_no = 1;
    while(cin>>N>>Q){
    if(N==0 && Q==0)break;
    int i;
    cout<<"SET "<<SET_no++<<":"<<endl;
    loop(i,0,N)
    {
        int tmp;
        cin>>tmp;
        num[i] = tmp;
    }

    loop(i,1,Q+1)
    {
        int d,m;
        cin>>d>>m;
        D = d;
        K = m;
        ms(isSolvedAlready,false);
        ll ans = rec(0,0,0);
        cout<<"QUERY "<<i<<": "<<ans<<endl;

    }



    }
    return 0;
}
