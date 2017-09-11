/*
      137.03599913
*/
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <iostream>
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

int n,q;
int balanced_prop[100005];
// ( = -1 & ) = 1 == 0

int tree[4*100005];
void build_tree(int root,int i, int j)
{
    if(i==j)
    {
        //leaf
        tree[root] = balanced_prop[i];
        return;
    }

    int lc = root<<1;
    int rc = lc + 1;
    int mid = (i+j)>>1;
    build_tree(lc,i,mid);
    build_tree(rc,mid+1,j);

    tree[root] = max(tree[lc],tree[rc]);

}
int query(int root,int i,int j,int a,int b)
{
    if(i>b || j<a)
        return -INF;
    if(i>=a && j<=b)
        return tree[root];

    int lc = root<<1;
    int rc = lc + 1;
    int mid = (i+j)>>1;

    int p1 = query(lc,i,mid,a,b);
    int p2 = query(rc,mid+1,j,a,b);

    return max(p1,p2);

}
char paren[100005];
int main()
{

    while(~scanf("%d %d",&n,&q))
    {

        sfs(paren);

        for(int i=0; i<n; i++)
        {
            if(paren[i]=='(')
            {
                balanced_prop[i+1] =
                    balanced_prop[i] - 1;
            }
            else
            {
                balanced_prop[i+1] =
                    balanced_prop[i] + 1;

            }

        }

        build_tree(1,1,n);

        while(q--)
        {

            int x,y;

            sfii(x,y);

            int sx = x+y;
            if(x>y)
            {
                x = min(x,y);
                y = sx-x;
            }
            if(paren[x-1]==')')
            {
                printf("Yes\n");
            }
            else if(paren[y-1]==')' && query(1,1,n,x,y-1)>-2)
            {

                printf("No\n");

            }
            else
            {
                printf("Yes\n");
            }



        }




    }

    return 0;
}
