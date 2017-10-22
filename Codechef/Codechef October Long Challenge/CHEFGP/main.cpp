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
string s;
int lim;
int main()
{
    int tc;
    sfi(tc);

    while(tc--)
    {
        cin>>s;
        int x,y;
        sfii(x,y);

        int p = 0, q = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='a')
                p++;
            else
                q++;

        }

        if(p>q)
        {
            int xp,yp;

            while(p>0 && q>0)
            {

                int m = p-q;
                if(m==0)
                {
                    xp = yp = min({x,y,p,q});
                }
                else if(m>0)
                {
                    yp = 1;
                    xp = min({yp+m,x,p});
                }
                else
                {
                    xp = 1;
                    yp = min({xp-m,y,q});
                }

                for(int i=1; i<=xp; i++)
                    cout<<'a';
                for(int i=1; i<=yp; i++)
                    cout<<'b';

                p -= xp;
                q -= yp;



            }

            if(p>0)
            {
                if(p<=x)
                {
                    for(int i=1; i<=p; i++)
                        cout<<'a';
                    p = 0;
                }
                else
                {
                    lim = p/x;
                    for(int i=1; i<lim; i++)
                    {
                        for(int j=1; j<=x; j++)
                            cout<<'a';
                        cout<<'*';
                        p -= x;
                    }

                    for(int i=1; i<=x; i++)
                        cout<<'a';
                    p-=x;

                    if(p!=0)
                    {
                        cout<<'*';
                        for(int j=1; j<=p; j++)
                        {
                            cout<<'a';
                        }
                    }

                }

            }

            if(q>0)
            {
                int extb = min({q,y-yp});

                for(int i=1; i<=extb; i++)
                    cout<<'b';

                q-=extb;
            }

            if(q>0)
            {
                cout<<'*';

                if(q<=y)
                {
                    for(int i=1; i<=q; i++)
                        cout<<'b';
                    q = 0;
                }
                else
                {
                    for(int i=1; i<(q/y); i++)
                    {
                        for(int j=1; j<=y; j++)
                            cout<<'b';
                        cout<<'*';
                        q -= y;
                    }

                    for(int i=1; i<=y; i++)
                        cout<<'b';
                    q-=y;

                    if(q!=0)
                    {
                        cout<<'*';
                        for(int j=1; j<=q; j++)
                        {
                            cout<<'b';
                        }
                    }

                }



            }

        }
        else
        {
            int xp,yp;
            while(p>0 && q>0)
            {

                int m = p-q;
                if(m==0)
                {
                    xp = yp = min({x,y,p,q});
                }
                else if(m>0)
                {
                    yp = 1;
                    xp = min({yp+m,x,p});
                }
                else
                {
                    xp = 1;
                    yp = min({xp-m,y,q});
                }


                for(int i=1; i<=yp; i++)
                    cout<<'b';
                for(int i=1; i<=xp; i++)
                    cout<<'a';

                p -= xp;
                q -= yp;



            }

            if(p>0)
            {
                int extb = min({p,x-xp});

                for(int i=1; i<=extb; i++)
                    cout<<'a';

                p-=extb;
            }

            if(p>0)
            {
                cout<<'*';
                if(p<=x)
                {
                    for(int i=1; i<=p; i++)
                        cout<<'a';
                    p = 0;
                }
                else
                {
                    for(int i=1; i<(p/x); i++)
                    {
                        for(int j=1; j<=x; j++)
                            cout<<'a';
                        cout<<'*';
                        p -= x;
                    }

                    for(int i=1; i<=x; i++)
                        cout<<'a';
                    p-=x;

                    if(p!=0)
                    {
                        cout<<'*';
                        for(int j=1; j<=p; j++)
                        {
                            cout<<'a';
                        }
                    }

                }

            }

            if(q>0)
            {
                if(q<=y)
                {
                    for(int i=1; i<=q; i++)
                        cout<<'b';
                    q = 0;
                }
                else
                {
                    lim = (q/y);
                    for(int i=1; i<lim; i++)
                    {
                        for(int j=1; j<=y; j++)
                            cout<<'b';
                        cout<<'*';
                        q -= y;
                    }

                    for(int i=1; i<=y; i++)
                        cout<<'b';
                    q-=y;

                    if(q!=0)
                    {
                        cout<<'*';
                        for(int j=1; j<=q; j++)
                        {
                            cout<<'b';
                        }
                    }

                }



            }


        }
        cout<<endl;

    }

    return 0;
}
