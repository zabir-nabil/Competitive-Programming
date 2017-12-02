#include <bits/stdc++.h>
#define ll long long
#define pf printf
#define sfi(a) scanf("%d",&a);
#define sfii(a,b) scanf("%d %d",&a,&b);
#define INF 100000   //10e9
using namespace std;
int ar[100005];
//SEGMENT TREE
//COPYING BUILD FUNC FOR UPDATE
//CHECK IF YOU ARE CALLING BUILD INSIDE UPDATE
struct node
{
    int ovmax,ovmax2;
};
node tree[4*100005];
void build(int root,int b,int e)
{
    if(b==e)
    {
        tree[root].ovmax = ar[b];
        tree[root].ovmax2 = 0;
        return;
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc+1;

    build(lc,b,mid);
    build(rc,mid+1,e);

    vector<int>dum;
    dum.push_back(tree[lc].ovmax2);
    dum.push_back(tree[lc].ovmax);
    dum.push_back(tree[rc].ovmax2);
    dum.push_back(tree[rc].ovmax);
    sort(dum.rbegin(),dum.rend());


    tree[root].ovmax = dum[0];
    tree[root].ovmax2 = dum[1];
    dum.clear();



}
void update(int root,int b,int e,int i,int x)
{
    if(b>i || e<i)
    {
        return;
    }
    if(b==e && b==i)
    {
        tree[root].ovmax = x;
        tree[root].ovmax2 = 0;
        return;
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc+1;

    update(lc,b,mid,i,x);
    update(rc,mid+1,e,i,x);

    vector<int>dum;
    dum.push_back(tree[lc].ovmax2);
    dum.push_back(tree[lc].ovmax);
    dum.push_back(tree[rc].ovmax2);
    dum.push_back(tree[rc].ovmax);
    sort(dum.rbegin(),dum.rend());


    tree[root].ovmax = dum[0];
    tree[root].ovmax2 = dum[1];
    dum.clear();



}
node query(int root,int b,int e,int i,int j)
{
    if(b>j || e<i)
    {
        node dummy;
        dummy.ovmax2 = 0;
        dummy.ovmax = 0;
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
    vector<int>dum;
    dum.push_back(treelc.ovmax2);
    dum.push_back(treelc.ovmax);
    dum.push_back(treerc.ovmax2);
    dum.push_back(treerc.ovmax);
    sort(dum.rbegin(),dum.rend());


    treeroot.ovmax = dum[0];
    treeroot.ovmax2 = dum[1];
    dum.clear();

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
        char cmd;
        cmd = 'g';
        while(1)
        {
            scanf("%c",&cmd);
            if(cmd=='U' || cmd=='Q')
                break;
        }

        if(cmd=='Q')
        {
            int x,y;
            sfii(x,y);
            node ans = query(1,1,n,x,y);
            pf("%d\n",ans.ovmax+ans.ovmax2);
        }
        else if(cmd=='U')
        {
            int x,y;
            sfii(x,y);

            update(1,1,n,x,y);
        }


    }


    return 0;
}
