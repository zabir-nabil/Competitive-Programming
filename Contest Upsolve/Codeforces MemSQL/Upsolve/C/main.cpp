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
int pie[50];
int bobans,aliceans;
//bob = 1, alice 0
int csum[50];
int n;
/*
void rec(int i,int player)
{
    if(i>=n+1)
        return;
    int curpos = i;
    int mxpos = 0;
    for(int j=i+1; j<=n; j++)
    {
        if(pie[j]>(csum[j-1]-csum[i-1]))
        {
            curpos = j;
            mxpos = max(mxpos,pie[j]);
        }
    }

    if(curpos==i)
    {
        if(player==0)
        {
            aliceans+=pie[i];
            rec(i+1,!player);
        }
        else
        {
            bobans+=pie[i];
            rec(i+1,!player);
        }
    }
    else
    {
        if(player==0)
        {
            aliceans+=pie[curpos];
            bobans+=csum[curpos-1]-csum[i-1];
            rec(curpos+1,!player);
        }
        else
        {
            bobans+=pie[curpos];
            aliceans+=csum[curpos-1]-csum[i-1];
            rec(curpos+1,!player);
        }


    }


}
*/
pair<pair<int,int>,int>cs;
map<pair<pair<int,int>,int>,int>dp;
int rec(int i,int player,int sum)
{
    //cout<<i<<" "<<player<<" "<<sum<<endl;

    cs = mp(mp(i,player),sum);


    if(i==n && player==1)
        return dp[cs] = sum+pie[n];
    else if(i==n && player==0)
        return dp[cs] = sum;

    if(dp[cs])
    {
        return dp[cs];
    }

    if(i==n+1)
    {
        return 0;
    }


    int p1;

    if(player==1)
    {
        int p2 = rec(i+1,0,sum+pie[i]);
        int p3 = rec(i+1,player,sum);
        p1 = max(p2,p3);
    }
    else
    {
        int p2 = rec(i+1,1,sum);
        int p3 = rec(i+1,player,sum+pie[i]);
        p1 = min(p2,p3);
    }

    return dp[cs] = p1;




}
int main()
{

    while(cin>>n)
    {
        bobans = 0;
        aliceans = 0;
        for(int i=1; i<=n; i++)
        {
            cin>>pie[i];
            csum[i] = csum[i-1] + pie[i];
        }

        //ms(dp,-1);


        //rec(1,1);

        //cout<<aliceans<<" "<<bobans<<endl;
        int pp = rec(1,1,0);
        cout<<csum[n]-pp<<" "<<pp<<endl;;

    }
    return 0;
}
