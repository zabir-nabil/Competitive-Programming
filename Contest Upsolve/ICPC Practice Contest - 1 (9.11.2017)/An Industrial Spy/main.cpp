/*
      137.03599913
*/
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <iostream>
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

#define mx 100000005

int prm[(mx/32)+5];
bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos) ;
}
void BWsieve(int N)
{
    int i, j, sqrtN;
    sqrtN = int( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( Check(prm[i>>5],i&31)==0)
        {
            for( j = i*i; j <= N; j += (i<<1) )
            {
                prm[j>>5]=Set(prm[j>>5],j & 31)   ;
            }
        }
    }


}
bool isprime(int input)
{
    if(input==2)
        return true;
    if(input<=1)
        return false;
    /*

    if(input&1)
    {
        if( Check(prm[input>>5],input&31 ) == 0 )
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
    */

    int lmt = sqrt(input);
    for(int dv=2;dv<=lmt;dv++)
    {
        if(input%dv==0)
            return false;
    }
    return true;
}


bool isprime2(int input)
{
    if(input==2)
        return true;
    if(input<=1)
        return false;

    if(input&1)
    {
        if( Check(prm[input>>5],input&31 ) == 0 )
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

set<int>num_prime;
int arr[10];
int sz, rng;
void gen(int mask)
{
    if(mask==rng)
        return;

    vector<int>perm;
    for(int pos=0; pos<sz; pos++)
    {
        if(Check_ON(mask,pos))
        {
            perm.pb(arr[pos+1]);
        }
    }

    sort(perm.begin(),perm.end());

    int p1 = 0;

    do
    {
        int curnum = 0;

        int lsz = perm.size();
        int po = 1;
        for(int ij=lsz-1; ij>=0; ij--)
        {
            curnum += perm[ij]*po;
            po*=10;
        }
        if(isprime(curnum)){
            num_prime.insert(curnum);
            //cout<<curnum<<endl;
        }

    }
    while(next_permutation(perm.begin(),perm.end()));

    perm.clear();

    gen(mask+1);
}

int main()
{

    //BWsieve(1e8);

    //for(int i=1;i<=10;i++)
    //    cout<<i<<" "<<isprime(i)<<endl;

    int tc;
    sfi(tc);

    while(tc--)
    {
        string num;
        cin>>num;
        sz = num.length();
        rng = (1<<sz);
        for(int i=0; i<num.length(); i++)
        {
            arr[i+1] = num[i]-'0';
        }
        gen(1);
        int ans = num_prime.size();

        printf("%d\n",ans);

        num_prime.clear();




    }





    return 0;
}
