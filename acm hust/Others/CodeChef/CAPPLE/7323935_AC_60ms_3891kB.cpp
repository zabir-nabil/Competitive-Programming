
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
//int arr[155];
int brr[155];
int crr[155];
int arr[100009];
int lop[100009];
int main()
{
    int n;
    /*
    while(cin>>n)
    {

        loop(i,1,n)
        cin>>arr[i];

        loop(x,1,n)
        cin>>brr[x];

        loop(x,1,n)
        {
            crr[x] = brr[x] - arr[x];
        }

        sort(crr+1,crr+n+1);

        int k = 0;
        int t = 0;

        for(int x=n;x>=1;x--)
        {
            for(int y=1;y<=n;y++)
            {
                if(x!=y){
                if( (crr[x]>=arr[y]) )
                {
                    crr[x]-=arr[y];
                    brr[x]+=brr[y];
                    brr[y]-=arr[y];
                    t+=crr[y];
                    arr[y] = 0;
                }
                else if(crr[x]>0)
                {
                    crr[y]-=crr[x];

                    brr[x]+=crr[x];
                    brr[y]-=crr[x];
                    t+=crr[x];

                    crr[x]=0;

                }
                }
            }
        }
        int nas = 0;
        loop(i,1,n)
        {
            if(brr[i]!=0)
                nas++;
        }

        cout<<nas<<" "<<t<<endl;


    }

    */


    int tc;
    sfi(tc);
    while(tc--)
    {
        ms(lop,0);
        int n;
        sfi(n);
        int ss = 0;
        loop(i,1,n){
        sfi(arr[i]);
        if(lop[ arr[i] ]==0)
            ss++;
        lop[ arr[i] ]=1;
        }

        cout<<ss<<endl;


    }

    return 0;
}
