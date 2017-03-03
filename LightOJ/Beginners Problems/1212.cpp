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
 
#define CASE(t) printf("Case %d:\n",++t) // t initialized 0
 
#define cCASE(t) cout<<"Case "<<++t<<": ";
 
#define D(v,status) cout<<status<<" "<<v<<endl;
 
#define INF 1000000000   //10e9
 
#define EPS 1e-9
 
#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )
 
#define CONTEST 1
using namespace std;
 
int main()
{
 
    int tc,cas  = 0;
    //write();
    sfi(tc);
    while(tc--)
    {
        CASE(cas);
        int n,m;
        sfii(n,m);
        deque<int>dq;
        loop(i,1,m)
        {
            string cmd;
            cin>>cmd;
            if(cmd=="pushLeft")
            {
                int x;
                sfi(x);
 
                if(dq.size()==n)
                {
                    pf("The queue is full\n");
 
                }
                else
                {
                    dq.push_front(x);
                    pf("Pushed in left: %d\n",x);
                }
 
            }
            else if(cmd=="pushRight")
            {
                int x;
                sfi(x);
 
                if(dq.size()==n)
                {
                    pf("The queue is full\n");
 
                }
                else
                {
                    dq.push_back(x);
                    pf("Pushed in right: %d\n",x);
                }
            }
            else if(cmd=="popLeft")
            {
                if(dq.empty())
                {
                    pf("The queue is empty\n");
                }
                else
                {
                    int x;
                    x = dq.front();
                    dq.pop_front();
                    pf("Popped from left: %d\n",x);
                }
 
            }
            else if(cmd=="popRight")
            {
                if(dq.empty())
                {
                    pf("The queue is empty\n");
                }
                else
                {
                    int x;
                    x = dq.back();
                    dq.pop_back();
                    pf("Popped from right: %d\n",x);
                }
 
            }
        }
 
    }
 
 
 
    return 0;
}