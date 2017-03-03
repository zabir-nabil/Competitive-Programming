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
ll fact[25];
 
void init()
{
    fact[0] = 1;
    loop(i,1,19)
    fact[i] = fact[i-1]*(i);
 
 
}
bool taken[20];
int main()
{
    init();
 
    int tc,cas  = 0;
    //write();
    sfi(tc);
    while(tc--)
    {
 
 
        ll N;
        sfl(N);
 
 
        vector<int>probable_sol;
        ms(taken,false);
 
        while(N>0)
        {
            int taken_one = 0;
            for(int fct = 19;fct>=0;fct--)
            {
 
                if(fact[fct]<=N && !taken[fct])
                {
                    probable_sol.pb(fct);
                    N-=fact[fct];
                    taken[fct] = true;
                    taken_one = 1;
                    break;
                }
            }
            if(taken_one==0)
            {
                N = - 10;
                break;
            }
 
        }
        CASE(cas);
 
        if(N==0)
        {
            sort(all(probable_sol));
            pf("%d!",probable_sol[0]);
            loop(i,1,SZ(probable_sol)-1)
            {
 
                int now = probable_sol[i];
                pf("+%d!",now);
            }
            pf("\n");
        }
        else
        {
            pf("impossible\n");
        }
 
 
 
 
 
 
 
 
 
 
    }
 
 
 
    return 0;
}