

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

#define CASE(t) printf("Case %d\n",++t) // t initialized 0

#define INF 1000000000   //10e9

#define EPS 1e-9


using namespace std;
string str;
stack<char>graph;
int cnt[35];
int main()
{

    int sl, tc;
    int t = 0;int i;

    sfi(tc);
    while(tc--)
    {

        cin>>str;

        int ln = str.length();ln--;

        graph.push(str[0]);


        for(int i=1;i<ln;i++)
        {
            char node= graph.top();
            if(node==str[i])
            {
                cnt[node-'A']++;
                graph.pop();
                node = graph.top();
                cnt[node-'A']++;
            }
            else
                graph.push(str[i]);
        }
        CASE(t);
        loop(i,0,26)
            if(cnt[i]!=0)

                pf("%c = %d\n",char(i+'A'),cnt[i]);
                ms(cnt,0);
    }

    return 0;
}
