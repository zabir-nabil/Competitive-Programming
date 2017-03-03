

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
struct tme{
int st,en;
};
tme evt[100];
int n;
bool cmp(tme t1,tme t2)
{
    if(t1.st==t2.st)
        return t1.en<t2.en;
    return t1.st<t2.st;

}
int dp[100][100];

int rec(int i,int lent)
{
    //cout<<i<<" "<<lent<<endl;
    if(i>=n+1){

        return 0;

    }

    int mans = 0;

    if(dp[i][lent]!=-1)
        return dp[i][lent];

    if(lent<=evt[i].st)
    {
        return dp[i][lent]=max( 1+rec(i+1,evt[i].en)
                   ,rec(i+1,lent) );
    }
    else
    {
        return dp[i][lent]=max(rec(i+1,evt[i].en)
                   ,rec(i+1,lent) );
    }


}
int main()
{
    int tc;
    sfi(tc);
    while(tc--)
    {
        int a,b;
        a=56,b=89;
        int cnt = 0;
        while(a!=0 || b!=0)
        {


            sfii(a,b);
            if(a==0 && b==0)
                break;
            cnt++;
            tme tmp;
            tmp.st = a; tmp.en = b;
            evt[cnt]=tmp;

        }

        n  = cnt;
        //cout<<n<<endl;

        sort(evt+1,evt+n+1,cmp);

       ms(dp,-1);

        int ans = rec(1,-1);

        pf("%d\n",ans);



    }



    return 0;
}
