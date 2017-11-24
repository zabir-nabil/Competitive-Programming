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


//Bit Manipulation
bool Check_ON(int mask,int pos) //Check if pos th bit (from right) of mask is ON
{
    if( (mask & (1<<pos) ) == 0  )return false;
    return true;
}
int SET(int mask,int pos) //Save the returned mask into some var //Turn on pos th bit in mask
{
    return (mask | (1<<pos));
}
int RESET(int mask,int pos)  //Save the returned mask into some var //Turn off pos th bit in mask
{
    return (mask & ~(1<<pos));
}
int FLIP(int mask,int pos) //Save the returned mask into some var //Toggle/Flip pos th bit in mask
{
    return (mask ^ (1<<pos));
}
int LSB(int mask) // The actual LSB mask
{
    return (mask & (-mask));
}
int LSB_pos(int mask) // 0 based position
{
    int mask_2 = (mask & (-mask));
    for(int pos = 0; pos<=15; pos++)
    {
        if(Check_ON(mask_2,pos))
            return pos;
    }
    return -1;//
}
int ON_Bits(int mask)
{
    return __builtin_popcount(mask);
}
inline int clz(int N)   // O(1) way to calculate log2(X) (int s only)
{
    return N ? 32 - __builtin_clz(N) : -INF;
}
int N,Q;
ll L,R;
struct node
{
    int ltr_lessL
    ,ltr_lessEqR,
    rtl_lessL,
    rtl_lessEqR;

    ll ans,val;

    node()
    {
        val = 0;
        ans = 0;
        ltr_lessL = 0;
        ltr_lessEqR = 0;
        rtl_lessEqR = 0;
        rtl_lessL = 0;
    }


};

node tree[2000005];

void build(int root,int b,int e)
{
    if(b==e)
    {
        tree[root].val = 0;
        if(tree[root].val>=L
                && tree[root].val<=R)
        {
            tree[root].ans = 1;
            tree[root].ltr_lessEqR = 1;
            tree[root].ltr_lessL = 0;
            tree[root].rtl_lessL = 0;
            tree[root].rtl_lessEqR = 1;
        }
        else if(tree[root].val<L)
        {
            tree[root].ans = 0;
            tree[root].ltr_lessEqR = 1;
            tree[root].ltr_lessL = 1;
            tree[root].rtl_lessL = 1;
            tree[root].rtl_lessEqR = 1;
        }
        else if(tree[root].val>R)
        {
            tree[root].ans = 0;
            tree[root].ltr_lessEqR = 0;
            tree[root].ltr_lessL = 0;
            tree[root].rtl_lessL = 0;
            tree[root].rtl_lessEqR = 0;
        }

        return;

    }
    int mid = (b+e)/2;
    int leftC = root*2;
    int rightC = leftC + 1;

    build(leftC,b,mid);
    build(rightC,mid+1,e);

    //left to right update

    int left_cover = (mid-b+1);

    if(tree[leftC].ltr_lessL==left_cover)
    {
        tree[root].ltr_lessL =
            tree[leftC].ltr_lessL
            + tree[rightC].ltr_lessL;
    }
    else
    {
        tree[root].ltr_lessL =
            tree[leftC].ltr_lessL;
    }


    if(tree[leftC].ltr_lessEqR==left_cover)
    {
        tree[root].ltr_lessEqR =
            tree[leftC].ltr_lessEqR
            + tree[rightC].ltr_lessEqR;
    }
    else
    {
        tree[root].ltr_lessEqR =
            tree[leftC].ltr_lessEqR;
    }

    //right to left update

    int right_cover = (e-mid);

    if(tree[rightC].rtl_lessL==right_cover)
    {
        tree[root].rtl_lessL =
            tree[rightC].rtl_lessL
            + tree[leftC].rtl_lessL;
    }
    else
    {
        tree[root].rtl_lessL =
            tree[rightC].rtl_lessL;
    }

    if(tree[rightC].rtl_lessEqR==right_cover)
    {
        tree[root].rtl_lessEqR =
            tree[rightC].rtl_lessEqR
            + tree[leftC].rtl_lessEqR;
    }
    else
    {
        tree[root].rtl_lessEqR =
            tree[rightC].rtl_lessEqR;
    }

    // ans update

    tree[root].ans = tree[leftC].ans
                     + tree[rightC].ans;

    ll mergedans = 0;
    ll left_tree_valid = (ll)(tree[leftC].rtl_lessEqR
                              - tree[leftC].rtl_lessL);
    ll left_all = (ll)tree[leftC].rtl_lessEqR;

    ll right_tree_valid = (ll)(tree[rightC].ltr_lessEqR
                               - tree[rightC].ltr_lessL);
    ll right_all = (ll)tree[rightC].ltr_lessEqR;
    mergedans = (left_tree_valid*right_all)
                + (right_tree_valid*left_all)
                - (left_tree_valid*right_tree_valid);

    tree[root].ans += mergedans;


}

