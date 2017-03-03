

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
#define N_max 100000
#define mx_seg (1429438) //max possible army configuration in

int N;
int updated; // actually updated or it was already updated

int tree[mx_seg*6];
int arr[mx_seg] ; //lower region for O(1) checking
int sol[N_max+5] ;
int ans_id;
int ans_pos;
int ans_num_army;

void build_tree(int c_node,int b,int e)
{

    if(b==e)
    {
        if(b%2==0)
        {
            tree[c_node] = 0;

            arr[b] = 0;
        }
        else
        {
            tree[c_node] = 1;
            arr[b] = 1;
        }



        return;

    }

    int leftC = (2*c_node);
    int rightC = leftC + 1;
    int mid = ( (b+e)/2 );
    build_tree(leftC,b,mid);
    build_tree(rightC,mid+1,e);
    tree[c_node] = tree[leftC] + tree[rightC];
    //cout<<tree[c_node].num_armies<<"~";

}
int query(int c_n,int b,int e,int pos)
{
    //returning node of the pos th unmarked army
    if(b==e)
    {

        return b;


    }

    int leftC = (2*c_n);
    int rightC = leftC + 1;
    int mid = (b+e)/2 ;
    int num_armies_in_left_subtree = tree[leftC];
    int num_armies_in_right_subtree = tree[rightC];
    if(num_armies_in_left_subtree>=pos)
    {
        query(leftC,b,mid,pos);
    }
    else
    {
        int new_pos = pos - num_armies_in_left_subtree;
        query(rightC,mid+1,e,new_pos);
    }


}
void update(int c_n,int b,int e,int pos_to_be_updated) //if I delete 1 element from the tree I must decrease 1 for next time updating
{
    if(b>pos_to_be_updated || e<pos_to_be_updated) //totally out of range
        return;

    if(b==e && b==pos_to_be_updated)
    {



        tree[c_n] = 0;
        arr[b] = 0;


        return;

    }
    if(b==e && b!=pos_to_be_updated) //Not sure but if at some point I am at some
        return;  //irrelevant node

    int leftC = (2*c_n);
    int rightC = leftC + 1;
    int mid = (b+e)/2 ;
    if(b<=pos_to_be_updated && mid>=pos_to_be_updated)
    update(leftC,b,mid,pos_to_be_updated);
    else
    update(rightC,mid+1,e,pos_to_be_updated);

    tree[c_n] = tree[leftC] + tree[rightC];



}
int main()
{
int tc;int cas = 0;
sfi(tc);
build_tree(1,1,mx_seg);
loop(i,2,N_max)
{
    int i_th_unmarked = query(1,1,mx_seg,i);
    sol[i] = i_th_unmarked;

    for(int now_up = i_th_unmarked;now_up<=mx_seg-5;) //first time used now_up<=N_max so didn't get the CA
    {
        int need_to_del = query(1,1,mx_seg,now_up);

        update(1,1,mx_seg,need_to_del);
        now_up--;
        now_up+=i_th_unmarked;


    }

}
/*
loop(i,1,100000)
pf("%d ",query(1,1,mx_seg,i));
*/
sol[1] = 1;
while(tc--)
{

    int pp;
    sfi(pp);
    CASE(cas);
   // int ans = query(1,1,mx_seg,pp); //Doing in extra O(log(N))

    pf("%d\n",sol[pp]); //Doing in O(1)

}

    return 0;
}
