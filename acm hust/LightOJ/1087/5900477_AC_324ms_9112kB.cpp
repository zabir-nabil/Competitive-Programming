

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
#define mx_seg (150018) //max possible army configuration in
#define mx_seg2 (mx_seg-1)
int N;
int army[mx_lim];

struct node{
int num_armies; //num of armies in that range
int pos_in_seg_tree ; //The range (b,e) in the lowest level of tree where b = e
int id; //only applicable for nodes of lowest level
};
node tree[mx_seg2*4];
int ans_id;
int ans_pos;
int ans_num_army;
void init_tree()
{
    loop(i,1,mx_seg2*4-1)
    {

        tree[i].num_armies = 0;


    }

}
void build_tree(int c_node,int b,int e)
{

    if(b==e)
    {
        if(b<=N)
    {
        tree[c_node].id = army[b];
        tree[c_node].num_armies = 1;
        tree[c_node].pos_in_seg_tree = b;
    }

        return;

    }

    int leftC = (2*c_node);
    int rightC = leftC + 1;
    int mid = ( (b+e)/2 );
    build_tree(leftC,b,mid);
    build_tree(rightC,mid+1,e);
    tree[c_node].num_armies = tree[leftC].num_armies + tree[rightC].num_armies;
    //cout<<tree[c_node].num_armies<<"~";

}
void query(int c_n,int b,int e,int pos)
{
    //returning node of the pos th unmarked army
    if(b==e)
    {


        ans_id = tree[c_n].id;;
        ans_pos = b;;

        return;


    }

    int leftC = (2*c_n);
    int rightC = leftC + 1;
    int mid = (b+e)/2 ;
    int num_armies_in_left_subtree = tree[leftC].num_armies;
    int num_armies_in_right_subtree = tree[rightC].num_armies;
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
void update(int c_n,int b,int e,int mode,int pos_to_be_updated,int new_id)
{
    if(b>pos_to_be_updated || e<pos_to_be_updated) //totally out of range
        return;

    if(b==e && b==pos_to_be_updated)
    {
        if(mode==1){ //Inserting new army
        tree[c_n].num_armies = 1;
        tree[c_n].id = new_id;
        tree[c_n].pos_in_seg_tree = b;
        }

        else if(mode==2){ //Removing old army
        tree[c_n].num_armies = 0;

        }
        return;

    }
    if(b==e && b!=pos_to_be_updated) //Not sure but if at some point I am at some
        return;  //irrelevant node

    int leftC = (2*c_n);
    int rightC = leftC + 1;
    int mid = (b+e)/2 ;
    if(b<=pos_to_be_updated && mid>=pos_to_be_updated)
    update(leftC,b,mid,mode,pos_to_be_updated,new_id);
    else
    update(rightC,mid+1,e,mode,pos_to_be_updated,new_id);

    tree[c_n].num_armies = tree[leftC].num_armies + tree[rightC].num_armies;



}
int main()
{
int tc;int cas = 0;
sfi(tc);
while(tc--)
{
    CASE(cas);
    int Q;
    sfii(N,Q);

    loop(i,1,N)
    {
        sfi(army[i]);

    }
    init_tree();
    build_tree(1,1,mx_seg2);
/*
    loop(i,1,N+5)
    {
        cout<<"Tree["<<i<<"]->"<<" id: "<<tree[i].id<<" armies: "<<tree[i].num_armies;
        cout<<"\npos_in_seg: "<<tree[i].pos_in_seg_tree<<endl;
    }
*/

int Qqq = Q*2;int i = 1;

    while(Qqq--)
    {

        char chh;int qqq;
        scanf("%c %d",&chh,&qqq);

        if(chh=='a')
        {
            int total_army_no = tree[1].num_armies ; //How many army s I have now in the list

             query(1,1,mx_seg2,total_army_no); // last army position which is unmarked //Generalization with query
            int last_army_pos = ans_pos;

            update(1,1,mx_seg2,1,last_army_pos+1,qqq); //I place the newly arrived army after the last
            //placed unmarked army

        }
        else if(chh=='c')
        {
            if(tree[1].num_armies<qqq)
            {
                pf("none\n");
            }
            else
            {

            //node tempii = query(1,1,mx_seg2,qqq) ; //finding army with qqq th position
            query(1,1,mx_seg2,qqq);//= tempii.id; //each time propagating these infos locally for each query
            //;//= tempii.pos_in_seg_tree;

            pf("%d\n",ans_id);
            update(1,1,mx_seg2,2,ans_pos,0);
            }

        }



    }





}


    return 0;
}
