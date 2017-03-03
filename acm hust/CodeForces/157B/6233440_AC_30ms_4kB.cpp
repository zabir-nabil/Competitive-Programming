

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

#define sful(a) scanf("%llu",&a);

#define sfulul(a,b) scanf("%llu %llu",&a,&b);

#define sful2(a,b) scanf("%llu %llu",&a,&b); // A little different

#define sfc(a) scanf("%c",&a);

#define sfs(a) scanf("%s",a);


#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define cCASE(t) cout<<"Case "<<++t<<": ";

#define INF 1000000000   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

using namespace std;
/*
IDEA:
Just take the radius , sort .
And start adding areas of the disc +=2
*/
vector<int>radius;
int main()
{
    int N;
    sfi(N);
    loop(i,1,N)
    {
        int tmp;
        sfi(tmp);
        radius.pb(tmp);
    }
    radius.pb(0); //The center //for generalization in code
    sort(all(radius));

    double area = 0.00000000;
    if(N%2==1)
    for(int i=1;i<=SZ(radius)-1;i+=2)
    {
        int curRad = radius[i];
        int lastRad = radius[i-1];
        area+=PI*(sqr(curRad)*1.0000 - sqr(lastRad)*1.0000) ;
    }
    else
    for(int i=2;i<=SZ(radius)-1;i+=2)
    {
        int curRad = radius[i];
        int lastRad = radius[i-1];
        area+=PI*(sqr(curRad)*1.0000 - sqr(lastRad)*1.0000) ;
    }

    pf("%.9lf\n",area);

    return 0;
}
