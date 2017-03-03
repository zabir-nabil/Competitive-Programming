

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

#define mod 1000007
using namespace std;
//LightWeight Version for SPOJ
deque<int>DQ;
int arr[1000005];
int main()
{
int N;int K;
sfi(N);
for(int a=1;a<=N;a++)sfi(arr[a]);
sfi(K);
int activator = 0;

for(int x = 1;x<=N;x++)
{
    while(!DQ.empty() && (DQ.back()< arr[x]) ){
            DQ.pop_back();
   // cout<<"Back element is smaller so removed ";
    }


    DQ.push_back(arr[x]);//cout<<"Current element is inserted ";

     if( (DQ.size()>K) || (x>K && arr[x-K]==DQ.front() ) ){
        DQ.pop_front();
//cout<<"Removed as big size or irrelevant element in list  ";
     }

//for(int m = 0;m<DQ.size();m++)cout<<DQ[m]<<" ";cout<<endl;
   // if(x==K)activator = 1;

    if(x>=K)cout<<DQ.front()<<" ";
}
cout<<endl;



    return 0;
}
