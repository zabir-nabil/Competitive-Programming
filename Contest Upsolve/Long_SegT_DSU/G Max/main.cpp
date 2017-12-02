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


#define INF 100000   //10e9


using namespace std;

int ar[50005];
struct node
{
    int rtlmax,ltrmax,ovmax,sum;
    node()
    {
        rtlmax = -INF;
        ltrmax = -INF;
        ovmax = -INF;
        sum = -INF;
    }
};
node tree[6*50005];
void build(int root,int b,int e)
{
    if(b==e)
    {
        tree[root].ltrmax = ar[b];
        tree[root].rtlmax = ar[b];
        tree[root].ovmax = ar[b];
        tree[root].sum = ar[b];

        return;
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc+1;

    build(lc,b,mid);
    build(rc,mid+1,e);

    tree[root].sum = tree[lc].sum + tree[rc].sum;

    tree[root].ltrmax = tree[lc].ltrmax;

    if(tree[lc].ltrmax==tree[lc].rtlmax)
    {
        tree[root].ltrmax = max(
                                tree[root].ltrmax,tree[lc].ltrmax +
                                tree[rc].ltrmax);
    }

    tree[root].ltrmax = max(tree[root].ltrmax,
                            tree[lc].sum + tree[rc].ltrmax);



    tree[root].rtlmax = tree[rc].rtlmax;

    if(tree[rc].rtlmax==tree[rc].ltrmax)
    {
        tree[root].rtlmax = max(
                                tree[root].rtlmax,tree[rc].rtlmax +
                                tree[lc].rtlmax);
    }

    tree[root].rtlmax = max(
                            tree[root].rtlmax,
                            tree[rc].sum + tree[lc].rtlmax);

    tree[root].ovmax = max({tree[lc].ltrmax,
                            tree[lc].rtlmax,
                            tree[lc].ovmax,
                            tree[rc].ltrmax,
                            tree[rc].rtlmax,
                            tree[rc].ovmax,
                            tree[lc].rtlmax+
                            tree[rc].ltrmax,
                            tree[lc].sum,
                            tree[rc].sum,
                            tree[root].sum,
                            tree[root].ltrmax,
                            tree[root].rtlmax
                           });

}

node query(int root,int b,int e,int i,int j)
{
    if(b>j || e<i)
    {
        node dummy;
        //cout<<dummy.ltrmax<<endl;
        return dummy;
    }

    if(b>=i && e<=j)
    {
        return tree[root];
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc+1;

    node treelc = query(lc,b,mid,i,j);
    node treerc = query(rc,mid+1,e,i,j);

    node treeroot;

    treeroot.sum = treelc.sum + treerc.sum;

    treeroot.ltrmax = treelc.ltrmax;

    if(treelc.ltrmax==treelc.rtlmax)
    {
        treeroot.ltrmax = max(
                              treeroot.ltrmax,treelc.ltrmax +
                              treerc.ltrmax);
    }

    treeroot.ltrmax = max(treeroot.ltrmax,
                          treelc.sum + treerc.ltrmax);


    treeroot.rtlmax = treerc.rtlmax;

    if(treerc.rtlmax==treerc.ltrmax)
    {
        treeroot.rtlmax = max(
                              treeroot.rtlmax,treerc.rtlmax +
                              treelc.rtlmax);
    }

    treeroot.rtlmax = max(
                            treeroot.rtlmax,
                            treerc.sum + treelc.rtlmax);

    treeroot.ovmax = max({treelc.ltrmax,
                          treelc.rtlmax,
                          treelc.ovmax,
                          treerc.ltrmax,
                          treerc.rtlmax,
                          treerc.ovmax,
                          treelc.rtlmax +
                          treerc.ltrmax,
                          treelc.sum,
                            treerc.sum,
                            treeroot.sum,
                            treeroot.ltrmax,
                            treeroot.rtlmax
                         });

    return treeroot;
}
int main()
{
    int n;
    sfi(n);

    for(int i=1; i<=n; i++)
    {
        sfi(ar[i]);
    }

    build(1,1,n);
    int q;
    sfi(q);

    while(q--)
    {
        int x,y;
        sfii(x,y);

        if(x>y)
            swap(x,y);

        node fans = query(1,1,n,x,y);

        pf("%d\n",fans.ovmax);


    }




    return 0;
}
