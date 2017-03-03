

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

#define CASE(t) printf("Case %d:\n",++t) // t initialized 0

#define INF 1000000000   //10e9

#define EPS 1e-9


using namespace std;
string str;
stack<char>graph;
int cnt[35];
struct player
{
    string name;
    int attack;
    int deffence;
    bool operator<(const player pp) const
    {
        if((attack > pp.attack) || (attack == pp.attack && deffence < pp.deffence) )
        return true;

               if(attack == pp.attack && deffence == pp.deffence && name<pp.name)
                return true;

                return false;
    }

} ppl[20];
bool comp1(player p1,player p2)
{
    return true;

}
bool comp2(const player ptt, const player pcc)
{
    if( ptt.name < pcc.name)
        return true;
    return false;
}
int main(void)
{
    int t;
    sfi(t);
    int tc = 0;
    while(t--)
    {
        for (int i = 0; i < 10; i++)

            cin>>ppl[i].name>>ppl[i].attack>>ppl[i].deffence;

        sort(ppl, ppl + 10);
        sort(ppl, ppl + 5, comp2);
        sort(ppl + 5, ppl + 10, comp2);
        CASE(tc);
        cout<<"(";
        int a;
        for(a=0;a<4;a++)
            cout<<ppl[a].name<<", ";
            cout<<ppl[a].name<<")\n";
cout<<"(";
                  for(a=5;a<9;a++)
            cout<<ppl[a].name<<", ";
            cout<<ppl[a].name<<")\n";



    }
    return 0;
}
