
//#include <bits/stdc++.h>

#include <iostream>

#include <cstdio>

#include <algorithm>

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

#define INF 1000000000  //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

#define CONTEST 1
using namespace std;
int mxi[15];
int mni[15];
int main()
{
    int n,n1,n2;
    while(scanf("%d %d %d",&n1,&n2,&n)==3)
    {
        if(n+n1+n2==0)
            break;


        double sum = 0.00,summx=0.00,summn=0.00;
        for(int i=0; i<n; i++)
        {
            int tmp;
            sfi(tmp);
            sum+=tmp;

            if(i<n1)
                mxi[i] = tmp;
            else
            {
                sort(mxi,mxi+n1);
                for(int xx=0; xx<n1; xx++)
                {
                    if(mxi[xx]<=tmp)
                    {
                        mxi[xx]=tmp;
                        break;
                    }
                }
            }
            if(i<n2)
                mni[i] = tmp;
            else
            {
                sort(mni,mni+n2);
                for(int xx=n2-1; xx>=0; xx--)
                {
                    if(mni[xx]>=tmp)
                    {
                        mni[xx]=tmp;
                        break;
                    }
                }
            }


        }

        for(int i=0; i<n1; i++)
            summx+=mxi[i];
        for(int i=0; i<n2; i++)
            summn+=mni[i];
        sum-=(summx+summn);
        sum/=(n*1.00-n1*1.00-n2*1.00)*1.00;
        //cout<<sum<<" "<<summx<<" "<<summn<<endl;
        printf("%.6f\n",sum);
    }

    return 0;
}
