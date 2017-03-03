

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
//Tricky case : What if actually there are less than
//k unique elements
int arr[5*100009];
int mark[1000009];
int main()
{
    int n,k;
    sfii(n,k);

    int unq = 0;
    loop(i,1,n)
    {
        sfi(arr[i]);
        if(mark[ arr[i] ]==0)
        {
            unq++;
        }
        mark[ arr[i] ]++;
    }

    ms(mark,0);
    int mxseg = 0;

    int ls = 1 , rs = n;



    mark[ arr[1] ] = 1;

    int l = 1, r = 1;

    unq = min(unq,k);
    k = 1;
    while(r<=n)
    {
        if(k==unq)
        {
            int rng = r - l + 1;
            if(rng>=mxseg)
            {
                ls = l; rs = r;
                mxseg = rng;
            }
        }
        if(k>unq && l<r)
        {
            if( mark[ arr[l] ]==1 )
            {
                k--;
                mark[ arr[l] ]--;
                l++;
            }
            else
            {
               mark[ arr[l] ]--;
                l++;
            }


        }
        else
        {
            r++;
            if(r<=n)
            {
                if(mark[ arr[r] ]==0)
                {
                    k++;
                    mark[ arr[r] ]++;

                }
                else
                {
                    mark[ arr[r] ]++;
                }

            }


        }



    }

    pf("%d %d\n",ls,rs);


    return 0;
}
