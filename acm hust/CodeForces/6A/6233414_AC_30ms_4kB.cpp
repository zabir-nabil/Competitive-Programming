

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
A degenerate triangle is the "triangle" formed by
three collinear points. It doesn't look like a
triangle, it looks like a line segment. A parabola
may be thought of as a degenerate ellipse with
one vertex at an infinitely distant point.
______.___________   It's a degenerate triangle As sides are 3 , 5 , 8
3 + 5 = 8
*/
int tri_type(int x,int y,int z)
{
    int mx = max(max(x,y),z);
    int mn_sum = x+y+z - mx;
    if(mn_sum>mx)
    {
        return 1; // good triangle
    }
    else if(mn_sum==mx)
    {
        return 2; // Degenerate triangle
    }
    else
    {
        return 3; //IMPOSSIBLE to construct a triangle
    }

}
int main()
{
    int a,b,c,d;
    sfii(a,b);
    sfii(c,d);
    //4C3 = 4 possible 3 tuples is a possibility for a triangle
    int pos1 = tri_type(a,b,c);
    int pos2 = tri_type(a,b,d);
    int pos3 = tri_type(a,c,d);
    int pos4 = tri_type(c,b,d);
    //First priority triangle 1 > Then Degenerate > Then Impossible

    if(pos1==1 || pos2==1 || pos3==1 || pos4==1)
    {
        cout<<"TRIANGLE"<<endl;
    }
    else if(pos1==2 || pos2==2 || pos3==2 || pos4==2)
    {
        cout<<"SEGMENT"<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
