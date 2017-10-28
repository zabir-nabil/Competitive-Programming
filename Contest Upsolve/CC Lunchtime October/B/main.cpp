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
char num[100005];
string cnum;
bool odd(char c)
{
    if(c=='1'
            || c=='3'
            || c=='5'
            || c=='7'
            || c=='9')
        return true;
    return false;
}
int nl;
struct aha
{
    int idx,val;
    aha(int i,int v)
    {
        idx = i;
        val = v;
    }
};
vector<aha>mnv;
bool cp(aha a1,aha a2)
{
    return a1.val<a2.val;
}
void special()
{
    int sum =0;
    for(int i=0; i<strlen(num); i++)
    {
        sum+=(num[i]-'0');
    }

    int n = strlen(num);
    if(odd(num[n-1]))
    {
        int pa = sum-(num[n-1]-'0');
        if(pa%3==0 && !odd(num[n-2]))
        {
            for(int i=0; i<n-1; i++)
                pf("%c",num[i]);

            pf("\n");
        }
        else
        {
            pf("-1\n");
        }
        return;
    }


    int ans = -1;
    cnum.clear();
    for(int i=1; i<n; i++)
    {
        cnum.pb('.');
    }

    int sidx = 0;
    for(int i=0; i<nl-1; i++)
    {
        sidx = 0;
        int gar = sum-(num[i]-'0');
        if(gar%3==0)
            for(int p=0; p<n; p++)
            {
                if(p!=i)
                {
                    if(num[p]>cnum[sidx])
                    {
                        ans = i;
                        cnum.clear();
                        for(int j=0; j<i; j++)
                        {
                            cnum.pb(num[j]);
                        }
                        for(int j=i+1; j<n; j++)
                        {
                            cnum.pb(num[j]);
                        }
                        break;
                    }
                    sidx++;
                }
            }


    }

    sidx = 0;

    int kala = sum - (num[n-1]-'0');
    if(!odd(num[n-2]) && (kala%3==0))
    {
        for(int p=0; p<n; p++)
        {
            if(p!=n-1)
            {
                if(num[p]>cnum[sidx])
                {
                    ans = n-1;
                    cnum.clear();
                    for(int j=0; j<n-1; j++)
                    {
                        cnum.pb(num[j]);
                    }

                    break;
                }
                sidx++;
            }
        }


    }

    if(ans!=-1)
    {
        for(int i=0; i<n; i++)
        {
            if(i!=ans)
            {
                pf("%c",num[i]);
            }
        }

        pf("\n");
    }
    else
    {
        pf("-1\n");
    }



}
int main()
{
    //cout<<('.'<'0')<<endl;


    int tc;
    sfi(tc);
    while(tc--)
    {
        sfs(num);
        nl = strlen(num);



        int sum =0;
        for(int i=0; i<strlen(num); i++)
        {
            sum+=(num[i]-'0');
        }

        int n = strlen(num);
        if(odd(num[n-1]))
        {
            int pa = sum-(num[n-1]-'0');
            if(pa%3==0 && !odd(num[n-2]))
            {
                for(int i=0; i<n-1; i++)
                    pf("%c",num[i]);

                pf("\n");
            }
            else
            {
                pf("-1\n");
            }
        }
        else

        {
            bool ans = false;

            for(int i=0; i<n-1; i++)
            {
                int ca = sum-(num[i]-'0');
                int d1 = num[i]-'0';
                int d2 = num[i+1]-'0';
                if(ca%3==0 && (d1<d2))
                {
                    ans = true;
                    for(int j=0; j<i; j++)
                    {
                        pf("%c",num[j]);

                    }
                    for(int j=i+1; j<n; j++)
                    {
                        pf("%c",num[j]);

                    }

                    pf("\n");
                    break;

                }
            }



            if(!ans)
            {
                int midx = 0;
                int mndg = INF;


                for(int i=0; i<n; i++)
                {
                    int ca = sum-(num[i]-'0');
                    int d1 = num[i]-'0';

                    if(ca%3==0)
                    {
                        aha a1(i,d1);
                        mnv.pb(a1);
                    }
                }

                sort(mnv.begin(),mnv.end(),cp);

                if(mnv.size()==0)
                {
                    pf("-1\n");
                    ans = true;
                }
                midx = INF;
                if(!ans && mnv.size()>0)
                    midx = mnv[0].idx;

                if(!ans && midx==n-1)
                {
                    int pa = sum-(num[n-1]-'0');
                    if(pa%3==0 && !odd(num[n-2]))
                    {
                        ans = true;
                        for(int i=0; i<n-1; i++)
                            pf("%c",num[i]);

                        pf("\n");
                    }
                    else
                    {
                        if(mnv.size()>1)
                        {
                            int ii = mnv[1].idx;

                            ans = true;
                            for(int j=0; j<ii; j++)
                            {
                                pf("%c",num[j]);

                            }
                            for(int j=ii+1; j<n; j++)
                            {
                                pf("%c",num[j]);

                            }

                            pf("\n");

                        }





                    }


                }
                else
                {
                    if(mnv.size()>0)
                    {
                        int ii = mnv[0].idx;

                        ans = true;
                        for(int j=0; j<ii; j++)
                        {
                            pf("%c",num[j]);

                        }
                        for(int j=ii+1; j<n; j++)
                        {
                            pf("%c",num[j]);

                        }

                        pf("\n");


                    }

                }


            }




            if(!ans)
            {
                pf("-1\n");
            }

        }



        mnv.clear();

    }

    return 0;
}
