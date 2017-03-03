

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
int mark[100009];
struct dt{
int val;
int idx;
};
deque<dt>mx;
deque<dt>mn;
int main()
{
    int n;
    sfi(n);
    loop(i,1,n)
    sfi(arr[i]);

    int ans = 0;

    int l = 1 , r =1;

    int maxi = arr[1];
    int mini = arr[1];
    dt lak;
    lak.idx =1;
    lak.val = arr[1];
    mx.push_back(lak);
    mn.push_back(lak);
    while(r<=n)
    {


        maxi = mx.front().val;
        mini = mn.front().val;
        if( maxi-mini<=1 )
        {
            ans = max(ans , r - l +1);
        }

        if(maxi-mini>1 && l<r)
        {
            while(!mx.empty() && mx.front().idx<=l)
            {
                mx.pop_front();
            }
            while(!mn.empty() && mn.front().idx<=l)
            {
                mn.pop_front();
            }

            l++;


        }
        else
        {
            r++;
            if(r<=n)
            {
                dt tmp;
                tmp.idx = r;
                tmp.val = arr[r];
                while(!mx.empty() && mx.back().val<arr[r])
                {
                    mx.pop_back();
                }
                mx.push_back(tmp);
                while(!mn.empty() && mn.back().val>arr[r])
                {
                    mn.pop_back();
                }
                mn.push_back(tmp);
            }



        }


    }

    pf("%d\n",ans);

    return 0;
}
