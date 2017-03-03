

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
vector<int>digit;
int main()
{

    ll N;
    sfl(N);
    ll N_c = N;
    while(N_c>0)
    {
        int dg = N_c%10;
        digit.pb(dg);
        N_c/=10;
    }
    int ans = 1;
    loop(x,0,digit.size()-1)
    {
        int curd = digit[x];
        if(curd!=1 && curd!=4)
        {
           // cout<<"++"<<endl;
            ans = 0;
            break;
        }
    }
if(digit.size()>=3)
    for(int i = 0;i<=digit.size()-3;i++)
    {
        int cd = digit[i];
        if(cd==4)
        {
            if(digit[i+1]!=1 && digit[i+2]!=1)
            {
               // cout<<"--"<<endl;
                ans = 0;
                break;
            }


        }

    }
//cout<<"da"<<endl;
    if(digit.size()>=2)
    {

        if(digit[digit.size() - 2]==4 && digit[digit.size() - 1]!=1)
        {
            //cout<<"**"<<endl;
            ans = 0;
        }
    }
    if(digit[digit.size()-1]==4){
            //cout<<"**--"<<endl;

        ans = 0;

    }

    if(ans)
        cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    //digit.clear();



    return 0;
}
