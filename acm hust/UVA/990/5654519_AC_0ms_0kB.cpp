

/****************************************

Cat Got Bored

*****************************************/

#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<e;i++) //excluding end point

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

int cost[32];
int weight[32];
int dep[32];
int dp[32][1009];
short dir[32][1009];
int CAP;
int n;
int rec(int i,int w)
{
	if(i==n+1) return 0; //Every object has been assumed
	if(dp[i][w]!=-1) return dp[i][w]; //previosuly calculated state
	int profit1=0,profit2=0;

	  if(w+weight[i]<=CAP)
         profit1=cost[i]+rec(i+1,w+weight[i]);
     else
         profit1=0;
     profit2=rec(i+1,w);
     if(profit1>profit2){dir[i][w]=1; return dp[i][w]=profit1;}
     else {dir[i][w]=2; return dp[i][w]=profit2;}
}
vector<int>sol_set;
int main()
{
int line = 0;
int t,w;
while(cin>>t>>w)
    {

cin>>n;
int i;
loop(i,1,n+1)
{
    int di,vi;
    cin>>di>>vi;
    weight[i]  = 3*w*di;
    dep[i] = di;
    cost[i] = vi;

}


ms(dp,-1);ms(dir,-1);
CAP = t;
int ans = rec(1,0);
//cout<<"----------------------"<<endl;
if(line!=0)cout<<endl;
line++;
cout<<ans<<endl;
int w_ = 0;
for(int x = 1;x<=n;x++)
{
    if(dir[x][w_] == 1 )
    {
        sol_set.pb(x);
        w_+=weight[x];
    }
    else if(dir[x][w_] == -1)
    {
        break;
    }
}
cout<<sol_set.size()<<endl;
for(int a=0;a<sol_set.size();a++)
{
    int pos = sol_set[a];
  //  cout<<pos<<endl;
    cout<<dep[pos]<<" "<<cost[pos]<<endl;
}
sol_set.clear();
//cout<<"----------------------"<<endl;
    }
    return 0;
}
