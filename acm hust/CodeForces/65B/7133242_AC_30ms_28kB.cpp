
/****************************************
              Zerus97
*****************************************/

#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<=e;i++) //including end point

#define pb(a) push_back(a)

#define sqr(x) ((x)*(x))

#define CIN ios_base::sync_with_stdio(0); cin.tie(0);

#define ull long long

#define ll unsigned long long

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
string ar[1009];
 int n;
 int toi(string s)
 {
     int asn = 0;
     int po = 1000;
     loop(x,0,3)
     {
         asn+=po*(s[x]-'0');
         po/=10;
     }
     return asn;
 }
 string con(int n)
 {
     string ss;
     int xa = 0;
     while(n>0)
     {
         int dg = n%10;
         ss.pb((char)(dg+'0'));
         n/=10;
     }
     reverse(all(ss));
     return ss;
 }
int mxi(string ss,int id)
{
    vector<int>asss;
    string scop = ss;
    loop(pos,0,3)
    {
        //cout<<pos<<" now "<<endl;
        string stm  = ss;
        for(int d = 9;d>=0;d--)
        {
            stm[pos] = (char)('0'+d);
            //cout<<stm<<endl;
            if(id==n){
            if(toi(stm)>=1000 && toi(stm)<=2011)
            {
                //ar[id] = stm;
                asss.pb(toi(stm));
                //return 1;
            }
            }
            else
            {
                if(toi(stm)>=1000 && toi(stm)<=2011
                   && toi(stm)<=toi(ar[id+1]) )
            {
                //ar[id] = stm;
                asss.pb(toi(stm));
                //return 1;
            }
            }

        }
    }
    if(SZ(asss)==0)
    return -1;

    int mx = 0;

    loop(x,0,SZ(asss)-1)
    mx = max(mx,asss[x]);

    ar[id] = con(mx);
}

int main()
{
  //cout<<con(1570)<<endl;


    cin>>n;
    loop(i,1,n)
    {
        cin>>ar[i];
    }
    int ans = 1;
    for(int x = n;x>=1;x--)
    {
        int as = mxi(ar[x],x);
        if(as==-1)
        {
            ans = 0;
            break;
        }

    }

    if(ans==0)
    {
        cout<<"No solution"<<endl;
    }
    else
    {
        loop(x,1,n)
        cout<<ar[x]<<endl;


    }



    return 0;
}
