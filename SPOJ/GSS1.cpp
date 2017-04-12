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
ll arr[50008];
struct node
{
    ll mxs,
    lfts,rgts,sum;
};
node tree[4*50000];
void build_tree(int root,int b,int e)
{
    if(b==e)
    {
        tree[root].sum = arr[b];
        tree[root].lfts = arr[b];
        tree[root].rgts = arr[b];
        tree[root].mxs = arr[b];
        return;
    }
    int mid = (b+e)/2;

    int lc = root*2;
    int rc = lc+1;

    build_tree(lc,b,mid);
    build_tree(rc,mid+1,e);

    tree[root].sum = tree[lc].sum
                     +tree[rc].sum;
    ll p1 = max(tree[lc].lfts,tree[rc].lfts);
    ll p2 = max(tree[lc].rgts,tree[rc].rgts);
    ll p3 = max(tree[lc].sum,tree[rc].sum);
    ll p4 = max(tree[lc].mxs,tree[rc].mxs);
    ll p5 = tree[root].sum;
    ll p6 = tree[lc].rgts + tree[rc].lfts;

    tree[root].mxs = max({p1,p2,p3,p4,p5,p6});

    tree[root].lfts = max(tree[lc].lfts,
                          tree[lc].sum + tree[rc].lfts  );

    tree[root].rgts = max(tree[rc].rgts,
                          tree[rc].sum + tree[lc].rgts  );
}
node query(int root,int b,int e,int i,int j)
{
    if(b>j || e<i)
    {
        node senti;
        senti.lfts=-INF;
        senti.mxs=-INF;
        senti.rgts=-INF;
        senti.sum=-INF;


        return senti;
    }

    if(b>=i && e<=j)
    {
        return tree[root];
    }
    int mid = (b+e)/2;

    int lc = root*2;
    int rc = lc+1;
    node q1 = query(lc,b,mid,i,j);
    node q2 = query(rc,mid+1,e,i,j);
    node qaa;
    qaa.sum = q1.sum
              +q2.sum;
    ll p1 = max(q1.lfts,q2.lfts);
    ll p2 = max(q1.rgts,q2.rgts);
    ll p3 = max(q1.sum,q2.sum);
    ll p4 = max(q1.mxs,q2.mxs);
    ll p5 = qaa.sum;
    ll p6 = q1.rgts + q2.lfts;

    qaa.mxs = max({p1,p2,p3,p4,p5,p6});

    qaa.lfts = max(q1.lfts,
                   q1.sum + q2.lfts  );

    qaa.rgts = max(q2.rgts,
                   q2.sum + q1.rgts  );

    return qaa;


}
int main()
{
    int n;
    sfi(n);

    loop(i,1,n)
    sfl(arr[i]);

    build_tree(1,1,n);

    int qq;
    sfi(qq);
    while(qq--)
    {
        int ki,kj;
        sfii(ki,kj);
        node qans = query(1,1,n,ki,kj);
        ll ans = max({qans.lfts,qans.mxs,qans.rgts,qans.sum});
        pf("%lld\n",ans);


    }


    return 0;
}