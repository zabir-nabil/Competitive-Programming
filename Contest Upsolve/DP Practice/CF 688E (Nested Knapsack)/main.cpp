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
int n,k;
int coins[505];
vector<int>pos_x;

short dp[502][502][502];
//Recursive solution TLE
short rec(int i_th_coin, int k_pos, int x_pos)
{

    int i = i_th_coin;

    if(i==n+1 && k_pos==k && x_pos==0)
        return 1;
    if(i==n+1 && k_pos==k && x_pos!=0)
        return 0;
    if(i==n+1 && k_pos!=k)
        return 0;
    if(i==n+1)
        return 0;
    if(k_pos>k)   //This condition is pretty important
        return 0; //If not handled, the value of k_pos will be
    //greater than 500 -> array out of bound error
    if(x_pos<0)
        return 0;

    if(dp[i][k_pos][x_pos]!=-1)
        return dp[i][k_pos][x_pos];



    short p1 = rec(i+1,k_pos,x_pos); // skipping this coin
    short p2 = rec(i+1,k_pos+coins[i],x_pos);
    //taking the current coin to make k (to give arya)
    //but not using this to make a possible x

    //so, k goes to the outer knapsack
    //but, x does n't go to the inner knapsack

    short p3 = rec(i+1,k_pos+coins[i],x_pos-coins[i]);

    //taking the current coin to make k (to give arya)
    //and using this to make a possible x

    //so, k goes to the outer knapsack
    //x goes to the inner knapsack



    return dp[i][k_pos][x_pos] = max(p1,max(p2,p3));

}
int main()
{

    while(cin>>n>>k)
    {
        for(int i=1; i<=n; i++)
        {
            cin>>coins[i];

        }
//pari will give arya k amount, so arya
//can't make any value x > k
//which means, 0 <= x <=k

        dp[0][0][0] = 1;

        for(int i=1;i<=n;i++)
        {
            for(int k_i=0;k_i<=k;k_i++)
            {
                for(int x_i=0;x_i<=k;x_i++)
                {
                    int k_p = (k_i-coins[i]);
                    int x_p = x_i - coins[i];

                    short dp_val = 0;

                    dp_val = dp[i-1][k_i][x_i];

                    if(k_p>=0)
                    {
                        dp_val = max(dp_val,dp[i-1][k_p][x_i]);
                    }
                    if(k_p>=0 && x_p>=0)
                    {
                        dp_val = max(dp_val,dp[i-1][k_p][x_p]);
                    }

                    if(k_p==0 && x_p==0)
                    {
                        //dp_val = 1;
                    }



                    dp[i][k_i][x_i] = dp_val;
                }
            }
        }

        for(int x=k; x>=0; x--)
        {

            short state = dp[n][k][x];
            if(state==1)
            {
                pos_x.pb(x);
            }
        }

        cout<<pos_x.size()<<endl;

        sort(pos_x.begin(),pos_x.end());

        for(int i=0; i<pos_x.size(); i++)
            cout<<pos_x[i]<<" ";
        cout<<endl;


    }


    return 0;
}
