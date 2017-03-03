

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

#define CASE(t) printf("Case %d:\n",++t) // t initialized 0

#define INF 1000000000   //10e9

#define EPS 1e-9


using namespace std;

#define mx_lim 100009
char binary_str[mx_lim];

struct node{
ll propagate;
ll flipped_times;
};
node tree[mx_lim*3];
void build_tree(int cur_node,int b,int e)
{
    if(b==e)
    {
        tree[cur_node].propagate = 0;
        tree[cur_node].flipped_times = 0;
        return;
    }
    tree[cur_node].propagate = 0;
    tree[cur_node].flipped_times = 0;

    int left_child = (cur_node*2);
    int right_child = (left_child+1);
    int mid = (b+e)/2;
    build_tree(left_child,b,mid);
    build_tree(right_child,mid+1,e);
   // tree[cur_node].flipped_times = tree[left_child].flipped_times + tree[right_child].flipped_times;



}
void range_update(int cur_node,int b,int e,int i,int j) //adding 1 by default // flipping 1 more time
{

    if(b>j || e<i) //totally out of range
        return;
    if(b>=i && e<=j) //totally inside the range
    {
        tree[cur_node].flipped_times += (e-b+1);
        tree[cur_node].propagate += 1;
        return ;
    }
    int left_child = (cur_node*2);
    int right_child = (left_child+1);
    int mid = ((b+e)/2);
    range_update(left_child,b,mid,i,j);
    range_update(right_child,mid+1,e,i,j);
    tree[cur_node].flipped_times = tree[left_child].flipped_times + tree[right_child].flipped_times + tree[cur_node].propagate;



}
ll query(int cur_node,int b,int e,int i,int carry)
{
  if(i<b || i>e)
    return 0;
  if(i==b && i==e)
  {
      return tree[cur_node].flipped_times + carry;
  }
  int left_child = (cur_node*2);
    int right_child = (left_child+1);
    int mid = ((b+e)/2);
    int q1 = query(left_child,b,mid,i,carry + tree[cur_node].propagate);
    int q2 = query(right_child,mid+1,e,i,carry+tree[cur_node].propagate);

    return q1+q2;

}
int main()
{
//read();
//write();
int tc,cas = 0;
sfi(tc);
int tc_mem = 0;
while(tc--)
{
    scanf("%s",binary_str);
    int N = strlen(binary_str);
    build_tree(1,1,N);
    int qqq;
    sfi(qqq);
    CASE(cas);
    while(qqq--)
    {
        char q_type = 'N';
        while(q_type!='I' && q_type!='Q')
        scanf("%c",&q_type);

        if(q_type == 'I')
        {
            int i,j;
            sfii(i,j);
            range_update(1,1,N,i,j);
        }
        else if(q_type == 'Q')
        {
            int ii;
            sfi(ii);
            int how_many_times_flipped = query(1,1,N,ii,0);
            if(how_many_times_flipped%2==0)
            {
               if(binary_str[ii-1]=='0')
                pf("0\n");
               else
                pf("1\n");
            }
            else
            {
                 if(binary_str[ii-1]=='0')
                pf("1\n");
                else
                    pf("0\n");

            }

        }


    }


}


    return 0;
}
