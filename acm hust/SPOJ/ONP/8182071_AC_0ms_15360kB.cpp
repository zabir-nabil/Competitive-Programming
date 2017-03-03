
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

int main()
{
    int tc;
    sfi(tc);
    while(tc--)
    {
        string s;
        cin>>s;

        stack<char>stick;
        vector<char>output;

        for(int i=0; i<s.length(); i++)
        {
            char cn = s[i];

            if(cn=='(')
            {
                stick.push(cn);
            }
            else if(cn==')')
            {
                char ct = stick.top();;
                while(ct!='(')
                {
                    stick.pop();
                    output.pb(ct);
                    ct = stick.top();

                }
                stick.pop();
                //last extra (
            }
            else if(cn=='+')
            {
                char ct = stick.top();
                while(ct=='+'
                        || ct=='-'
                        || ct=='*'
                        || ct=='/'
                        || ct=='^')
                {
                    stick.pop();
                    output.pb(ct);
                    ct = stick.top();
                }

                stick.push(cn);

            }
            else if(cn=='-')
            {
                char ct = stick.top();
                while(ct=='-'
                        || ct=='*'
                        || ct=='/'
                        || ct=='^')
                {
                    stick.pop();
                    output.pb(ct);
                    ct = stick.top();
                }

                stick.push(cn);
            }
            else if(cn=='*')
            {
                char ct = stick.top();
                while(ct=='*'
                        || ct=='/'
                        || ct=='^')
                {
                    stick.pop();
                    output.pb(ct);
                    ct = stick.top();
                }

                stick.push(cn);
            }
            else if(cn=='/')
            {
                char ct = stick.top();
                while(ct=='/'
                        || ct=='^')
                {
                    stick.pop();
                    output.pb(ct);
                    ct = stick.top();
                }

                stick.push(cn);
            }
            else if(cn=='^')
            {
                char ct = stick.top();
                while(ct=='^')
                {
                    stick.pop();
                    output.pb(ct);
                    ct = stick.top();
                }

                stick.push(cn);
            }
            else
            {
                output.pb(cn);
            }
        }

        for(int x=0; x<output.size(); x++)
        {
            pf("%c",output[x]);
        }
        pf("\n");

        while(!stick.empty())
        stick.pop();

        output.clear();




    }


    return 0;
}
