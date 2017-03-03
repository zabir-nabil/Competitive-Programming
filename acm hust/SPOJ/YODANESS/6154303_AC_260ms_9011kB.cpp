
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
#define MX_N 30009
ull BIT[MX_N + 5];
map<string,int>ID;
string Yoda[MX_N];
string Ori[MX_N];
void update(int idx,ll val)
{
    while(idx<=MX_N)
    {
        BIT[idx]+=val;
        idx+=(idx&-idx);
    }




}

ull query(int idx)
{
    ull sum =0;
    while(idx>0)
    {

        sum+=BIT[idx];
        idx-=(idx&-idx);

    }

    return sum;

}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int N;
        cin>>N;
        ms(BIT,0);
        loop(x,1,N)
        {

            cin>>Yoda[x];

        }

          loop(x,1,N)
        {

            cin>>Ori[x];

            ID[Ori[x]] = x;

        }
        ull ans = 0;
        for(int x=N;x>=1;x--)
        {
            ull nta = query( ID[Yoda[x] ]  );
            ans+=nta;
            update( ID[ Yoda[x] ] , 1);
        }

        cout<<ans<<endl;





    }



    return 0;
}
