/*
      137.03599913
*/
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cstring>

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

#define getl(s) getline(cin,s);

#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define vi vector<int>

#define vll vector<ll>

#define mii map<int,int>

#define mlli map<ll,int>

#define mib map<int,bool>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define cCASE(t) cout<<"Case "<<++t<<": ";

#define D(v,status) cout<<status<<" "<<v<<endl;

#define INF 1000000000   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

#define CONTEST 1

#define MOD 1000000007

using namespace std;

//Editorial Page : https://github.com/zabir-nabil/Competitive-Programming/tree/master/Contest%20Upsolve/ICPC%20Practice%20Contest%20-%201%20(9.11.2017)

char dig[100005];
ll weight[100005];
ll dig_sum[100005];
ll right_to_left_move_preprocess[100005];
ll left_to_right_move_preprocess[100005];
ll nc2mod(int n)
{
    ll nn = (ll)n;

    ll pp = nn*(nn-1);
    pp/=2;
    pp%=MOD;
    return pp;
}
int n;

int bfarr[100];
void bruteforce()
{
    ll pans = 0;
    string codig = dig;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            string cop = codig;
            reverse(cop.begin()+i-1,cop.begin()+j);

            for(int x=0;x<cop.length();x++)
            {
                pans += (cop[x]-'0')*weight[x+1];
            }

        }

    }

    cout<<pans%MOD<<endl;

}
int main()
{


    while(~scanf("%d",&n))
    {
        sfs(dig);

        weight[n] = 1;

        for(int i=n-1; i>=1; i--)
        {
            weight[i] = (weight[i+1]*10)%MOD;
        }

        for(int i=1; i<=n; i++)
        {
            dig_sum[i] = dig_sum[i-1] +
                         (dig[i-1]-'0');
        }

        right_to_left_move_preprocess[n] = (dig[n-1]-'0');
        right_to_left_move_preprocess[n+1] = 0;
        ll appearance = 2;
        for(int i=n-1; i>=1; i--)
        {
            right_to_left_move_preprocess[i]
                = right_to_left_move_preprocess[i+1]
                  + appearance*(dig[i-1]-'0');
            appearance++;
            right_to_left_move_preprocess[i]%=MOD;
        }

        left_to_right_move_preprocess[1] = (dig[0]-'0');
        appearance = 2;

        for(int i=2; i<=n; i++)
        {
            left_to_right_move_preprocess[i]
                = left_to_right_move_preprocess[i-1]
                  + appearance*(dig[i-1]-'0');
            appearance++;
            right_to_left_move_preprocess[i]%=MOD;
        }

        ll ans = 0;
        for(int i=1; i<=n; i++)
        {
            ll cur_dig = (dig[i-1]-'0');

            //Case 1: The digit stays at its own position

            ll own_pos_freq = nc2mod(i-1) + n + nc2mod(n-i) + min(i-1,n-i);
            own_pos_freq%=MOD;
            ans = (ans + (own_pos_freq*weight[i]*cur_dig)%MOD)%MOD;

            //Case 2: Digits from right positions are moved to current position

            if(i<=(n/2))
            {
                int sym_point = n-i+1;
                ll weighted_dsum = ((dig_sum[sym_point] - dig_sum[i])*weight[i])%MOD;

                ans = (ans + (i*weighted_dsum)%MOD )%MOD;
                ans = (ans + (right_to_left_move_preprocess[sym_point+1]*weight[i])%MOD)%MOD;
            }
            else
            {
                ans = (ans + (right_to_left_move_preprocess[i+1]*weight[i])%MOD)%MOD;
            }

            //Case 3: Digits from left positions are moved to current position

            if(i<=(n/2))
            {
                ans = (ans + (left_to_right_move_preprocess[i-1]*weight[i])%MOD)%MOD;
            }
            else
            {
                int sym_point = n-i+1;
                ll weighted_dsum = ((dig_sum[i-1] - dig_sum[sym_point-1])*weight[i])%MOD;

                ans = (ans + (sym_point*weighted_dsum)%MOD )%MOD;
                ans = (ans + (left_to_right_move_preprocess[sym_point-1]*weight[i])%MOD)%MOD;

            }


        }

        printf("%lld\n",ans);

        //bruteforce();

    }







    return 0;
}
