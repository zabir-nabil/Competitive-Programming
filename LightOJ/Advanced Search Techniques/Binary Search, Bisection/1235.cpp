

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

#define INF 1000000009   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

#define CONTEST 1
using namespace std;
int n,k;
int ar[20];
vi lw;
map<int,bool> up;
void genl(int i,int sum)
{
    if(i==(n/2)+1)
    {
        lw.pb(sum);
        return;
    }
    genl(i+1,sum);
    genl(i+1,sum+ar[i]);
    genl(i+1,sum+ar[i]*2);

}
void genu(int i,int sum)
{
    if(i==n+1)
    {
        up[sum]=1;
        return;
    }
    genu(i+1,sum);
    genu(i+1,sum+ar[i]);
    genu(i+1,sum+ar[i]*2);

}
int main()
{
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        int ans = 0;
        sfii(n,k);

        for(int i=1; i<=n; i++)
        {
            sfi(ar[i]);
            if(ar[i]==k || ar[i]*2==k)
            {
                ans=1;
            }
        }

        if(n==1)
        {
            CASE(cas);
            if(ans)
                pf("Yes\n");
            else
                pf("No\n");

            continue;
        }
        else
        {
            genl(1,0);

            genu((n/2)+1,0);

            for(int i=0; i<lw.size(); i++)
            {
                int have = lw[i];

                if(up[ k-have ])
                {
                    ans=1;
                    break;
                }

            }

            CASE(cas);
            if(ans)
                pf("Yes\n");
            else
                pf("No\n");


        }
        lw.clear();
        up.clear();
    }


    return 0;
}
