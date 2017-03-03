

/****************************************
              Zerus97
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
    string ss;
    cin>>ss;
    int len = ss.length();

    if(len==1)
    {
        if((ss[0]-'0')%8==0)
        {
            cout<<"YES"<<endl;
            cout<<ss<<endl;
            return 0;
        }

    }
    else if(len==2)
    {
        int pos1 =

            (ss[0]-'0')*10 +
            (ss[1]-'0');

        if(pos1%8==0)
        {
            cout<<"YES"<<endl;
            cout<<pos1<<endl;
            return 0;
        }

        int pos2 =

            (ss[0]-'0');
        if(pos2%8==0)
        {
            cout<<"YES"<<endl;
            cout<<pos2<<endl;
            return 0;
        }

        int pos3 =

            (ss[1]-'0');
        if(pos3%8==0)
        {
            cout<<"YES"<<endl;
            cout<<pos3<<endl;
            return 0;
        }




    }
    else if(len>=3)
    {
        loop(lv1,0,len-1)
        {
            loop(lv2,lv1+1,len-1)
            {
                loop(lv3,lv2+1,len-1)
                {

                    int pos1 =
                        (ss[lv1]-'0')*100 +
                        (ss[lv2]-'0')*10 +
                        (ss[lv3]-'0');

                    if(pos1%8==0)
                    {
                        cout<<"YES"<<endl;
                        cout<<pos1<<endl;
                        return 0;
                    }

                    int pos2 =

                        (ss[lv1]-'0')*10 +
                        (ss[lv2]-'0');

                    if(pos2%8==0)
                    {
                        cout<<"YES"<<endl;
                        cout<<pos2<<endl;
                        return 0;
                    }
                    int pos3 =

                        (ss[lv2]-'0')*10 +
                        (ss[lv3]-'0');

                    if(pos3%8==0)
                    {
                        cout<<"YES"<<endl;
                        cout<<pos3<<endl;
                        return 0;
                    }
                    int pos4 =

                        (ss[lv1]-'0')*10 +
                        (ss[lv3]-'0');
                    if(pos4%8==0)
                    {
                        cout<<"YES"<<endl;
                        cout<<pos4<<endl;
                        return 0;
                    }

                    int pos5 =

                        (ss[lv1]-'0');
                    if(pos5%8==0)
                    {
                        cout<<"YES"<<endl;
                        cout<<pos5<<endl;
                        return 0;
                    }
                    int pos6 =

                        (ss[lv2]-'0');
                    if(pos6%8==0)
                    {
                        cout<<"YES"<<endl;
                        cout<<pos6<<endl;
                        return 0;
                    }
                    int pos7 =

                        (ss[lv3]-'0');
                    if(pos7%8==0)
                    {
                        cout<<"YES"<<endl;
                        cout<<pos7<<endl;
                        return 0;
                    }

                }
            }


        }

    }

    cout<<"NO"<<endl;
    return 0;
}
