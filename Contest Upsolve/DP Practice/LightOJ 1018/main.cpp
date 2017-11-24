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
int xx[30];
int yy[30];
int all_line[70000];
int in_one_move_clean[20];
int in_one_move_clean_mask[20];
vector<pair <int,int> >gen;
int n;
int dp[68000][17];
int rec(int mask,int i)
{
    if(i==n && mask==((1<<n)-1))
    {
        return 0;
    }
    if(i==n)
    {
        return INF;
    }
    if(all_line[mask])
        return 1;

    if(dp[mask][i]!=-1)
        return dp[mask][i];


    int mn_pos = INF;

    int mask2 = mask;

    for(int j=0; j<n; j++)
    {
        if(Check_ON(in_one_move_clean_mask[i],j))
        {
            mask2 = SET(mask2,j);
        }
    }

    mn_pos = 1 + min(mn_pos,rec(mask2,i+1));
    mn_pos = min(mn_pos,rec(mask,i+1));

    return dp[mask][i] = mn_pos;

}
int main()
{
    int tc,cas=0;
    sfi(tc);

    while(tc--)
    {

        sfi(n);

        for(int i=1; i<=n; i++)
        {
            int x,y;
            sfii(x,y);
            xx[i] = x;
            yy[i] = y;

        }
        ms(in_one_move_clean,0);

        ms(all_line,false);

        for(int msk=1; msk<=((1<<n)-1); msk++)
        {
            bool possible = true;
            for(int pos=0; pos<n; pos++)
            {
                if(Check_ON(msk,pos))
                {
                    gen.pb(mp(xx[pos+1],yy[pos+1]));
                }
            }

            int dx = (gen[0].first-gen[1].first);
            int dy = (gen[0].second-gen[1].second);

            for(int i=2; i<gen.size(); i++)
            {
                int dx2 = (gen[i-1].first-gen[i].first);
                int dy2 = (gen[i-1].second-gen[i].second);

                if(dx*dy2!=dx2*dy)
                {
                    possible = false;
                    break;
                }

            }

            all_line[msk] = possible;
            int clr = gen.size();
            if(possible)
            for(int pos=0; pos<n; pos++)
            {
                if(Check_ON(msk,pos))
                {
                    if(clr>=in_one_move_clean[pos])
                    {
                        in_one_move_clean[pos] = clr;
                        in_one_move_clean_mask[pos] = msk;
                    }
                }
            }



            gen.clear();
        }

        ms(dp,-1);


        int ans = rec(0,0);

        CASE(cas);

        pf("%d\n",ans);





    }

    return 0;
}
