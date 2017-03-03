

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
int coins[109];

int dp[109][50009];
int m;

int rec(int i,int W)
{

int pos1 = 0;int pos2 = 0;
    if(i==m)
        return 0;

    else if(W-coins[i]==0)
        return dp[i][W]=W;

    else if(dp[i][W]!=-1)
        return dp[i][W];

    if(W-coins[i]>0)
    {
        pos1=coins[i]+rec(i+1,W-coins[i]);

    }
    pos2=rec(i+1,W);


    return dp[i][W]=max(pos1,pos2);
}
int main()
{

    int T;
    cin>>T;

    while(T--)
    {

        ms(coins,0);
        ms(dp,-1);
        int sub_sum = 0;
        cin>>m;
       // n = m;
        for(int a = 0;a<m;a++)
        {


            cin>>coins[a];
            sub_sum+=coins[a];

        }

        int person1_cum_sum = coins[0];
        int person2_cum_sum = coins[1];
   /*
        if(m<=2)
            cout<<abs(person1_cum_sum - person2_cum_sum)<<endl;
      */


            int mx_dividend = rec(0,sub_sum/2);
            cout<<sub_sum - 2*mx_dividend<<endl;



        }





    return 0;
}
