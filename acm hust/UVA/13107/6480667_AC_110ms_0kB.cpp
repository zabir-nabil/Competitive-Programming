
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
ll sum2p(ll N)
{
    ll sum = 0;
    ll p = 1;
    while(p<=N)
    {
        sum+=p;
        p*=2;
    }
    return sum;

}
char lola[100009];
int sol[100009];
int mem[1000];
int main()
{

    while(scanf("%s",lola)==1)
    {

        int len = strlen(lola) - 1;
        ms(mem,-1);
        int cnt = 1;
        loop(i,0,len)
        {
            char c = lola[i];
            int msk = c - 'a' +1 ;
            if(mem[msk]==-1)
            {
                sol[i] = cnt;
                mem[msk] = cnt;
                cnt++;
            }
            else
            {
                sol[i] = mem[msk];

            }


        }

        loop(i,0,len)
        {
            int lala = sol[i];
            vector<int>dig;
            while(lala>0)
            {
                dig.pb(lala%10);
                lala/=10;
            }
            for(int i = dig.size()-1;
            i>=0;i--){
            if(dig[i]==2)
                pf("5");
            else if(dig[i]==5)
                pf("2");
            else if(dig[i]==6)
                pf("9");
            else if(dig[i]==9)
                pf("6");
            else
                pf("%d",dig[i]);

            }
        }
        pf("\n");


    }




    return 0;
}
