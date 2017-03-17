#include <bits/stdc++.h>
 
 
#define loop(i,s,e) for(int i = s;i<e;i++) //excluding end point
 
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
 
#define mp make_pair
 
#define paii pair<int, int>
 
#define padd pair<dd, dd>
 
#define pall pair<ll, ll>
 
#define fs first
 
#define sc second
 
#define CASE(t) printf("Case %d: ",++t) // t initialized 0
 
#define INF 1000000000   //10e9
 
#define EPS 1e-9
 
 
using namespace std;
map<int,int>isOn;
//Crazy solution -_-
int main()
{
 
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
int xx = 0;
int N = n;
while(n--)
{
    int tt;
    cin>>tt;
    xx^=tt;
    isOn[tt]++;
}
 
if(xx == 0)
    cout<<"First\n";
else {
        if(N%2==1)
    cout<<"Second\n";
else
    cout<<"First\n";
 
}
}
 
    return 0;
}