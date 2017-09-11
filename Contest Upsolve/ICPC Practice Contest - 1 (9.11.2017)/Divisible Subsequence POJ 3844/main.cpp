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
using namespace std;
int mod_ar[50005];
int mod_pos[1000002];
int main()
{
    int tc;
    sfi(tc);

    while(tc--)
    {
        int d,n;
        sfii(d,n);

        int ans = 0;

        mod_pos[0] = 1;

        for(int i=1;i<=n;i++)
        {

          int tmp;
          sfi(tmp);
          mod_ar[i] = (mod_ar[i-1] + tmp)%d;

          //cout<<mod_ar[i]<<" ";

          ans+=mod_pos[ mod_ar[i] ];

          mod_pos[ mod_ar[i] ]++;

        }
        //cout<<endl;
        printf("%d\n",ans);

        ms(mod_pos,0);



    }

    return 0;
}
