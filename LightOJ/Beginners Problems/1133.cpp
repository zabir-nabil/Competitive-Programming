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
 
#define INF 10000000000   //10e9
 
#define EPS 1e-9
 
#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )
 
#define CONTEST 1
using namespace std;
ll arr[107];
ll revarr[107];
int main()
{
    //write();
 
 
    int tc,cas  =0;
    sfi(tc);
 
    while(tc--)
    {
        int n,m;
        sfii(n,m);
        loop(i,1,n)
        sfl(arr[i]);
 
 
        loop(i,1,m)
        {
            char qt;
            cin>>qt;
            int A,B;
            if(qt=='S')
            {
              sfi(A);
              loop(i,1,n)
              {
                  arr[i]+=A;
              }
            }
            else if(qt=='M')
            {
                sfi(A);
                loop(i,1,n)
                {
                    arr[i]*=A;
                }
            }
            else if(qt=='D')
            {
                sfi(A);
                loop(i,1,n)
                {
                    arr[i]/=A;
                }
            }
            else if(qt=='R')
            {
                loop(i,1,n)
                {
                    revarr[n-i+1] = arr[i];
                }
                loop(i,1,n)
                {
                    arr[i] = revarr[i];
                }
            }
            else if(qt=='P')
            {
                sfii(A,B);
                A++;
                B++;
                ll tmp = arr[A];
                arr[A] = arr[B];
                arr[B] = tmp;
            }
 
            //cout<<arr[8]<<endl;
            //Caused some problems for mixing up ll
            //and int
 
        }
 
        CASE(cas);
        loop(i,1,n-1)
        {
            pf("%d ",arr[i]);
        }
        pf("%d\n",arr[n]);
 
 
    }
 
    return 0;
}