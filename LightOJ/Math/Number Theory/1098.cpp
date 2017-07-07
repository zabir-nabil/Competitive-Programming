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
	//SOD has a closed formula from prime factorization. But, I don't know any for CSOD.
	//Lets see how many times 2<=i<=sqrt(n) appears in CSOD(n). It looks, it appears n/i -1 which_open_mode
	//is obvious as we are only counting proper divisors. But what about numbers that are greater than sq;
	//Example, n = 10, 2->4 and 3->2. There's a way to find out how many times 4,5 appears from only
	//this info. and the formula is (after some trials) -> (i-1)*SUM_OF(n/(i)-1+1 to n/(i+1)+1)
	//There are some corner cases where overcounting can be an issue.
    ll n;
    ll cums(ll st,ll en)
    {
     
        ll ret = (en*(en+1))/2 - (st*(st-1))/2;
        return ret;
    }
    int main()
    {
        //write();
        int tc,cas=0;
        sfi(tc);
        while(tc--)
        {
     
            sfl(n);
            ll ans = 0;
            ll sq = sqrt(n+0.1);
            for(ll i=2;i<=sq;i++)
            {
                ll curb = ((n/i -1));
                ans+=i*curb;
                ll lastb = n/(i+1);
                ll prt = (i-1)*cums(lastb+1,curb+1);
                if(lastb+1>sq)
                 ans+=prt;
     
     
     
            }
     
            CASE(cas);
            pf("%lld\n",ans);
     
     
        }
     
     
     
        return 0;
    }
     
