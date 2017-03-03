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
#define N_m 1027
ll BIT[1030][1030];
ll query(int x1,int y1)
{
    int x,y;
    x=x1;y=y1;
    ll sum = 0;
    while(x>0)
    {
        y=y1;
        while(y>0)
        {
            sum += BIT[x][y];
            y -=(y&-y);
            //cout<<"QUERY "<<x<<" "<<y<<endl;

        }

        x-=(x&-x);


    }

    return sum;


}

void update(int x1,int y1,ll val)
{
    int x,y;
    x=x1;y=y1;
    while(x<=N_m)
    {
        y = y1;
        while(y<=N_m)
        {
            BIT[x][y]+=val;
            y+=(y&-y);
            //cout<<"UPDATE "<<x<<" "<<y<<endl;

        }

        x+=(x&-x);
       // cout<<"X now "<<x<<endl;


    }


}
int main()
{
   // update(1,1,1);
    //cout<<query(3,3)<<endl;

    int tc;
    sfi(tc);
    int cas = 0;
    while(tc--)
    {
        ms(BIT,0);
        int N;
        sfi(N);
        char ss[6] = "as";

        while(strcmp(ss,"END")!=0)
        {
            scanf("%s",ss);
            if(strcmp(ss,"SET")==0)
            {
                int x,y;ll val;
                sfii(x,y);
                sfl(val);
                //arr[x][y]= val;
                int x0 = 2;int y0 = 2;
                x+=2;y+=2;

                ll an1 = query(x,y);
                ll an2 = query(x-1,y);
                ll an3 = query(x,y-1);
                ll an4 = query(x-1,y-1);
                ll art = an1 - an2 - an3 + an4;


                //update(x,y,0);
                update(x,y,- art);
                update(x,y,val);
            }
            else if(strcmp(ss,"SUM")==0)
            {
                ll sum = 0;
                int x1,y1,x2,y2;

                sfii(x1,y1);
                sfii(x2,y2);
                x1+=2;x2+=2;y1+=2;y2+=2;
                ll an1 = query(x2,y2);
                ll an2 = query(x1-1,y2);
                ll an3 = query(x2,y1-1);
                ll an4 = query(x1-1,y1-1);
                sum = an1 - an2 - an3 + an4;
                pf("%lld\n",sum);

            }


        }
        pf("\n");
    }

    return 0;
}
