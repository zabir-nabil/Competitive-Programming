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


//Bit Manipulation
bool Check_ON(int mask,int pos) //Check if pos th bit (from right) of mask is ON
{
    if( (mask & (1<<pos) ) == 0  )return false;
    return true;
}
int SET(int mask,int pos) //Save the returned mask into some var //Turn on pos th bit in mask
{
    return (mask | (1<<pos));
}
int RESET(int mask,int pos)  //Save the returned mask into some var //Turn off pos th bit in mask
{
    return (mask & ~(1<<pos));
}
int FLIP(int mask,int pos) //Save the returned mask into some var //Toggle/Flip pos th bit in mask
{
    return (mask ^ (1<<pos));
}
int LSB(int mask) // The actual LSB mask
{
    return (mask & (-mask));
}
int LSB_pos(int mask) // 0 based position
{
    int mask_2 = (mask & (-mask));
    for(int pos = 0; pos<=15; pos++)
    {
        if(Check_ON(mask_2,pos))
            return pos;
    }
    return -1;//
}
int ON_Bits(int mask)
{
    return __builtin_popcount(mask);
}
inline int clz(int N)   // O(1) way to calculate log2(X) (int s only)
{
    return N ? 32 - __builtin_clz(N) : -INF;
}
int n;
int grid_len[1000005];
vector<ll>grid[1000005];
vector<ll>dp[1000005][2];
#define up 0
#define side 1
ll rec(int i,int j,int dir)
{
    if(i==1)
        return 0;

    if(dp[i][j][dir]!=-1)
        return dp[i][j][dir];

    ll mxi = 0;

    if(dir == up){

    ll curv = grid[i][j];

    for(int k=1; k<=grid_len[i-1]; k++)
    {
        ll valg = abs(curv-grid[i-1][k])*(i-1);
        mxi = max(mxi, rec(i-1,k,side) + valg);
    }

    }
    else
    {
if(grid_len[i]==1)
{

}

    }

    return dp[i][j] = mxi;

}
int main()
{
    int tc;

    sfi(tc);

    while(tc--)
    {
        sfi(n);

        for(int i=1; i<=n; i++)
        {
            sfi(grid_len[i]);

            grid[i].pb(0);
            dp[i][0].pb(-1);

            for(int j=1; j<=grid_len[i]; j++)
            {
                ll tpval;
                sfl(tpval);
                grid[i].pb(tpval);
                dp[i][0].pb(-1);
                dp[i][1].pb(-1);
            }
        }

        for(int i=1;i<=n;i++)
        {
            cout<<grid_len[i]<<" ";
        }
        cout<<endl;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=grid_len[i];j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }


        ll ans = 0;

        for(int j=1; j<=grid_len[n]; j++)
        {
            ans = max(ans,rec(n,j,up));
        }


        pf("%lld\n",ans);


    }

    return 0;
}
