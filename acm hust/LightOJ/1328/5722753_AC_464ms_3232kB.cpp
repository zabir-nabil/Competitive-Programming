

/****************************************

Cat Got Bored

*****************************************/

#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<e;i++) //excluding end point

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

#define mod 1000007
using namespace std;
vector<ll>num_list;
int main()
{
    int tc;
    cin>>tc;int cas = 0;
    while(tc--)
    {
        int K,C,N,a_0;
        cin>>K>>C>>N>>a_0;
        num_list.clear();
       num_list.pb(a_0);
        for(int x =1;x<N;x++)
        {
            int tmp = (((K)*(num_list[x-1]))+ C)%mod;//(((K%mod)*(num_list[x-1])%mod)%mod + C%mod)%mod;
            num_list.pb(tmp);
        }
        sort(num_list.rbegin(),num_list.rend());

        //for(int x = 0;x<N;x++)cout<<num_list[x]<<" ";cout<<endl;
        ll sum = 0;
        for(int a = 0;a<N;a++)
        {
            sum+= (N - 2*(a+1) + 1)*num_list[a];
        }
        CASE(cas);
        pf("%lld\n",sum);
        num_list.clear();


    }


    return 0;
}
