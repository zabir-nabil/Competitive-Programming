

/****************************************

@_@
Cat Got Bored *_*
#_#
*****************************************/

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



//m 10 n 10
int arr[10];
int m,n;
int rec(int i,int len)
{

    int ans = 0;
    if(i>m)
        return 0;
    if(len==n-1)
        return 1;
    int ans1 = 0;
    loop(x,1,m)
    {
        if(abs(arr[x]-arr[i])<=2)
        {
            ans1+=rec(x,len+1);
        }
    }

    ans = ans1;



    return ans;




}
int main()
{
    int tc;
    cin>>tc;
    int cas = 0;
    while(tc--){

    sfii(m,n);
    ms(arr,-1);
    loop(x,1,m)
    {
        sfi(arr[x]);
    }
    //sort(arr,arr+m);
    CASE(cas);
    ll kans = 0;
    loop(p,1,m){
    kans += rec(p,0);
    }
    pf("%lld\n",kans);
    }
    return 0;
}
