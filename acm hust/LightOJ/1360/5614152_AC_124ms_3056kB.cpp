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

struct Ads
{
    int start;
    int enda;
    int cost;
    Ads(int start,int enda,int cost)
    {
        this->start = start;
        this->enda = enda;
        this->cost = cost;
    }
    Ads()
    {

    }


};

bool compare(Ads Ad1,Ads Ad2)
{

    if(Ad1.start != Ad2.start)
        return Ad1.start < Ad2.start ;
    if(Ad1.start == Ad2.start)
    {
        if(Ad1.enda != Ad2.enda)
            return Ad1.enda < Ad2.enda;
        else
            return Ad1.cost > Ad2.cost;
  }

}
vector<Ads>ADQ;

int dp[200099];
int max_end;

int DpBU()
{

   int i;
   int vec_traverser = 0;
   int cc = 0;
   int ans = 0;
   loop(i,0,max_end+5)
   {

       //Traversing vector while I get a lower floor with i
       while(vec_traverser != max_end + 2)
       {
           if(ADQ[ vec_traverser ].start != i)
            break;
           int tmp = dp[i-1] + ADQ[vec_traverser].cost;
           dp[ ADQ[ vec_traverser ].enda ] = max(dp[ ADQ[ vec_traverser ].enda ] , tmp);
           vec_traverser++;


       }

       cc = max(cc,dp[i]);
       dp[i] = cc;
       ans = max(ans,dp[i]);

   }

   return ans;
}


int main()
{
    int T;
    int tc = 0;
    sfi(T);
    while(T--)
    {
        int N;
        sfi(N);
        int lp;
        max_end = 0;
        loop(lp,0,N)
        {
        int A,B,C;
        sfii(A,B);
        sfi(C);
        Ads ad(A+1,A+B,C);
        //ad.start = A;ad.enda = A+B ; ad.cost = C;
        ADQ.pb(ad);
        max_end = max(max_end , A+B );
        }

        sort(ADQ.begin(),ADQ.end(),compare);
        CASE(tc);
        ms(dp,0);

        int ans = DpBU();

        pf("%d\n",ans);
        ADQ.clear();


    }

    return 0;
}
