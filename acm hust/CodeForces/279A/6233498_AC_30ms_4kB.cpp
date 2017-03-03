

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
Simulating a spiral is tricky .I simulated this earlier and
had to handle many tricky cases.
Now,I have come up with much easier solution with
only 4 cases .
See the figure in my blog to understand.

*/

int main()
{
    int x,y;
    sfii(x,y);

    int max_layer; //Which layer I'm in actually
    int layer = max(abs(x),abs(y));

    int xp = 1 , xn = 2 , yp = 3 , yn = 4;
    if(x>0 && ( (y>=0 && abs(x)>=abs(y)) || (y<0 && (abs(x) - abs(y))>=2))) // less symmetric side
    {
        max_layer = xp;
    }
    else if(x<0 && (abs(x)>=abs(y))) //much more symmetric side
    {                             //taking advantage of extra handling to make symmetric
        max_layer = xn;
    }
    else if(y>0 && (abs(y)>=abs(x))) // another symmetric side
    {
        max_layer = yp;
    }
    else //less symmetric  side
    {
        max_layer = yn;
    }
    int ans;





    //Another approach


    if(x==0 && y==0)
    {
        ans = 0; //special case
    }
    else if(x>0 && y<=0 && x==abs(y)+1) // another special case
    {
        ans = (layer-1)*4;
    }
    else if(x<0 && y>=0 && abs(x)==y)
    {
        ans = (layer-1)*4 + 2; // safety
    }
    else if(x>0 && y>0 && (x==y))
    {
        ans = (layer-1)*4 + 1;
    }
    else if(x<0 && y<0 && x==y)
    {
        ans = (layer-1)*4 +3;
    }
    else if(max_layer==xp)
    {
        ans = (layer-1)*4 + 1;
    }
    else if(max_layer==yp)
    {
        ans = (layer-1)*4 + 2;
    }
    else if(max_layer==xn)
    {
        ans = (layer-1)*4 + 3;
    }
    else
    {
        ans = (layer-1)*4 + 4;
    }



    pf("%d\n",ans);

    return 0;
}