void update(int root,int b,int e,int i,ll j)
{
    if(i>e || i<b)
    {
        return;
    }
    if(b==e && b==i)
    {
        tree[root].val = j;
        if(tree[root].val>=L
                && tree[root].val<=R)
        {
            tree[root].ans = 1;
            tree[root].ltr_lessEqR = 1;
            tree[root].ltr_lessL = 0;
            tree[root].rtl_lessL = 0;
            tree[root].rtl_lessEqR = 1;
        }
        else if(tree[root].val<L)
        {
            tree[root].ans = 0;
            tree[root].ltr_lessEqR = 1;
            tree[root].ltr_lessL = 1;
            tree[root].rtl_lessL = 1;
            tree[root].rtl_lessEqR = 1;
        }
        else if(tree[root].val>R)
        {
            tree[root].ans = 0;
            tree[root].ltr_lessEqR = 0;
            tree[root].ltr_lessL = 0;
            tree[root].rtl_lessL = 0;
            tree[root].rtl_lessEqR = 0;
        }

        return;

    }
    int mid = (b+e)/2;
    int leftC = root*2;
    int rightC = leftC + 1;

    update(leftC,b,mid,i,j);
    update(rightC,mid+1,e,i,j);

    //left to right update

    int left_cover = (mid-b+1);

    if(tree[leftC].ltr_lessL==left_cover)
    {
        tree[root].ltr_lessL =
            tree[leftC].ltr_lessL
            + tree[rightC].ltr_lessL;
    }
    else
    {
        tree[root].ltr_lessL =
            tree[leftC].ltr_lessL;
    }


    if(tree[leftC].ltr_lessEqR==left_cover)
    {
        tree[root].ltr_lessEqR =
            tree[leftC].ltr_lessEqR
            + tree[rightC].ltr_lessEqR;
    }
    else
    {
        tree[root].ltr_lessEqR =
            tree[leftC].ltr_lessEqR;
    }

    //right to left update

    int right_cover = (e-mid);

    if(tree[rightC].rtl_lessL==right_cover)
    {
        tree[root].rtl_lessL =
            tree[rightC].rtl_lessL
            + tree[leftC].rtl_lessL;
    }
    else
    {
        tree[root].rtl_lessL =
            tree[rightC].rtl_lessL;
    }

    if(tree[rightC].rtl_lessEqR==right_cover)
    {
        tree[root].rtl_lessEqR =
            tree[rightC].rtl_lessEqR
            + tree[leftC].rtl_lessEqR;
    }
    else
    {
        tree[root].rtl_lessEqR =
            tree[rightC].rtl_lessEqR;
    }

    // ans update

    tree[root].ans = tree[leftC].ans
                     + tree[rightC].ans;

    ll mergedans = 0;
    ll left_tree_valid = (tree[leftC].rtl_lessEqR
                          - tree[leftC].rtl_lessL);
    ll left_all = tree[leftC].rtl_lessEqR;

    ll right_tree_valid = (tree[rightC].ltr_lessEqR
                           - tree[rightC].ltr_lessL);
    ll right_all = tree[rightC].ltr_lessEqR;
    mergedans = (left_tree_valid*right_all)
                + (right_tree_valid*left_all)
                - (left_tree_valid*right_tree_valid);
    tree[root].ans += mergedans;


}

node query(int root,int b,int e,int l,int r)
{
    if(l>e || r<b)
    {
        node null_node;
        return null_node;
    }

    if(b>=l && e<=r)
    {
        return tree[root];
    }
    int mid = (b+e)/2;
    int leftC = root*2;
    int rightC = leftC + 1;

    node p1 = query(leftC,b,mid,l,r);
    node p2 = query(rightC,mid+1,e,l,r);

    ll ans = p1.ans + p2.ans;
    ll mergedans = 0;
    ll left_tree_valid = (p1.rtl_lessEqR
                          - p1.rtl_lessL);
    ll left_all = p1.rtl_lessEqR;

    ll right_tree_valid = (p2.ltr_lessEqR
                           - p2.ltr_lessL);
    ll right_all = p2.ltr_lessEqR;
    mergedans = (left_tree_valid*right_all)
                + (right_tree_valid*left_all)
                - (left_tree_valid*right_tree_valid);


    ans += mergedans;

    node ret;

    //left to right update

    int left_cover = (mid-b+1);

    if(p1.ltr_lessL==left_cover)
    {
        ret.ltr_lessL =
            p1.ltr_lessL
            + p2.ltr_lessL;
    }
    else
    {
        ret.ltr_lessL =
            p1.ltr_lessL;
    }


    if(p1.ltr_lessEqR==left_cover)
    {
        ret.ltr_lessEqR =
            p1.ltr_lessEqR
            + p2.ltr_lessEqR;
    }
    else
    {
        ret.ltr_lessEqR =
            p1.ltr_lessEqR;
    }

    //right to left update

    int right_cover = (e-mid);

    if(p2.rtl_lessL==right_cover)
    {
        ret.rtl_lessL =
            p2.rtl_lessL
            + p1.rtl_lessL;
    }
    else
    {
        ret.rtl_lessL =
            p2.rtl_lessL;
    }

    if(p2.rtl_lessEqR==right_cover)
    {
        ret.rtl_lessEqR =
            p2.rtl_lessEqR
            + p1.rtl_lessEqR;
    }
    else
    {
        ret.rtl_lessEqR =
            p2.rtl_lessEqR;
    }

    ret.ans = ans;

    return ret;




}
int main()
{
    sfii(N,Q);

    sfll(L,R);

    build(1,1,N);

    while(Q--)
    {
        int cmd;
        sfi(cmd);

        if(cmd==1)
        {
            int i;
            ll j;
            sfi(i);
            sfl(j);
            update(1,1,N,i,j);

        }
        else
        {
            int l,r;
            sfii(l,r);
            node ans = query(1,1,N,l,r);
            pf("%lld\n",ans.ans);
        }


    }



    return 0;
}
