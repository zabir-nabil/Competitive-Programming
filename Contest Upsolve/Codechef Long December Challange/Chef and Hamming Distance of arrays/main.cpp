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
int ai[100005];
int freq[100005];
struct nod
{
    int val;
    int idx1;
    int idx2;
};
nod f1[100005];
nod f2[100005];
int mark[100005];
int ans[100005];
int bi[100005];
int main()
{
    int tc;
    sfi(tc);
    while(tc--)
    {
        int n;
        sfi(n);

        ms(freq,0);
        ms(mark,0);

        int fr1 = 0;
        int fr2 = 0;

        for(int i=1; i<=n; i++)
        {
            sfi(ai[i]);
            freq[ai[i]]++;
            ans[i] = ai[i];
            bi[i] = ai[i];
        }


        if(n<=8)
        {
            int mxc = 0;

            sort(bi+1,bi+n+1);

            do
            {
                int curc = 0;

                for(int i=1; i<=n; i++)
                {
                    if(ai[i]!=bi[i])
                    {
                        curc++;
                    }
                }

                if(curc>mxc)
                {
                    mxc = curc;

                    for(int i=1; i<=n; i++)
                    {
                        ans[i] = bi[i];
                    }
                }

            }
            while(next_permutation(bi+1,bi+n+1));

            pf("%d\n",mxc);

            for(int i=1; i<=n; i++)
            {
                pf("%d ",ans[i]);
            }
            pf("\n");

            continue;

        }



        for(int i=1; i<=n; i++)
        {
            int x = ai[i];
            if(mark[x]==0)
            {
                if(freq[x]==1)
                {
                    fr1++;
                    f1[fr1].val = x;
                    f1[fr1].idx1 = i;
                }
                else
                {
                    fr2++;
                    f2[fr2].val = x;
                    f2[fr2].idx1 = i;
                    mark[x] = fr2;
                }
            }
            else
            {
                int get_idx = mark[x];
                f2[get_idx].idx2 = i;
            }
        }


        if((fr1>=2 || fr1==0) && (fr2>=2 || fr2==0))
        {
            if(fr1%2)
            {

                ans[ f1[1].idx1 ] = f1[3].val;
                ans[ f1[2].idx1 ] = f1[1].val;
                ans[ f1[3].idx1 ] = f1[2].val;

                for(int k=4; k<=fr1; k+=2)
                {
                    ans[ f1[k].idx1 ] = f1[k+1].val;
                    ans[ f1[k+1].idx1 ] = f1[k].val;
                }
            }
            else
            {
                for(int k=1; k<=fr1; k+=2)
                {
                    ans[ f1[k].idx1 ] = f1[k+1].val;
                    ans[ f1[k+1].idx1 ] = f1[k].val;
                }
            }


            if(fr2%2)
            {

                ans[ f2[1].idx1 ] = f2[3].val;
                ans[ f2[2].idx1 ] = f2[1].val;
                ans[ f2[3].idx1 ] = f2[2].val;

                ans[ f2[1].idx2 ] = f2[3].val;
                ans[ f2[2].idx2 ] = f2[1].val;
                ans[ f2[3].idx2 ] = f2[2].val;

                for(int k=4; k<=fr2; k+=2)
                {
                    ans[ f2[k].idx1 ] = f2[k+1].val;
                    ans[ f2[k+1].idx1 ] = f2[k].val;

                    ans[ f2[k].idx2 ] = f2[k+1].val;
                    ans[ f2[k+1].idx2 ] = f2[k].val;
                }
            }
            else
            {
                for(int k=1; k<=fr2; k+=2)
                {
                    ans[ f2[k].idx1 ] = f2[k+1].val;
                    ans[ f2[k+1].idx1 ] = f2[k].val;

                    ans[ f2[k].idx2 ] = f2[k+1].val;
                    ans[ f2[k+1].idx2 ] = f2[k].val;
                }
            }
        }
        else if(fr1==1 && fr2>=2)
        {
            if(fr2==2)
            {
                ans[ f1[1].idx1 ] = f2[1].val;
                ans[ f2[1].idx1 ] = f2[2].val;
                ans[ f2[1].idx2 ] = f2[2].val;
                ans[ f2[2].idx1 ] = f1[1].val;
                ans[ f2[2].idx2 ] = f2[1].val;
            }
            else if(fr2==3)
            {
                ans[ f1[1].idx1 ] = f2[1].val;
                ans[ f2[1].idx1 ] = f2[2].val;
                ans[ f2[1].idx2 ] = f2[3].val;
                ans[ f2[2].idx1 ] = f1[1].val;
                ans[ f2[2].idx2 ] = f2[3].val;
                ans[ f2[3].idx1 ] = f2[2].val;
                ans[ f2[3].idx2 ] = f2[1].val;
            }
            else
            {
                ans[ f1[1].idx1 ] = f2[1].val;
                ans[ f2[1].idx1 ] = f2[2].val;
                ans[ f2[1].idx2 ] = f2[2].val;
                ans[ f2[2].idx1 ] = f1[1].val;
                ans[ f2[2].idx2 ] = f2[1].val;
                if(fr2%2)
                {
                    ans[ f2[3].idx1 ] = f2[5].val;
                    ans[ f2[4].idx1 ] = f2[3].val;
                    ans[ f2[5].idx1 ] = f2[4].val;

                    ans[ f2[3].idx2 ] = f2[5].val;
                    ans[ f2[4].idx2 ] = f2[3].val;
                    ans[ f2[5].idx2 ] = f2[4].val;
                    for(int k=6; k<=fr2; k+=2)
                    {
                        ans[ f2[k].idx1 ] = f2[k+1].val;
                        ans[ f2[k+1].idx1 ] = f2[k].val;

                        ans[ f2[k].idx2 ] = f2[k+1].val;
                        ans[ f2[k+1].idx2 ] = f2[k].val;
                    }
                }
                else
                {
                    for(int k=3; k<=fr2; k+=2)
                    {
                        ans[ f2[k].idx1 ] = f2[k+1].val;
                        ans[ f2[k+1].idx1 ] = f2[k].val;

                        ans[ f2[k].idx2 ] = f2[k+1].val;
                        ans[ f2[k+1].idx2 ] = f2[k].val;
                    }

                }
            }
        }
        else if(fr2==1 && fr1>=2)
        {
            if(fr1==2)
            {
                ans[ f1[1].idx1 ] = f2[1].val;
                ans[ f1[2].idx1 ] = f2[1].val;
                ans[ f2[1].idx1 ] = f1[1].val;
                ans[ f2[1].idx2 ] = f1[2].val;
            }
            else if(fr1==3)
            {
                ans[ f1[1].idx1 ] = f1[2].val;
                ans[ f1[2].idx1 ] = f2[1].val;
                ans[ f1[3].idx1 ] = f2[1].val;
                ans[ f2[1].idx1 ] = f1[1].val;
                ans[ f2[1].idx2 ] = f1[3].val;

            }
            else
            {
                ans[ f1[1].idx1 ] = f2[1].val;
                ans[ f1[2].idx1 ] = f2[1].val;
                ans[ f2[1].idx1 ] = f1[1].val;
                ans[ f2[1].idx2 ] = f1[2].val;
                if(fr1%2)
                {
                    ans[ f1[3].idx1 ] = f1[5].val;
                    ans[ f1[4].idx1 ] = f1[3].val;
                    ans[ f1[5].idx1 ] = f1[4].val;
                    for(int k=6; k<=fr1; k+=2)
                    {
                        ans[ f1[k].idx1 ] = f1[k+1].val;
                        ans[ f1[k+1].idx1 ] = f1[k].val;
                    }
                }
                else
                {
                    for(int k=3; k<=fr1; k+=2)
                    {
                        ans[ f1[k].idx1 ] = f1[k+1].val;
                        ans[ f1[k+1].idx1 ] = f1[k].val;
                    }
                }

            }


        }




        if(fr1==1 && fr2==1)
        {
            pf("2\n");
            pf("%d %d %d\n",ai[2],ai[1],ai[3]);
        }
        else if(fr1==1 && fr2==0)
        {
            pf("0\n");
            pf("%d\n",ai[1]);
        }
        else if(fr1==0 && fr2==1)
        {
            pf("0\n");
            pf("%d %d\n",ai[2],ai[1]);
        }
        else
        {
            pf("%d\n",n);

            for(int i=1; i<=n; i++)
            {
                pf("%d ",ans[i]);
            }
            pf("\n");
        }












    }

    return 0;
}
