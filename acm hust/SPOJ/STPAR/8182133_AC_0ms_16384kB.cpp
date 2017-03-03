
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
int arr[1005];
vi output;
stack<int>stick;
int main()
{
    int n;
    while(scanf("%d",&n)==1){

    if(n==0)
    break;

    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        while(!stick.empty() && stick.top()==cnt+1)
        {
            output.pb(stick.top());
            stick.pop();
            cnt++;
        }
        sfi(arr[i]);
        if(arr[i]==cnt+1)
        {
            output.pb(arr[i]);
            cnt++;
        }
        else
            stick.push(arr[i]);
    }

    while(!stick.empty())
    {
        output.pb(stick.top());
        stick.pop();
    }

    int ans = 1;

    for(int i=0;i<n;i++)
    {
        if(output[i]!=i+1)
        {
            ans = 0;
            break;
        }
    }

    if(ans)
        pf("yes\n");
    else
        pf("no\n");
    output.clear();

    }

    return 0;
}
