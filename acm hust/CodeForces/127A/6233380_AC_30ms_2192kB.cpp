

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
Simply add all line distance .
Then , time = distance / speed
*/
int main()
{
    int n,k;
    sfii(n,k);

    int lastX,lastY;
    int curX,curY;

    sfii(lastX,lastY);


    double dist_lines = 0.00000000f;


    loop(i,1,n-1)
    {
        sfii(curX,curY);
        double diffX = (curX - lastX)*1.0000000;
        double diffY = (curY - lastY)*1.0000000;
        dist_lines+=hypot(diffX,diffY);
        lastX = curX;
        lastY = curY;
    }

    dist_lines*=(k*1.00000000);

    double time = (dist_lines/50.00000000000);

    pf("%.9lf\n",time);

    return 0;
}
