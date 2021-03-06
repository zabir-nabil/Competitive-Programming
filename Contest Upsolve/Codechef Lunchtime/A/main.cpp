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
ll ai[100005];
struct node
{
    int freq[105];
};
node tree[5*100005];
void build(int root,int b,int e)
{
    if(b==e)
    {
        for(int vv=0; vv<=100; vv++)
        {
            tree[root].freq[vv] = 0;
        }
        int vl = ai[b];
        tree[root].freq[vl]++;
        return;
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc+1;

    build(lc,b,mid);
    build(rc,mid+1,e);

    for(int fv=0; fv<=100; fv++)
    {
        tree[root].freq[fv]
            = tree[lc].freq[fv]
              + tree[rc].freq[fv];
    }

}
void update(int root,int b,int e,int i,int v)
{
    if(b>i || e<i)
        return;

    if(b==e && b==i)
    {
        for(int vv=0; vv<=100; vv++)
        {
            tree[root].freq[vv] = 0;
        }
        int vl = v;
        tree[root].freq[v]++;
        return;
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc+1;

    update(lc,b,mid,i,v);
    update(rc,mid+1,e,i,v);

    for(int fv=0; fv<=100; fv++)
    {
        tree[root].freq[fv]
            = tree[lc].freq[fv]
              + tree[rc].freq[fv];
    }
}
int query(int root,int b,int e,int l,int r,int v)
{
    if(b>r || e<l)
    {
        return 0;
    }

    if(b>=l && e<=r)
    {
        return tree[root].freq[v];
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc+1;

    int p1 = query(lc,b,mid,l,r,v);
    int p2 = query(rc,mid+1,e,l,r,v);
    return p1+p2;

}
int main()
{
    int tc;
    sfi(tc);
    while(tc--)
    {
        int n,q;
        sfii(n,q);

        for(int i=1; i<=n; i++)
        {
            sfl(ai[i]);
        }

        if(n<=5000)
        {
            while(q--)
            {

                int cmd;
                sfi(cmd);
                if(cmd==1)
                {
                    int L,R;
                    sfii(L,R);
                    ll mxans = 0;

                    for(int xi=L; xi<=R; xi++)
                    {

                        mxans = max(mxans,
                                    (ai[xi]-ai[L])*(ai[R]-ai[xi]));



                    }

                    pf("%lld\n",mxans);

                }
                else
                {
                    int xx,yy;
                    sfii(xx,yy);
                    ai[xx] = yy;
                }

            }


        }
        else
        {

            build(1,1,n);

            while(q--)
            {
                int cmd;
                sfi(cmd);
                if(cmd==1)
                {
                    int L,R;
                    sfii(L,R);
                    ll mxans = 0;

                    for(int xi=0; xi<=100; xi++)
                    {
                        if(query(1,1,n,L,R,xi)>0)
                        {
                            mxans = max(mxans,
                                        (xi-ai[L])*(ai[R]-xi));
                        }


                    }

                    pf("%lld\n",mxans);

                }
                else
                {
                    int xx;
                    int yy;
                    sfii(xx,yy);

                    update(1,1,n,xx,yy);
                }

            }

        }

    }

    return 0;
}
