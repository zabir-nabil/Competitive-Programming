

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
#define mx_range 50009
#define mx_seg 160009
int N,Q;
map<ll,int>isThere;
pair<ll,ll>segments[mx_range];
ll queryOffline[mx_range] ;
vector<ll>compresser;
map<ll,int>mapper;
struct node{
ll propagate;
ll updatedTimes;
};
node tree[mx_seg*5];
void clear_all()
{
    compresser.clear();
    mapper.clear(); //not needed
    isThere.clear();
}
void init_tree()
{
    loop(i,1,mx_seg*5-2)
    {
        tree[i].propagate = 0;
        tree[i].updatedTimes = 0;
    }

}
void range_update(int c_n,int b,int e,int i,int j)
{
    if(b>j || e<i) //totally out of range :: nothing to do
        return;
    if(b>=i && e<=j) //relevant segment
    {
        tree[c_n].propagate += 1; //I am first storing the propagate value in this segment for later propagation

        tree[c_n].updatedTimes += (e-b+1) ; //I know before hand if I propagate the new 1 I must get extra (e-b+1)[width
        //of the range*value]
        return ; //Not going any lower thus maintaining O(logN)

    }
    int leftT = c_n*2;
    int rightT = leftT + 1;
    int mid = (b+e)/2;
    range_update(leftT,b,mid,i,j);

    range_update(rightT,mid+1,e,i,j);

    tree[c_n].updatedTimes = tree[leftT].updatedTimes + tree[rightT].updatedTimes + (e-b+1);
}
ll query(int c_n,int b,int e,int ii,int jj,ll carry)
{
    if(b>jj || e<ii)
        return 0;
    if(b>=ii && e<=jj)
    {
       return tree[c_n].updatedTimes + carry*(e-b+1);
    }
    int leftT = c_n*2;
    int rightT = leftT + 1;
    int mid = (b+e)/2;
    ll new_carry = tree[c_n].propagate;

ll qq1 = query(leftT,b,mid,ii,jj,carry+new_carry);
ll qq2 = query(rightT,mid+1,e,ii,jj,carry+new_carry);
return qq1+qq2;
}
int main()
{

//read();
//write();
    int tc,cas = 0;
    sfi(tc);
    while(tc--)
    {
        clear_all();
        sfii(N,Q);
        loop(i,1,N)
        {
            ll x,y;
            sfll(x,y);
            pair<ll,ll>tmp;
            tmp.first = x; tmp.second = y;
            segments[i] = tmp;
            if(isThere[x]==0)
            {
                compresser.pb(x);
                isThere[x]++;
            }
            if(isThere[y]==0)
            {
                compresser.pb(y);
                isThere[y]++;
            }



        }

        loop(i,1,Q)
        {
            ll qqq;
            sfl(qqq);
            queryOffline[i] = qqq;
               if(isThere[qqq]==0)
            {
                compresser.pb(qqq);
                isThere[qqq]++;
            }



        }

        sort(compresser.begin(),compresser.end());
        loop(i,0,compresser.size()-1)
        {

            mapper[ compresser[i] ] = i+1;

        }
        init_tree();
        loop(i,1,N)
        {
            pair<ll,ll>tmp = segments[i];
            int st = mapper[ tmp.first ];int en = mapper[ tmp.second  ];
            range_update(1,1,mx_seg,st,en);
        }

        CASE(cas);
        loop(i,1,Q)
        {
            int map_qq  = mapper[ queryOffline[i] ];
            ll h_m_t_u = query(1,1,mx_seg,map_qq,map_qq,0); //how_many_times_updated
            pf("%lld\n",h_m_t_u);

        }
        clear_all();



    }


    return 0;
}
