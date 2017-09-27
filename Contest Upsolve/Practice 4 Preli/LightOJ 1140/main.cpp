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
string cnum;
int n;

ll rec(int i,bool mx,ll nz)
{
    if(i==n)
    {

        return nz;

    }

    ll p = 0;

    bool leadinz = 0;
    if(i==nz)
    {
        leadinz = 1;
    }

    if(mx)
    {
        if(cnum[i]=='0')
        {
            if(leadinz)
                p+= rec(i+1,mx,0);
            else
                p+=rec(i+1,mx,nz+1);

        }
        else
        {
            if(leadinz)
                p+= rec(i+1,0,0);
            else
                p+=rec(i+1,0,nz+1);

            for(int k=1; k<(cnum[i]-'0'); k++)
            {
                if(leadinz)
                    p+= rec(i+1,0,0);
                else
                    p+=rec(i+1,0,nz);
            }

            if(leadinz)
                p+= rec(i+1,mx,0);
            else
                p+=rec(i+1,mx,nz);


        }

    }
    else
    {
        if(leadinz)
        {
            p+=rec(i+1,0,0);
        }
        else
        {
            p+=rec(i+1,0,nz+1);
        }

        for(int d=1; d<=9; d++)
            p+=rec(i+1,0,nz);
    }

    return p;
}
int main()
{
    int tc,cas=0;
    sfi(tc);

    while(tc--)
    {
        ll pk;
        cin>>pk;
        cnum.clear();
        if(pk==0)
        {
            cnum.pb('0');
        }
        while(pk>0)
        {

            ll dg = pk%10;
            cnum.push_back('0'+dg);
            pk/=10;
        }
        reverse(cnum.begin(),cnum.end());
        n = (cnum).length();

        cout<<cnum<<endl;


        ll a1 = rec(0,1,0);
        a1++;
        cout<<a1<<endl;


        //cin>>cnum;
        n = (cnum).length();

        //ll a2 = rec(0,1,0);

        //cout<<a2<<" "<<a1<<endl;


    }

    return 0;
}
