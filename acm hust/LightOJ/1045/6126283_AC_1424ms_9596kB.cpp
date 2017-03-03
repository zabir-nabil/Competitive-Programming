

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

double arrsum[1000009];
int main()
{

    int tc;
    cin>>tc;int cas = 0;
       arrsum[0] = 0.00;
    loop(x,1,1000008)
    {
        arrsum[x]+=log10(x) + arrsum[x-1];
    }

    while(tc--)
    {



    int a,b;
    cin>>a>>b;
    CASE(cas);
    ull ans = ceil(arrsum[a]/log10(b)*1.00);
    if(a==0)
    {
        ans = 1;
    }

    cout<<ans<<endl;



    }

    return 0;
}
/*
using namespace std;
//m 10 n 10
int arr[10];
int m,n;
int rec(int i,int len)
{
    if(i>=m)
        return 0;
        if(len==n+1)
        return 1;

    if(i==0)
    {
        if((arr[1] - arr[0])>2)
            return 0;
    }
    if((arr[i] - arr[i-1])>2)
        return 0;
    if((arr[i+1] - arr[i])>2)
        return 0;

    int ans = rec(i+1,len) + rec(i+1,len+1) + rec(i,len);

    return ans;




}
int main()
{
    int tc;
    int cas = 0;
    while(tc--){

    sfii(m,n);
    loop(x,0,m-1)
    {
        sfi(arr[x]);
    }
    //sort(arr,arr+m);
    CASE(cas);
    int ans = rec(0,0);
    pf("%d\n",ans);
    }
    return 0;
}
*/
