

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
double arr[1000];
bool comp(double val1,double val2)
{
    return true;
}
int main()
{
    arr[0] = 0.0000;
    arr[1] = 0.0000;

    loop(i,2,1000)
    {
        arr[i] = arr[i-1] + (double)(1.00/(i*1.00));
    //    cout<<arr[i]<<endl;
    }

    while(true)
    {


    double in;
    cin>>in;
    if(in==0.00)
        break;

    int ans = 2;
    loop(x,2,999)
    {
        if(arr[x]>=in)
            {
                ans = x-1;
                break;
            }
    }

    pf("%d card(s)\n",ans);
    }

    return 0;
}
