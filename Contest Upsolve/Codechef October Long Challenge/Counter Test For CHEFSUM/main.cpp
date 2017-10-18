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
int wrongSolver(std::vector <unsigned int> a)
{
    int n = a.size();
    std::vector<unsigned int> prefSum(n), sufSum(n);
    prefSum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefSum[i] = prefSum[i - 1] + a[i];
    }
    sufSum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sufSum[i] = sufSum[i + 1] + a[i];
    }
    unsigned int mn = prefSum[0] + sufSum[0];
    int where = 1;

    //cout<<"<> "<<prefSum[0]<<" "<<sufSum[0]<<endl;
    //cout<<mn<<" ! ";
    for (int i = 1; i < n; i++)
    {
        unsigned int val = prefSum[i] + sufSum[i];
        if(i==1 || i==2 || i==n-3)
        {
            //cout<<val<<" ! ";
        }
        if (val < mn)
        {
            mn = val;
            where = i + 1;
        }
    }
    return where;
}

int wrongSolver2(std::vector <unsigned int> a)
{
    int n = a.size();
    std::vector<ll> prefSum(n), sufSum(n);
    prefSum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefSum[i] = prefSum[i - 1] + a[i];
    }
    sufSum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sufSum[i] = sufSum[i + 1] + a[i];
    }
    ll mn = prefSum[0] + sufSum[0];
    int where = 1;

    //cout<<"<> "<<prefSum[0]<<" "<<sufSum[0]<<endl;
    //cout<<mn<<" ! ";
    for (int i = 1; i < n; i++)
    {
        ll val = prefSum[i] + sufSum[i];
        if(i==1 || i==2 || i==n-3)
        {
            //cout<<val<<" ! ";
        }
        if (val < mn)
        {
            mn = val;
            where = i + 1;
        }
    }
    return where;
}
int ans[100005];
int main()
{
    //cout<<INT_MAX<<endl;

    //write();

    int tc;
    sfi(tc);

    while(tc--)
    {
        vector<unsigned int>tryme;
        int n;
        sfi(n);
        int cnt = 0;

        unsigned int s2 = 0;

        ll sum = ((ll)1<<32) - 10;
        //cout<<sum<<endl;

        ans[1] = 10;

        s2+=10;

        //tryme.pb(10);

        sum-=11;



        int avg = (sum)/(n-12);

        for(int i=2; i<n-9; i++)
        {
            ans[i] = avg;
            sum-=avg;
            s2+=avg;
            //tryme.pb(avg);
        }

        ans[n-9] = sum;

        s2+=sum;

        for(int j=n; j>=n-10; j--)
        {
            ans[j] = 1;

            s2+=1;

            //tryme.pb(1);
        }
        ll sp = 0;
        for(int i=n;i>=2;i--)
        {
            sp+=ans[i];
        }

        ll req = (((ll)1<<32) - 20) - sp;

        //cout<<req<<endl;

        ans[99990] += req;

        //cout<<s2<<endl;

        int flg = 0;

        for(int i=1;i<=n;i++)
        {
            tryme.pb(ans[i]);
            if(ans[i]>100000)
            {
                cout<<"TOO BIG"<<endl;
            }
        }

        //cout<<ans[n-9]<<endl;

        //cout<<wrongSolver(tryme)<<" vs "<<wrongSolver2(tryme)<<endl;

        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;

        tryme.clear();



    }

    return 0;
}
