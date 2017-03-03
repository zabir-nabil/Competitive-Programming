

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
vector<int>divis;
int main()
{
int tt;
cin>>tt;
while(tt--)
{
    int N;
    cin>>N;
    int NNN = N;
    int out_iter = 0;
    int in_iter = 0;
    int ans = 0;
    //cout<<"Out:";
    if(N==1)
    {
        cout<<"1\n";
        continue;
    }
     if(N==0)
    {
        cout<<"0\n";
        continue;
    }
    divis.clear();
    while(NNN>1)
    {
        out_iter++;

        for(int diiv = 9 ;diiv >=2;diiv--)
        {
            if(NNN%diiv == 0)
            {
                in_iter++;
                divis.pb(diiv);
                NNN/=diiv;
                break;
            }
        }

        if(NNN == N)
        {
            ans = -1;
            break;
        }

        if(out_iter > in_iter + 3)
        {
            ans = -1;
            break;
        }
    }

    if(ans == -1){
        cout<<"-1\n";
        continue;

    }

    sort(divis.begin(),divis.end());
    for(int x = 0;x<divis.size();x++)
        cout<<divis[x];
    cout<<endl;
    divis.clear();

}

    return 0;
}
