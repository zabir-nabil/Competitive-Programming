

/****************************************
              Zerus97
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

#define sful(a) scanf("%llu",&a);

#define sfulul(a,b) scanf("%llu %llu",&a,&b);

#define sful2(a,b) scanf("%llu %llu",&a,&b); // A little different

#define sfc(a) scanf("%c",&a);

#define sfs(a) scanf("%s",a);


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
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1,y1;
    ll gcd = exgcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return gcd;
}
int main()
{
    /*
    int tc,cas= 0;
    sfi(tc);
    while(tc--)
    {

        ll A,B,C,x1,x2,y1,y2;
        sfll(A,B);
        sfl(C);
        sfll(x1,x2);
        sfll(y1,y2);

        ll x,y;
        ll g = exgcd(A,B,x,y);
        CASE(cas);
        if(C%g)
        {
            pf("%lld\n",0);
        }
        else
        {
            cout<<x<<" "<<y<<endl;
            ll kxl = g*(x1 - x)/B;
            kxl--;
            while(true)
            {
                ll xx1 = x + kxl*B/g;
                if(xx1>=x1)
                {
                    break;
                }
                kxl++;
            }
            ll kxh = g*(x2 - x)/B;
            kxh++;
            while(true)
            {
                ll xx2 = x + kxh*B/g;
                if(xx2<=x2)
                {
                    break;
                }
                kxh--;
            }


            ll kyl = g*(y - y1)/A;
            kyl--;
            while(true)
            {
                ll yy1 = y + kyl*A/g;
                if(yy1>=y1)
                {
                    break;
                }
                kyl++;
            }
            ll kyh = g*(y - y2)/A;
            kyh++;
            while(true)
            {
                ll yy2 = y + kyh*A/g;
                if(yy2<=y2)
                {
                    break;
                }
                kyh--;
            }


            cout<<"X: "<<kxl<<" "<<kxh<<endl;
            cout<<"Y: "<<kyl<<" "<<kyh<<endl;



        }



    }

    */

 int tc,cas =0 ;
	sfi(tc);

	while (tc--)
	{
		ull n , c , e ;
		bool isans = false;

		sful2(n,c);

		e = (n * (n + 1)) / 2;

		if (c >= e)
		{
			ull next = n * n;

			if (n % 2 == 0 && c >= next)
			{
				isans = ((c - next) % (n / 2) == 0);
			}
			else
			{
				isans = (((c % e) % n) == 0);
			}
		}

		if(isans)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
	}





    return 0;
}
