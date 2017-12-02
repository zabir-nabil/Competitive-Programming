#include <bits/stdc++.h>
#define ll long long
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
void build(int root,int b,int e,int x,int y)
{
    if(x!=0 && b>x || e<x)
    {
        return;
    }
    if(x!=0 && b==e && b==x)
    {
        tree[root].ltrmax = y;
        tree[root].rtlmax = y;
        tree[root].ovmax = y;
        tree[root].sum = y;

        return;
    }
    if(x==0 && b==e)
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
    build(lc,b,mid,x,y);
    build(rc,mid+1,e,x,y);
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
    build(1,1,n,0,0);
    int q;
    sfi(q);
    while(q--)
    {
        int cmd;
        sfi(cmd);
        int x,y;
        sfii(x,y);
        if(cmd==1)
        {
            node fans = query(1,1,n,x,y);
            pf("%d\n",fans.ovmax);
        }
        else
        {
            build(1,1,n,x,y);
        }
    }
    return 0;
}
