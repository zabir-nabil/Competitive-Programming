
/****************************************
@_@
Cat Got Bored *_*
#_#
*****************************************/
 
#include <bits/stdc++.h>
 
 
#define loop(i,s,e) for(int i = s;i<=e;i++) //including end point
 
#define pb(a) push_back(a)
 
#define sqr(x) ((x)*(x))
 
#define CIN ios_base::sync_with_stdio(0); cin.tie(0);
 
#define ll long long
 
#define ull unsigned long long
 
#define SZ(a) int(a.size())
 
#define read() freopen("in.txt", "r", stdin)
 
#define write() freopen("out.txt", "w", stdout)
 
 
#define ms(a,b) memset(a, b, sizeof(a))
 
#define all(v) v.begin(), v.end()
 
#define PI acos(-1.0)
 
#define pf printf
 
#define sfi(a) scanf("%d",&a);
 
#define sfii(a,b) scanf("%d %d",&a,&b);
 
#define sfl(a) scanf("%lld",&a);
 
#define sfll(a,b) scanf("%lld %lld",&a,&b);
 
#define mp make_pair
 
#define paii pair<int, int>
 
#define padd pair<dd, dd>
 
#define pall pair<ll, ll>
 
#define fs first
 
#define sc second
 
#define CASE(t) printf("Case %d:\n",++t) // t initialized 0
 
#define INF 1000000000   //10e9
 
#define EPS 1e-9
 
 
using namespace std;
int nums[100009];
int tree[300555];
void build_tree(int Node,int beg,int en)
{
    if(beg == en) // Hit the bottom
    {
        tree[Node] = nums[beg] ;
        return; // very important
    }
    int leftChild = 2*Node;
    int rightChild = 2*Node + 1;
    int mid = ( beg + en )/2;
    build_tree(leftChild,beg,mid);
    build_tree(rightChild,mid+1,en);
    tree[Node] = min( tree[leftChild] , tree[rightChild]  );
}
int query(int Node,int beg,int en,int i,int j)
{
    if( j < beg || i > en )
        return INF;
    if( i <= beg && j >= en)
    return tree[Node];
    int leftChild = 2*Node;
    int rightChild = 2*Node + 1;
    int mid = ( beg + en )/2;
    int an1 = query(leftChild,beg,mid,i,j);
    int an2 = query(rightChild,mid+1,en,i,j);
 
    return min(an1,an2);
 
 
 
 
 
 
}
int main()
{
    //read();
    //write();
    int tc;int cas = 0;
    sfi(tc);
    while(tc--)
    {
        int N,Q;
        sfii(N,Q);
        loop(i,1,N)
        {
            sfi(nums[i]) ;
        }
        build_tree(1,1,N);
        CASE(cas);
        while(Q--)
        {
            int i,j;
            sfii(i,j);
            int mn_ans = query(1,1,N,i,j);
            pf("%d\n",mn_ans);
 
        }
 
 
 
    }
 
 
    return 0;
}