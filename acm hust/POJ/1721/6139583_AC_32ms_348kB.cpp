

/****************************************

@_@
Cat Got Bored *_*
#_#
*****************************************/

#include <stdio.h>


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
/*
int l_cards[1009];
int cards[1009];
int temp_cards[1009];
void double_shuffle(int N)
{
    loop(x,1,N)
    {
        int p1 = cards[x];
        int p2 = cards[p1];
        temp_cards[x] = p2;

    }

    loop(x,1,N)
    cards[x] = temp_cards[x];
}
int main()
{
   int N,S;
   sfii(N,S);
   loop(x,1,N)
   sfi(cards[x]);

   //First operation

   //cards[1] = l_cards[N];

   loop(x,2,N)
   {
   //    cards[x] = l_cards[x-1];
   }


   loop(s,1,S)
   {
       double_shuffle(N);
   }


   loop(x,1,N)
   pf("%d\n",cards[x]);





    return 0;
}
*/

const int MAXN=1010;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int n,m;
int min_cycle_length()
{
    int j;
    int cnt=0;
    while(1)
    {
        for(int i=1; i<=n; i++)
            b[i]=c[c[i]];
        cnt++;
        for(j=1; j<=n; j++)
            if(b[j]!=a[j])
                break;
        if(j==n+1)break;

        for(int i=1; i<=n; i++)
            c[i]=b[i];
    }
    return cnt;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            c[i]=a[i];
            b[i]=a[i];
        }
        int cnt=min_cycle_length();
        m%=cnt;
        m=cnt-m;
        while(m--)
        {
            for(int i=1; i<=n; i++)
                b[i]=a[a[i]];
            for(int i=1; i<=n; i++)
                a[i]=b[i];
        }
        for(int i=1; i<=n; i++)
            printf("%d\n",b[i]);
    }
    return 0;
}

