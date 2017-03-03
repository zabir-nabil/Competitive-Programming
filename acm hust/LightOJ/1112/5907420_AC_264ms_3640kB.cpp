

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
#define mx_seg 100009
int N;
int arr[mx_seg + 5];
int tree[mx_seg*4];
void build_tree(int c_node,int b,int e)
{

    if(b==e)
    {
        tree[c_node] = arr[b];



        return;

    }

    int leftC = (2*c_node);
    int rightC = leftC + 1;
    int mid = ( (b+e)/2 );
    build_tree(leftC,b,mid);
    build_tree(rightC,mid+1,e);
    tree[c_node] = tree[leftC] + tree[rightC];


}
int query(int c_n,int b,int e,int i,int j)
{
    if(b>j || e<i)
        return 0; //irrelevant segment passing 0 to get the call used up

    if(b>=i && e<=j)
        return tree[c_n];

    int leftC = (2*c_n);
    int rightC = leftC + 1;
    int mid = (b+e)/2 ;


    int q1 =   query(leftC,b,mid,i,j);


    int q2 = query(rightC,mid+1,e,i,j);
    return q1+q2;



}
void update(int c_n,int b,int e,int ii,int val) //if I delete 1 element from the tree I must decrease 1 for next time updating
{
    if(b>ii || e<ii) //totally out of range
        return;

    if(b==e && b==ii)
    {



        tree[c_n] += val;
        arr[b] += val;


        return;

    }
    if(b==e && b!=ii) //Not sure but if at some point I am at some
        return;  //irrelevant node

    int leftC = (2*c_n);
    int rightC = leftC + 1;
    int mid = (b+e)/2 ;
    if(b<=ii && mid>=ii)
        update(leftC,b,mid,ii,val);
    else
        update(rightC,mid+1,e,ii,val);

    tree[c_n] = tree[leftC] + tree[rightC];



}
int main()
{
    //read();
    //write();
    int tc,cas =0;
    sfi(tc);
    while(tc--)
    {
        int Q;
        sfii(N,Q);
        loop(i,1,N)
        {
            sfi(arr[i]);
        }
        build_tree(1,1,mx_seg);
        CASE(cas);
        while(Q--)
        {

            int q_type;
            int ii,jj;
            sfi(q_type);
            if(q_type==1)
            {
                sfi(ii);
                pf("%d\n",arr[ii+1]);
                update(1,1,mx_seg,ii+1,-arr[ii+1]);//indexing shifting as I have used 1 based indexing
            }
            else if(q_type==2)
            {
                sfii(ii,jj);
                update(1,1,mx_seg,ii+1,jj); //add jj to ii th pos



            }
            else
            {
                sfii(ii,jj);
                int ans = query(1,1,mx_seg,ii+1,jj+1); //sum between ii & jj
                pf("%d\n",ans);

            }


        }




    }


    return 0;
}
