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
int xi[105];
int yi[105];
int n,a,b;
//Some tricky if else s
//Think about all possible orientation
int farea(int p1,int p2)
{
    int area = 0;
    int x1 = xi[p1], x2 = xi[p2],
        y1 = yi[p1], y2 = yi[p2];

    if((x1+x2)<=a && max(y1,y2)<=b)
    {
        area = max(area,(x1*y1)+(x2*y2));
    }
    if((x1+x2)<=b && max(y1,y2)<=a)
    {
        area = max(area,(x1*y1)+(x2*y2));
    }
    if(max(x1,x2)<=a && (y1+y2)<=b)
    {
        area = max(area,(x1*y1)+(x2*y2));
    }
    if(max(x1,x2)<=b && (y1+y2)<=a)
    {
        area = max(area,(x1*y1)+(x2*y2));
    }

    if(max(x1,y2)<=a && (y1+x2)<=b)
    {
        area = max(area,(x1*y1)+(x2*y2));
    }
    if(max(x1,y2)<=b && (y1+x2)<=a)
    {
        area = max(area,(x1*y1)+(x2*y2));
    }

    if(max(y1,x2)<=a && (x1+y2)<=b)
    {
        area = max(area,(x1*y1)+(x2*y2));
    }
    if(max(y1,x2)<=b && (x1+y2)<=a)
    {
        area = max(area,(x1*y1)+(x2*y2));
    }

    return area;
}
int main()
{

    while(cin>>n>>a>>b)
    {
        for(int i=1; i<=n; i++)
        {
            int xt,yt;
            cin>>xt>>yt;
            xi[i] = xt;
            yi[i] = yt;
        }
        int area = 0;
        for(int p1=1; p1<=n; p1++)
        {
            for(int p2=p1+1; p2<=n; p2++)
            {

                area = max(area,farea(p1,p2));
            }
        }

        cout<<area<<endl;

    }

    return 0;
}
