

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
ll arr[10009];
int digitsum[10009];
bool mark[10009];
int main()
{
    ms(mark,false);
    ms(digitsum,0);

    int N;
    sfi(N);
    loop(x,1,N)
    {
        sfl(arr[x]);
        ll curNum = arr[x];
        while(curNum>0)
        {
            digitsum[x]+=curNum%10;
            curNum/=10;
        }
    }
    ll cnt = 0;

    loop(x,1,N)
    {
        for(int y=x+1; y<=N; y++)
        {
            if(mark[x]==false && mark[y]==false)
            {
                int sum1 = digitsum[x];
                int sum2 = digitsum[y];
                if((sum1+sum2)%3==0)
                {
                    cnt++;
                    mark[x] = true;
                    mark[y] = true;

                }

            }


        }

    }

    pf("%lld\n",cnt);



    return 0;
}
