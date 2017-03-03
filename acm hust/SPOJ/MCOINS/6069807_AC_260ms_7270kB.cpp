

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
int K,L,N;
int states[1000009]; //winning or losing state
int winner;//Alice 1 Bob 2
int inv(int turn)
{
    if(turn ==0)
        return 1;
    else
        return 0;
}
int rec(int N,int turn)
{
    if(N<0)
        return 0;

    if( (N-1)<=0 || (N-K)<=0 || (N-L)<=0  )
    {
        return 1;
    }
    if(  rec(N-1,inv(turn)) == 1 || rec(N-1,inv(turn)) == 1
       || rec(N-1,inv(turn)) == 1 )
    {
        winner = inv(turn);
        return inv(turn);
    }
    else

    {
        winner = turn;
        return turn;
    }

}
void looper()
{
    ms(states,0);
    states[0] = 0;
    states[1] = 1;
    states[K] = 1;
    states[L] = 1;

    loop(i,2,N)
    {
        if( (states[i-1]==0) || (i>K && states[i-K]==0) || (i>L && states[i-L]==0) )
        {
            states[i] = 1;
        }

    }



}
int main()
{
     int M;
     sfii(K,L); sfi(M);
     while(M--)
     {


        sfi(N);
        looper();
        if(states[N]==1)
            pf("%c",'A');
        else
            pf("%c",'B');

     }
     pf("\n");

    return 0;
}
