

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



///Segment tree Template//////////////////////////

#define segType long long
#define finRT long long
struct SegTreeNode {
segType max_in_range;
segType min_in_range;

  void assignLeaf(segType mArrEl) {

      max_in_range = mArrEl;
      min_in_range = mArrEl;

   }

  void merge(SegTreeNode& left, SegTreeNode& right) {

      max_in_range = max( left.max_in_range , right.max_in_range  );
      min_in_range = min(left.min_in_range , right.min_in_range) ;
  }

  finRT getValue() {
      return (max_in_range - min_in_range);

  }
};


template<class T, class V>
class SegTree {
  SegTreeNode* nodes;
  int N;

public:
  SegTree(T arr[], int N) {
    this->N = N;
    nodes = new SegTreeNode[getSegmentTreeSize(N)];
    buildTree(arr, 1, 0, N-1);
  }

  ~SegTree() {
    delete[] nodes;
  }

  V getValue(int lo, int hi) {
    SegTreeNode result = getValue(1, 0, N-1, lo, hi);
    return result.getValue();
  }

  void update(int index, T value) {
    update(1, 0, N-1, index, value);
  }

  private:
  void buildTree(T arr[], int stIndex, int lo, int hi) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }

    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }

  SegTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
    if (left == lo && right == hi)
      return nodes[stIndex];

    int mid = (left + right) / 2;
    if (lo > mid)
      return getValue(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
      return getValue(2*stIndex, left, mid, lo, hi);

    SegTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
    SegTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
    SegTreeNode result;
    result.merge(leftResult, rightResult);
    return result;
  }

  int getSegmentTreeSize(int N) {
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }

  void update(int stIndex, int lo, int hi, int index, T value) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }

    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
      update(left, lo, mid, index, value);
    else
      update(right, mid+1, hi, index, value);

    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};
/////////////////////////////////////////////////////////////////////


int arr[100009];
int main()
{
int tc,cas = 0;
sfi(tc);
while(tc--)
{
    int n,d;
    sfii(n,d);
    loop(i,0,n-1)
    {
        sfi(arr[i]);
    }
    SegTree<int,int> sT(arr,n);
    int mx_diff = 0;
    CASE(cas);
    loop(i,0,n-d)
    {
        mx_diff = max(mx_diff , sT.getValue(i,i+d-1));
    }
    pf("%d\n",mx_diff);
}


    return 0;
}
