

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
int arr[100009];
struct dt
{
    int val;
    int idx;
};
deque<dt>mx;
deque<dt>mn;
int main()
{
    //write();

    int tc,cas = 0;
    sfi(tc);
    while(tc--)
    {
        int n,d;
        sfii(n,d);

        loop(i,1,n)
        sfi(arr[i]);
int ans = 0;
if(d!=1)
        loop(i,1,n)
        {
            dt temp;
            temp.val = arr[i];
            temp.idx = i;
            //mx part
            while(!mx.empty() && mx.back().val<arr[i])
            {
                mx.pop_back();
            }
            mx.push_back(temp);

            while(!mx.empty() && (i-mx.front().idx>=d))
            {
             mx.pop_front();
            }

            //mn part
            while(!mn.empty() && mn.back().val>arr[i])
            {
                mn.pop_back();
            }
            mn.push_back(temp);

            while(!mn.empty() && (i-mn.front().idx>=d))
            {
             mn.pop_front();
            }

            int maxi = mx.front().val;
            int mini = mn.front().val;

            if(i>=d)
            {
                ans = max(ans , abs(maxi-mini));
            }


        }
        CASE(cas);
        pf("%d\n",ans);

        mx.clear();
        mn.clear();

    }




    return 0;
}
