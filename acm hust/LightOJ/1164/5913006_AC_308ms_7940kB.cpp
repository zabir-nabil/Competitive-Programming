

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
//Just implementation of Lazy Propagation
#define mx_lim 100009
int N;
struct node
{
    ll propagate;;
    ll sum;
};
node tree[mx_lim*4+2];
void init_tree()
{
    loop(i,1,mx_lim*4)
    {
        tree[i].propagate = 0;
        tree[i].sum = 0;
    }
}

void range_update(int c_n,int b,int e,int i,int j,ll v)
{
    if(e<i || b>j) //totally out of range
        return;
    if(b>=i && e<=j) //relevant segment
    {
        //To ensure update in O(log(N)) we cant go any deeper , I have to return
        //from here
        //What I will do is from the new update operation value (here v)
        //I will calculate the ans (here sum) for the range (b e)
        //and I will also save  a propagate value here for future query operation

        tree[c_n].sum += (e-b+1)*v ; //This is a completely relevant segment
        //so I add v to all the elements in the range (b e) so the sum
        //in this node increases by (e-b+1)*v = (number of elements * value added)
        tree[c_n].propagate += v;
        //Next time I make a query operation and I go any children of this node (lower level leaf)
        //I will keep adding this value until I get a relevant segment as this only means
        // I should have added this value to those lower nodes but I was lazy :-/ so I just
        //made a flag to make me know that in future I need to add these propagation values
        //to lower level nodes
        return; //this return statement here guarantee s me log(N) time  :-D

    }
    //Not a relevant segment

    int leftC = (c_n*2);
    int rightC = leftC + 1;
    int mid = (b+e)/2;
    //I recursively update the left portion and then right portion
    //I return when I get a irrelevant section and when I get a relevant section I update it
    range_update(leftC,b,mid,i,j,v);
    range_update(rightC,mid+1,e,i,j,v);
    //As it's already a bigger range so I just update the node sum as sum of
    //left node sum and right node sum
    //But wait , what if this node contains a propagate value I also need to add this to
    //get the actual sum of this range so , I must add (e-b+1)*propagation value to the sum
    // as propagation value exists in this node that means I had updated this node
    //earlier and all the elements in the range (b e) must have an actual sum = sum now + propagation value
    //So the actual sum of this node is left node sum + right node sum + number_of_lower_leafs*prop_val
    tree[c_n].sum = tree[leftC].sum + tree[rightC].sum + tree[c_n].propagate*(e-b+1);
    //I am done updating :-D
}
ll query(int c_n,int b,int e,int i,int j,ll carry)
{

    if(b>j || e<i)  //totally out of range
        return 0; // As the identity of addition operation is 0

    if(b>=i && e<=j) //relevant segment
    {
        //To ensure update in O(log(N)) we cant go any deeper , I have to return
        //from here
        //As this is a totally relevant segment I must return the partial ans
        //from here
        //What carry actually carries?
        //It carries sum of all the propagation values of the upper nodes
        //That means those values were supposed to be added to all the elements
        //of the range (b e) as this is already a completely relevant segment
        //I will add all those values to all the elements in the range
        //So actually I will return the sum that is contained in this node + the carry
        // = prop_val_sum*(number of nodes in this range
        return tree[c_n].sum + carry*(e-b+1);


    }
    //Bigger segment which is composed of both relevant and irrelevant segments
    //First I recursively query the left child and right child until I hit
    //a irrelevant segment where I return just 0
    //Or when I hit a relevant segment I just return the partial ans
    //But first I must pass the propagation values downward so if I hit a relevant
    //segment at bottom I will add this value to my query if don't hit
    // a relevant segment I will not add this prop_val (return 0)
    int leftC = (c_n*2);
    int rightC = leftC + 1;
    int mid = (b+e)/2;
    int prop = tree[c_n].propagate ; //for future : lower nodes
    ll qL = query(leftC,b,mid,i,j,carry+prop); //I add this prop_val to my carry
    ll qR = query(rightC,mid+1,e,i,j,carry+prop); //I will add this prop_val to both the child
    //as I can hit relevant segment in both those portions
    return qL + qR;

}
int main()
{
    //read();
    //write();
    int tc,cas = 0;
    sfi(tc);
    while(tc--)
    {
        init_tree();
        int Q;
        sfii(N,Q);

        int q_type,x,y;ll v;
        CASE(cas);
        while(Q--)
        {


            sfi(q_type);
            if(q_type==0)
            {
                sfii(x,y); //always check if index is 0 based then you need to shift 1 unit to right
                sfl(v);
                range_update(1,1,N,x+1,y+1,v);
            }
            else
            {
                sfii(x,y);
                ll ans = query(1,1,N,x+1,y+1,0) ; //carry initially 0
                pf("%lld\n",ans);
            }

        }
    }


    return 0;
}
