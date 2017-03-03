

/****************************************
              Zerus97
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
char lak[100009];
int mark[1000];
int main()
{
    int n;
    sfi(n);
    sfs(lak);

    loop(i,0,n-1)
    {
        char aka = lak[i];
        mark[aka] = 1;
    }
    int sols = 0;
    loop(i,1,1000)
    {
        if(mark[i]==1)
            sols++;
    }

    ms(mark,0);

    int k = 1;
    int l = 0 , r = 0;
    mark[ lak[0] ] = 1;
    int ans = INF;
    while(r<n)
    {

        if(k==sols)
        {
            ans = min(ans, r - l + 1 );
        }

        if(k>=sols && l<r)
        {
            if(mark[lak[l] ]==1)
            {
                k--;
                mark[ lak[l] ] -= 1;
                l++;
            }
            else
            {
                mark[ lak[l] ] -= 1;
                l++;

            }
        }
        else
        {

            r++;
            if(r<=n-1)
            {
                if(mark[lak[r]]==0)
                {
                    k++;
                    mark[lak[r]]+=1;

                }
                else
                {
                    mark[lak[r]]+=1;
                }

            }


        }


    }

    pf("%d\n",ans);






    return 0;
}
