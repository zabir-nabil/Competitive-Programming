
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
int arr[55];
int carr[55];
int main()
{
    int tc,cas =0 ;
    sfi(tc);
    while(tc--)
    {
        int n;
        sfi(n);

        int sum = 0;
        loop(i,1,n)
        {
            sfi(arr[i]);
            carr[i]=arr[i];
            sum+=arr[i];
        }

        int ps1 = (n*(n-1))/2;
        int ps2 = (n*(n+1))/2;
        int ans = INF;
        //int lef = sum - ps1;
        if( (sum-ps1)%n==0 )
        {
            int kas = 0;
            int lef = (sum-ps1)/n;
            //cout<<lef<<endl;

            loop(p,1,51)
            {

                loop(x,1,n)
                {
                    loop(y,x+1,n)
                    {
                        /*                      if(arr[x]>=arr[y])
                                              {
                                                  arr[x]--;
                                                  arr[y]++;
                                                  ans++;
                                              }
                        */
                        if(arr[x]<(x-1+lef) && arr[y]>(y-1+lef) )
                        {
                            arr[x]++;
                            arr[y]--;
                            kas++;
                        }
                        else if(arr[x]>(x-1+lef) && arr[y]<(y-1+lef) )
                        {
                            arr[x]--;
                            arr[y]++;
                            kas++;
                        }

                    }
                }

            }

            ans = min(kas,ans);
        }
        int ans2 = INF;
        if((sum-ps2)%n==0)
        {
            int lol = 0;

            int lef = (sum-ps2)/n;

            loop(p,1,51)
            {

                loop(x,1,n)
                {
                    loop(y,x+1,n)
                    {
                        if(carr[x]<(x+lef) && carr[y]>(y+lef) )
                        {
                            carr[x]++;
                            carr[y]--;
                            lol++;
                        }
                        else if(carr[x]>(x+lef) && carr[y]<(y+lef) )
                        {
                            carr[x]--;
                            carr[y]++;
                            lol++;
                        }

                    }
                }

            }

            ans2 = min(ans2,lol);
        }


        if((sum-ps1)%n!=0 && (sum-ps2)%n!=0)
        {
            pf("-1\n");
            continue;
        }
        ans = min(ans,ans2);
        pf("%d\n",ans);
    }

    return 0;
}
