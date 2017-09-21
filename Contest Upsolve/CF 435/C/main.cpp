#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<=e;i++) //including end point

#define pb(a) push_back(a)

#define sqr(x) ((x)*(x))

#define CIN ios_base::sync_with_stdio(0); cin.tie(0);

#define ll long long

#define ull unsigned long long

#define SZ(a) int(a.size())

#define read() freopen("alibaba.in", "r", stdin)

#define write() freopen("alibaba.out", "w", stdout)


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
set< paii >kep;
map<int,int>dtoi;
int di[10005];
int tin[10005];
int del[10005];
int main()
{
    //read();
    //write();

    while(~scanf("%d",&n))
    {
        ms(del,0);
        for(int i=1; i<=n; i++)
        {
            int dis,tm;

            sfii(dis,tm);

            di[i] = dis;
            tin[i] = tm;
            dtoi[ dis ] = i;

            paii p = mp(tm,dis);

            kep.insert(p);

        }


        int lastds = 0;

        paii bg = *(kep.begin());
        lastds = bg.sc;

        kep.erase(bg);
        del[ dtoi[lastds] ] =1;

        int totime = 0;
        int ans = 1;


        for(int j=2; j<=n; j++)
        {
            if(kep.empty())
                break;
            paii cn = *(kep.begin());
            int cd = cn.sc;

            int rt = abs(lastds - cd);

            int ct = cn.fs;

            ct-= totime;

            if(rt>ct)
            {
                ans = 0;
                break;

            }
            else
            {
                int si = dtoi[cd];
                int ei = dtoi[lastds];
                int sm = si+ei;
                si = min(si,ei);
                ei = sm-si;
                for(int ii=si+1; ii<ei; ii++)
                {
                    if(del[ii]==0)
                    {
                        paii dl = mp(tin[ii],di[ii]);
                        kep.erase(dl);
                        del[ii] = 1;

                    }
                }
                kep.erase(cn);

                del[ dtoi[cd] ] = 1;
                totime += rt;
                lastds = cd;
            }

        }

        if(ans)
        {
            pf("%d\n",totime);
        }
        else
        {
            pf("No solution\n");
        }

        kep.clear();

        dtoi.clear();



    }


    return 0;

}
