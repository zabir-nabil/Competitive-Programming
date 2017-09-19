#include<bits/stdc++.h>


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

#define osful2(a,b) scanf("%llu %llu",&a,&b); // A little different

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
int n,m;
paii xp;
int kgold;
vector< paii >gold;
int dp[17][(1<<15) + 5];
int rec(int i,int mask)
{

    if(dp[i][mask]!=-1)
        return dp[i][mask];

    int cnt = 0;
    int pans = INF;
    paii og = gold[i-1];
    for(int p=0; p<kgold; p++)
    {
        if(!Check_ON(mask,p))
        {
            paii ng = gold[p+1];

            int tans = max(abs(og.first-ng.first),abs(og.second-ng.second));

            if(tans==0)
                continue;

            int mskc = mask;
            int mask2 = SET(mask,p);



            tans += rec(i+1,mask2);
            pans = min(tans,pans);
            cnt++;
        }

    }

    if(cnt==0)
    {
        pans = max(abs(og.first-xp.first),abs(og.second-xp.second));

    }

    cout<<i<<" "<<mask<<" "<<pans<<endl;

    return dp[i][mask] = pans;

}
int val(char c)
{
    if(c=='.' || c=='g' || c=='x')
        return 1;
    return 0;
}
int main()
{
    int tc,cas=0;
    sfi(tc);

    while(tc--)
    {
        kgold = 0;
        sfii(n,m);
        //if(cas==0)
        //getchar();

        paii ranp;
        gold.pb(ranp);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                char cc='5';
                while(!val(cc))
                {
                    sfc(cc);
                }


                if(cc=='x')
                {
                    xp.first = i;
                    xp.second = j;
                    gold[0] = xp;
                }
                else if(cc=='g')
                {
                    paii gp = mp(i,j);
                    gold.pb(gp);
                    kgold++;

                }

            }

        }

//        for(int i=0;i<gold.size();i++)
//            cout<<gold[i].fs<<" "<<gold[i].sc<<endl;
//
//        cout<<kgold<<endl;
        ms(dp,-1);

        int ans = rec(1,0);

        CASE(cas);
        pf("%d\n",ans);

        gold.clear();

    }

    return 0;
}
