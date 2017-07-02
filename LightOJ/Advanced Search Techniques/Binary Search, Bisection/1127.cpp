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

#define INF 100000000000000   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

#define CONTEST 1

using namespace std;
ll lsi1[32800];
ll lsi2[32800];
ll mip1[17];
ll mip2[34];
int n;
ll w;
int idx1;
void gen1(int pos,ll sum)
{
    if(pos==n/2+1)
    {
        idx1++;
        lsi1[idx1] = sum;
        return;
    }
    gen1(pos+1,sum);
    gen1(pos+1,sum+mip1[pos]);


}
int idx2;
void gen2(int pos,ll sum)
{
    if(pos==n+1)
    {
        idx2++;
        lsi2[idx2] = sum;
        return;
    }
    gen2(pos+1,sum);
    gen2(pos+1,sum+mip2[pos]);

}
int bs(ll p)
{
    int lo = 1, hi = idx1;

    if(p<0)
        return 0;

    while(lo<=hi)
    {
        int mid = (lo+hi)/2;

        if(lsi1[mid]<=p && lsi1[mid+1]>p)
            return mid;
        else if(lsi1[mid]<=p)
            lo = mid+1;
        else
            hi = mid-1;

    }


}
int main()
{
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {

        sfi(n);sfl(w);

        for(int i=1; i<=n/2; i++)
        {
            ll tmp;
            sfl(tmp);
            mip1[i] = tmp;


        }

        for(int i=n/2+1; i<=n; i++)
        {
            ll tmp;
            sfl(tmp);
            mip2[i] = tmp;
        }

        idx1 = 0;
        gen1(1,0);
        idx2 = 0;
        gen2(n/2+1,0);



        sort(lsi1+1,lsi1+idx1+1);
        int ans = 0;
        lsi1[idx1+1] = INF;
        for(int i=1; i<=idx2; i++)
        {
            ans+=bs(w-lsi2[i]);
        }


        CASE(cas);
        pf("%d\n",ans);




    }



    return 0;
}
