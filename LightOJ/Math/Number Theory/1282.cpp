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
ll last3(ll a, ll p)
{
    if(p==0)
        return 1;
    if(p%2)
    {
        ll ap1 = last3(a,p/2)%1000;
        ap1 = (ap1*(a%1000)*ap1)%1000;
        return ap1;
    }
    else
    {
        ll ap1 = last3(a,p/2)%1000;
        ap1 = (ap1*ap1)%1000;
        return ap1;
    }
}
//Only kept 10 leading digits, more than that
//caused overflow (weird)
double up3(double a,ll p)
{
    if(p==0)
        return 1.00;
    if(p%2)
    {
        double ap1 = up3(a,p/2);
        int p10 = log10(ap1);
        while(ap1>(1e10/(ap1*a)))
        {
            ap1/=10;
        }
        return ap1*ap1*a;
    }
    else
    {
        double ap1 = up3(a,p/2);
        int p10 = log10(ap1);
        while(ap1>(1e10/ap1))
        {
            ap1/=10;
        }
        return ap1*ap1;

    }

}
int main()
{
    //write();
    int tc,cas=0;
    sfi(tc);

    while(tc--)
    {
        ll a,b;
        sfll(a,b);
        ll last3ans = last3(a,b);
        double up3ans = up3((double)a,b);
        ll upa = up3ans;
        while(upa>999)
        {
            upa/=10;
        }
        CASE(cas);
        //This part is important
        //Remember if there's a mod operation
        //and you are asked to print some digits
    
        if(last3ans>100)
        pf("%lld %lld\n",upa,last3ans);
        else if(last3ans>10)
        pf("%lld 0%lld\n",upa,last3ans);
        else if(last3ans>=0)
        pf("%lld 00%lld\n",upa,last3ans);


    }
    return 0;
}
