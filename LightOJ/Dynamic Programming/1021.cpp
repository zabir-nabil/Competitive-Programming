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
    for(int pos = 0;pos<=15;pos++)
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
inline int clz(int N) { // O(1) way to calculate log2(X) (int s only)
    return N ? 32 - __builtin_clz(N) : -INF;
}

int b,k;
string digl;
int n;
ll dp[(1<<16)+2][21];
int powk[17][17][25];
void prec()
{
    for(int bs=1;bs<=16;bs++)
    {
        for(int md=2;md<=20;md++)
        {
            powk[bs][0][md] = 1;
        }
    }

    for(int bs=0;bs<=16;bs++)
    {
        for(int po=1;po<=16;po++)
        {
            for(int md=1;md<=20;md++)
            {
                powk[bs][po][md]
                = (powk[bs][po-1][md]*bs)%md;
            }
        }
    }

}

int conv(char c)
{
    if(c>='A' && c<='F')
        return (10 + (c-'A'));

    return (c-'0');
}
//Bitmask dp with state compression
/*
states(how_many_selected=16,
       mask=2^16,
       modval=20)
       
       we can remove the first state
       as how_many_selected = num_of_1s
       in mask

pre calculate powers%mod

in line 207, (powk[b][idx-1][k])

(powk[b][i][k]) //DID THIS MISTAKE
//AND DEBUGGED FOR 30 MINS

*/
ll rec(int idx, int taken, int modv)
{
    if(idx==n+1)
    {
        if(modv==0)
           return 1;
        else
            return 0;
    }
    if(dp[taken][modv]!=-1)
        return dp[taken][modv];




    ll p1 = 0;

    for(int i=0;i<n;i++)
    {
        int mask = taken;
        if(!Check_ON(mask,i))
        {
            mask = SET(mask,i);
            int val = (conv(digl[i]))
            *(powk[b][idx-1][k]);
            val%=k;
            int nmod = (modv + val)%k;
            p1 += rec(idx+1,mask,nmod);
        }
    }

    return dp[taken][modv] = p1;

}
int main()
{
    prec();
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
       sfii(b,k);
       cin>>digl;
       n = digl.length();
       ms(dp,-1);
       ll ans = rec(1,0,0);
       CASE(cas);
       pf("%lld\n",ans);
    }



    return 0;
}
