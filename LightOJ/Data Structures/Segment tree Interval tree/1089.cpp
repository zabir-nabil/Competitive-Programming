

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

#define CASE(t) printf("Case %d:\n",++t) // t initialized 0

#define cCASE(t) cout<<"Case "<<++t<<": ";

#define D(v,status) cout<<status<<" "<<v<<endl;

#define INF 1000000000   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

#define CONTEST 1
using namespace std;
int n,q;
struct offline{
int point;
int num_start;
int num_end;
int query;
offline()
{

}
offline(int p,int n_s,int n_e,int q=0)
{
    point = p;
    num_start = n_s;
    num_end = n_e;
    query = q;
}
};
map<int,int>postoidx;
offline goal[150005];

int ofq[500005];

bool cmp(offline a,offline b)
{
    return a.point<b.point;
}
int main()
{

    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        sfii(n,q);

        int idxcnt = 0;

        for(int i=1;i<=n;i++)
        {
           int a,b;
           sfii(a,b);
           if(postoidx[a]==0){

           offline op(a,1,0,0);
           idxcnt++;
           postoidx[a] = idxcnt;
           goal[idxcnt] = op;
           }
           else
           {
               offline op = goal[ postoidx[a] ];
               op.num_start++;
               goal[ postoidx[a] ] = op;

           }


           if(postoidx[b]==0){

           offline op(b,0,1,0);
           idxcnt++;
           postoidx[b] = idxcnt;
           goal[idxcnt] = op;
           }
           else
           {
               offline op = goal[ postoidx[b] ];
               op.num_end++;
               goal[ postoidx[b] ] = op;

           }

        }

        for(int i=1;i<=q;i++)
        {
            int ps;
            sfi(ps);
            ofq[i] = ps;

            if(postoidx[ps]==0)
            {
                offline op(ps,0,0,1);
                idxcnt++;
                postoidx[ps]=idxcnt;

                goal[idxcnt] = op;

            }
            else
            {
                offline op = goal[ postoidx[ps] ];
                op.query=1;
                goal[ postoidx[ps] ] = op;

            }
        }

        sort(goal+1,goal+idxcnt+1,cmp);


        int num_in = 0;
        postoidx.clear();

        for(int i=1;i<=idxcnt;i++)
        {
            offline op = goal[i];

            num_in+=op.num_start;
            if(op.query)
            {
                postoidx[op.point]
                = num_in;
            }

            num_in-=op.num_end;

        }

        CASE(cas);
        for(int i=1;i<=q;i++)
        {
            int qq = ofq[i];
            pf("%d\n",postoidx[qq]);
        }

        postoidx.clear();








    }



    return 0;
}
