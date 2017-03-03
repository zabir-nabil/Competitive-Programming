

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
struct memory
{
    int mem;
    int id;
};
memory clients[100002];
bool comp(memory m1,memory m2)
{
    if(m1.mem<m2.mem)
        return true;
    return false;
}
int main()
{
    int N,D;
    sfii(N,D);
    
    int a,b;
    sfii(a,b);

    loop(x,0,N-1)
    {
        int xi,yi;
        scanf("%d %d",&xi,&yi);

        clients[x].mem = xi*a + yi*b;
        clients[x].id = x+1;

    }
 
    

    sort(clients,clients+N,comp);
    

    

    int cnt = 0;

    loop(x,0,N-1)
    {
        if( D >= clients[x].mem  )
        {
            D-=clients[x].mem;
            cnt++;
        }
        else
            break;

    }
    pf("%d\n",cnt);
    loop(x,0,cnt-1)
    {
        int idnow = clients[x].id;
        pf("%d ",idnow);
    }

    pf("\n");






    return 0;
}
