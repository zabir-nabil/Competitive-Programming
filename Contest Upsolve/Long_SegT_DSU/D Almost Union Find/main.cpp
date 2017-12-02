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

int n,m;
int id[200005]; //pointers
int par[200005];
int sz[200005];
ll sum[200005];
int global_id_gen;
void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        id[i] = i; //initially everyone has id = i
        par[i] = id[i]; // we access each element by it's id, not it's id index
        sz[i] = 1;
        sum[i] = i;
    }

    global_id_gen = n;

}
int find_p(int x)
{
//Recursive find_parent gets WA
//    if(par[x]!=x)
//        par[x] = find_p(par[x]);
//
//    return par[x];

    //But Iterative version gets AC

    int root = x;

    while(par[root]!=root)
        root = par[root];

    int cn = x;

    while(cn!=root)
    {
        int curp = par[cn];
        par[cn] = root;
        cn = curp;
    }

    return root;

}
void unio(int p,int q)
{
    int pp = find_p(p);
    int pq = find_p(q);

    if(pp>pq)
    {

        par[pp] = pq;
        sz[pq] += sz[pp];
        sum[pq] += sum[pp];
    }
    else if(pp<pq)
    {
        par[pq] = pp;
        sz[pp] += sz[pq];
        sum[pp] += sum[pq];
    }

}
void replac(int p,int q)
{
    //move p to q
    //first, delete p from it's original set

    //grab p by it's id

    int pp = find_p(id[p]);
    int pq = find_p(id[q]);

    if(pp==pq)
        return;

    sz[pp]--; // p is being deleted
    sum[pp] -= p;

    id[p] = ++global_id_gen; //replace old id with
    //id[global_id_gen] = global_id_gen;
    //update pointer
    int new_node = id[p];
    par[new_node] = new_node;
    sz[new_node] = 1 ;
    sum[new_node] = p;
    unio(new_node,id[q]); //missed id[q]

}
paii szsum(int p)
{
    int pp = find_p(p);

    paii ret = mp(sz[pp],sum[pp]);
    return ret;

}
int main()
{
    //write();

    while(scanf("%d %d",&n,&m)!=EOF)
    {
        global_id_gen = 0;
        init(n);

        while(m--)
        {
            int cmd;
            sfi(cmd);
            if(cmd==1)
            {
                int p,q;
                sfii(p,q);
                p = id[p];
                q = id[q];
                unio(p,q);
            }
            else if(cmd==2)
            {
                int p,q;
                sfii(p,q);
                //p = id[p];
                //q = id[q];
                replac(p,q);
            }
            else
            {
                int p;
                sfi(p);
                p = id[p];
                paii res = szsum(p);
                pf("%d %lld\n",res.fs,res.sc);

            }

        }


    }

    return 0;
}
