

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

#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define INF 1000000000   //10e9

#define EPS 1e-9


using namespace std;

#define mx_lim 30009
int heights[mx_lim];
int N;
struct node{
int height;
int index; //To avoid extra binary search later
};
node INF_NODE;
node tree[3*mx_lim];
void build_tree(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].height = heights[b];
        tree[node].index = b;
        return;
    }
    int leftCh = 2*node;
    int rightCh = leftCh + 1;
    int mid = (b+e)/2;
    build_tree(leftCh,b,mid);
    build_tree(rightCh,mid+1,e);
    if(tree[leftCh].height < tree[rightCh].height)
    {
        tree[node].height = tree[leftCh].height;
        tree[node].index = tree[leftCh].index;
    }
    else
    {
           tree[node].height = tree[rightCh].height;
        tree[node].index = tree[rightCh].index;
    }

}
node query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i) //out of range
        return INF_NODE; //some sen value INF to just make the call go away

    if(b>=i && e<=j) //totally in range
    {
        return tree[node]; //just return that struct

    }
    //need to go down
   int leftCh = 2*node;
    int rightCh = leftCh + 1;
    int mid = ((b+e)/2);
    struct node q1;
    q1  = query(leftCh,b,mid,i,j);
    struct node q2 ;
    q2 = query(rightCh,mid+1,e,i,j);
    if(q1.height <= q2.height)
    {
        return q1;
    }
    else
    {
        return q2;
    }




}
int divide_and_conquer(int i,int j)
{
    //cout<<"last error"<<i<<" "<<j<<endl;
    if(i==j)
        return heights[i];
//
    if(i>j)
        return 0; // Important line : I am going to wrong ranges -> RTE
    node minimum_in_range = query(1,1,N,i,j);
    int min_ht = minimum_in_range.height;
    int min_index = minimum_in_range.index;
    int possibility1 = min_ht*(j-i+1) ; //The area that can be made by taking the
    //minimum in the range . we can take the total range as it is the minimum
    //in the list
    int possibility2 = divide_and_conquer(i,min_index-1); //excluding the
    //minimum and taking the left side for answer
    int possibility3 = divide_and_conquer(min_index+1,j); //excluding the
    //minimum and taking the right side

    int pos12 = max(possibility1,possibility2);

    return max( pos12, possibility3 );


}
int main()
{
//read();
//write();
INF_NODE.height = INF;
INF_NODE.index = 0;

int tc;
int cas = 0;
sfi(tc);
while(tc--)
{

    sfi(N);
    loop(i,1,N)
    {
        sfi(heights[i]);
    }
    build_tree(1,1,N);
    loop(i,1,N-1){
    struct node nn1 = query(1,1,N,i,i+1);
    //cout<<nn1.height<<" ";
    }
    int max_area = divide_and_conquer(1,N); //O(N) complexity as number of nodes in
    // a balanced 3-tree is O(N) . same way //depth O(log3(N)) = = k // and total nodes
    //3^(k+1) - 1 = = O(N)
    CASE(cas);
    pf("%d\n",max_area);

}
    return 0;
}
