

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
/*
char ss[1000009];
map<char,char>parent;
map<char,char>child;
int main()
{
    int tc;
    sfi(tc);
    while(tc--)
    {
        sfs(ss);
        int len = strlen(ss);

        int R;
        sfi(R);

        for(char c='A';c<='Z';c++)
        {
            parent[c] = c;
            child[c] = c;
        }
        loop(i,1,R)
        {
            char xx , yy ;
            cin>>xx>>yy;

            parent[xx] = yy;
            child[yy] = xx;
            child[parent[yy]] = xx;


        }

        loop(i,0,len-1)
        {
            char aal = ss[i];
            if(aal=='_')
                pf("%c",aal);
            else
            pf("%c",child[aal]);
        }
        pf("\n");
        parent.clear();
        child.clear();






    }

    return 0;
}
*/
int arr[1000];
int main()
{
    int tc;
    sfi(tc);
    while(tc--)
    {
        int F,H,W;
        sfii(F,H);
        sfi(W);

        arr[1] = 0;

        loop(i,2,F+1)
        {
            sfi(arr[i]);
        }

        arr[F+2] = W;

        sort(arr+1,arr+F+3);
        int diff = 999999999;
        loop(i,2,F+2)
        {
            diff = min(diff,arr[i]-arr[i-1]);
        }

        pf("%d\n",diff*H);



    }


    return 0;
}
